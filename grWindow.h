#ifndef grWindow_H
#define grWindow_H

#include "Window.h"


class graphicWindow : public window {
	HDC hdcMemDC;
	HBRUSH hBrush;
	int ClientWidth;
	int ClientHeight;
public:
	graphicWindow(HDC hdc, HDC hdcmemdc);
	void plot(int i, int k);
	void plot(const Point& p);
	~graphicWindow();
};


#endif // !grWindow_H
