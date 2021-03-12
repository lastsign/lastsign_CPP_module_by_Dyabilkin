#ifndef Polynomail_H
#define Polynomail_H
#include <iostream>
using namespace std;

class Polynomial {
	int number;
	int* coefficients;
public:
	Polynomial();
	Polynomial(int, int);
	Polynomial(const Polynomial&);
	Polynomial(int, const int*);
	~Polynomial();
	int degree() const;
	int operator[](int) const;
	int operator()(int);
	Polynomial operator+(const Polynomial&);
	Polynomial& operator+=(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial operator-();
	Polynomial operator*(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
	Polynomial& operator=(const Polynomial&);
	bool operator ==(const Polynomial&);
	bool operator != (const Polynomial&);
	Polynomial operator*(int) const;
	Polynomial& operator*=(int);
	friend Polynomial operator*(int a, const Polynomial& p);
};

Polynomial operator*(int a, const Polynomial& p);
ostream& operator<<(ostream& os, const Polynomial& p);

#endif Polynomail_H