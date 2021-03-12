#include "pch.h"
//#include "stdafx.h"
#include <iostream>
#include "Window.h"
#include "Shape.h"

void dot::draw(window* W) {
	W->plot(p.x, p.y);
}
void rectangle::draw(window* W) {
	int t = p1.x;
	int b = p1.y;
	while (t <= p2.x) {
		W->plot(t, p1.y);
		W->plot(t, p2.y);
		t++;
	}
	while (b <= p2.y) {
		W->plot(p1.x, b);
		W->plot(p2.x, b);
		b++;
	}
}

void line::draw(window* W) {
	int xa = p2.x - p1.x;
	int ya = p1.y - p2.y;
	int a1 = 1;
	int a2 = 1;
	int b1 = 1;
	int b2 = 1;
	if (xa > 0) {
		if (ya > 0) {
			if (xa > ya) {
				a1 = 1; a2 = 0; b1 = 0; b2 = 1;
			}
			else {
				a1 = 0; a2 = 1; b1 = 1; b2 = 0; int t = xa; xa = ya; ya = t;
			}
		}
		else {
			if (xa > -ya) {
				a1 = 1; a2 = 0; b1 = 0; b2 = -1; ya = -ya;
			}
			else {
				a1 = 0; a2 = -1; b1 = 1; b2 = 0; int t = xa; xa = -ya; ya = t;
			}
		}
	}
	else {
		if (ya > 0) {
			if (-xa > ya) {
				a1 = -1; a2 = 0; b1 = 0; b2 = 1; xa = -xa;
			}
			else {
				a1 = 0; a2 = 1; b1 = -1; b2 = 0; int t = -xa; xa = ya; ya = t;
			}
		}
		else {
			if (-xa > -ya) {
				a1 = -1; a2 = 0; b1 = 0; b2 = -1; xa = -xa; ya = -ya;
			}
			else {
				a1 = 0; a2 = -1; b1 = -1; b2 = 0; int t = -xa; xa = -ya; ya = t;
			}
		}
	}
	int e = 2 * ya - xa, eS = 2 * ya, eD = 2 * ya - 2 * xa, x = 0, y = 0;
	while (x < xa) {
		W->plot(p1.x + a1 * x + b1 * y, p1.y - a2 * x - b2 * y);
		if (e > 0) {
			x++;
			y++;
			e += eD;
		}
		else {
			x++;
			e += eS;
		}
	}
	W->plot(p2.x, p2.y);
}
void elipce::draw(window* w) {
	int a = (p2.x - p1.x) / 2;
	int b = (p2.y - p1.y) / 2;
	Point O(p1.x + a, p1.y + b);
	int x = 0;
	int y = b;
	int ds = 4 * b * b * (x + 1) * (x + 1) + a * a * (2 * y - 1) * (2 * y - 1) - 4 * a * a * b * b;
	int sd = a * a * (2 * x + 1) * (2 * x + 1) + 4 * b * b * (y - 1) * (y - 1) - 4 * a * a * b * b;
	while (a * a * (2 * y + 1) >= 2 * b * b * (x + 1)) {
		w->plot(O.x + x - 1, O.y - y);
		w->plot(O.x - x, O.y - y);
		w->plot(O.x + x - 1, O.y + y - 1);
		w->plot(O.x - x, O.y + y - 1);
		if (ds < 0) {
			ds = ds + 4 * b * b * (2 * x + 3);
			x++;
		}
		else {
			ds = ds + 4 * b * b * (2 * x + 3) - 8 * a * a * (y - 1);
			x++;
			y--;
		}
	}
	while (y > 0) {
		w->plot(O.x + x - 1, O.y - y);
		w->plot(O.x - x, O.y - y);
		w->plot(O.x + x - 1, O.y + y - 1);
		w->plot(O.x - x, O.y + y - 1);
		if (sd >= 0) {
			sd = sd - 4 * a * a * (2 * y - 3);
			y--;
		}
		else {
			sd = sd - 4 * a * a * (2 * y - 3) + 8 * b * b * (x + 1);
			y--;
			x++;
		}
	}
}
void Triangle::draw(window* W) {
	line l1(p1, p2);
	line l2(p2, p3);
	line l3(p3, p1);
	l1.draw(W);
	l2.draw(W);
	l3.draw(W);
}
