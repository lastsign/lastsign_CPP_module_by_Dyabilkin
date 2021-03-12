#ifndef window_H
#define window_H

struct Point {
	int x;
	int y;
	Point() { x = 0; y = 0; }
	Point(int X, int Y) {
		x = X;
		y = Y;
	}
};

class window {
public:
	virtual void plot(int, int) = 0;
	virtual void plot(const Point&) = 0;
};
#endif // !window_H
