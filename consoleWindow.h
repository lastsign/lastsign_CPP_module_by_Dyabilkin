#ifndef Window_H
#define Window_H
#include <Windows.h>

class consoleWindow :public window{
	HANDLE hConsole;
	int weight;
	int height;
public:
	consoleWindow(int w, int t);
	void plot(int, int);
	void plot(const Point& p);
	~consoleWindow();
};

#endif // !Window_H
