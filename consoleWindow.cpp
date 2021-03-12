#include "pch.h"
#include "Window.h"
#include "consoleWindow.h"

consoleWindow::consoleWindow(int w, int h)
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	weight = w;
	height = h;
}

void consoleWindow::plot(int w, int h)
{
	if (weight > w && height > h) {
		COORD Pos;
		Pos.X = w;
		Pos.Y = h;
		SetConsoleCursorPosition(hConsole, Pos);
		WriteConsole(hConsole, "*", 1, 0, 0);
	}
}

void consoleWindow::plot(const Point& p)
{
	if (weight > p.x && height > p.y) {
		COORD Pos;
		Pos.X = p.x;
		Pos.Y = p.y;
		SetConsoleCursorPosition(hConsole, Pos);
		WriteConsole(hConsole, "*", 1, 0, 0);
	}
}

consoleWindow::~consoleWindow()
{
	COORD Pos;
	Pos.X = 0;
	Pos.Y = height;
	SetConsoleCursorPosition(hConsole, Pos);
	CloseHandle(hConsole);
}
