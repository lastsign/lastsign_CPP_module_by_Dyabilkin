#ifndef Shape_H
#define Shape_H



using namespace std;

class Shape {
public:
	virtual void draw(window*) = 0;
};

class dot : public Shape {
	Point p;
public:
	dot(Point a) : p(a) { };
	void draw(window* W);
};

class rectangle : public Shape {
	Point p1;
	Point p2;
public:
	rectangle(Point a, Point b) : p1(a), p2(b) { }
	void draw(window* W);
};

class line : public Shape {
	Point p1;
	Point p2;
public:
	line(Point a, Point b) : p1(a), p2(b) { }
	void draw(window* W);
};

class elipce : public Shape {
	Point p1;
	Point p2;
public:
	elipce(Point a, Point b) : p1(a), p2(b) { }
	void draw(window* w);
};
class Triangle : public line {
	Point p1;
	Point p2;
	Point p3;
public:
	Triangle(Point a, Point b, Point c) : p1(a), p2(b), p3(c), line(p1, p2) { }
	void draw(window* W);
};
class Square : public rectangle {
public:
	Square(Point a, int l) : rectangle(a, Point(a.x + l, a.y + l)) { }
};

class Circle : public elipce {
public:
	Circle(Point c, int r) : elipce(Point(c.x - r, c.y - r), Point(c.x + r, c.y + r)) { }
};

#endif // !Shape_H