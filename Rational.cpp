#include "pch.h"
#include "Rational.h"
#include <iostream>

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		int t = a;
		a = b;
		b = t;
	}
	return a;
}
int Abs(int a)
{
	return a < 0 ? -a : a;
}

Rational::Rational()
{
	num = 0;
	denum = 1;
}

Rational::Rational(int a)
{
	num = a;
	denum = 1;
}

Rational::Rational(int a, int b)
{
	if (b > 0)
	{
		num = a;
		denum = b;
		int t = gcd(Abs(a), b);
		if (t > 1)
		{
			num /= t;
			denum /= t;
		}
	}
	else if (b < 0)
	{
		num = -a;
		denum = -b;
		int t = gcd(Abs(a), b);
		if (t > 1)
		{
			num /= t;
			denum /= t;
		}
	}
}

Rational Rational::operator-()
{
	return Rational(-num, denum);
}

Rational Rational::operator+(Rational a)
{
	return Rational(num * a.denum + denum * a.num, denum * a.denum);
}

Rational Rational::operator-(Rational a)
{
	return Rational(num * a.denum - denum * a.num, denum * a.denum);
}

Rational Rational::operator*(Rational a)
{
	return Rational(num * a.num, denum * a.denum);
}

Rational Rational::operator/(Rational a)
{
	return Rational(num * a.denum, denum * a.num);
}

bool Rational::operator<(Rational a)
{
	return num * a.denum < a.num * denum;
}

bool Rational::operator>(Rational a)
{
	return num * a.denum > a.num* denum;
}

bool Rational::operator<=(Rational a)
{
	return num * a.denum <= a.num * denum;
}

bool Rational::operator>=(Rational a)
{
	return num * a.denum >= a.num * denum;
}

bool Rational::operator==(Rational a)
{
	return num * a.denum == a.num * denum;
}

bool Rational::operator!=(Rational a)
{
	return num * a.denum != a.num * denum;
}

Rational& Rational::operator+=(Rational a)
{
	return *this = *this + a;
}

Rational& Rational::operator-=(Rational a)
{
	return *this = *this - a;
}

Rational& Rational::operator*=(Rational a)
{
	return *this = *this * a;
}

Rational& Rational::operator/=(Rational a)
{
	return *this = *this / a;
}

ostream& operator<<(ostream& os, const Rational& t)
{
	if (t.denum > 1)
	{
		return os << t.num << "/" << t.denum;
	}
	else
	{
		return os << t.num;
	}
}

Rational operator+(int a, Rational b)
{
	return Rational(a) + b;
}

Rational operator-(int a, Rational b)
{
	return Rational(a) - b;
}

Rational operator*(int a, Rational b)
{
	return Rational(a) * b;
}

Rational operator/(int a, Rational b)
{
	return Rational(a) / b;
}