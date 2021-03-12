#ifndef Rational_H
#define Rational_H

#include <ostream>
using namespace std;

int gcd(int a, int b);
int Abs(int a);

class Rational
{
private:
	int num;
	int denum;
public:
	Rational();
	Rational(int);
	Rational(int, int);
	Rational operator-();
	Rational operator+(Rational);
	Rational operator-(Rational);
	Rational operator*(Rational);
	Rational operator/(Rational);
	bool operator<(Rational);
	bool operator>(Rational);
	bool operator<=(Rational);
	bool operator>=(Rational);
	bool operator==(Rational);
	bool operator!=(Rational);
	friend ostream& operator<<(ostream& os, const Rational& t);
	Rational& operator+=(Rational);
	Rational& operator-=(Rational);
	Rational& operator*=(Rational);
	Rational& operator/=(Rational);
};

Rational operator+(int, Rational);
Rational operator-(int, Rational);
Rational operator*(int, Rational);
Rational operator/(int, Rational);

#endif // !Rational_H