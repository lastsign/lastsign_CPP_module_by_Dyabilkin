#include "stdafx.h"
#include "grWindow.h"


graphicWindow::graphicWindow(HDC hdc, HDC hdcmemdc) {
	hdcMemDC = hdcmemdc;
	ClientWidth = 899;
	ClientHeight = 599;
	hBrush = CreateSolidBrush(RGB(255, 255, 255));

	//ReleaseDC(hWnd, hdc);

	RECT GrBufferSize = { 0,0,ClientWidth,ClientHeight };
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
	FillRect(hdcMemDC, &GrBufferSize, hBrush);
	DeleteObject(hBrush);

	HPEN hPen, hPenOld;
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	hPenOld = (HPEN)SelectObject(hdcMemDC, hPen);
	for (int i = 19; i < ClientWidth; i += 20) {
		MoveToEx(hdcMemDC, i, 0, NULL);
		LineTo(hdcMemDC, i, ClientHeight);
	}
	for (int i = 19; i < ClientHeight; i += 20) {
		MoveToEx(hdcMemDC, 0, i, NULL);
		LineTo(hdcMemDC, ClientWidth, i);
	}
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}
void graphicWindow::plot(int i, int k) {
	if (ClientWidth >= i * 20 && ClientHeight >= k * 20) {
		RECT cell = { 20 * i, 20 * k, 20 * i + 19, 20 * k + 19 };
		FillRect(hdcMemDC, &cell, hBrush);
	}
}
void graphicWindow::plot(const Point& p) {
	if (ClientWidth >= p.x * 20 && ClientHeight >= p.y * 20) {
		RECT cell = { 20 * p.x,20 * p.y,20 * p.x + 19,20 * p.y + 19 };
		FillRect(hdcMemDC, &cell, hBrush);
	}
}
graphicWindow::~graphicWindow() {
	DeleteObject(hBrush);
}
