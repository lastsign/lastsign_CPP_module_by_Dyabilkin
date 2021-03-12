#ifndef Polynomail_H
#define Polynomail_H
#include <iostream>
#include "Rational.h"
using namespace std;


template <class T>
struct Pair {
	T first;
	T second;
	Pair() {
	}
	Pair(const T& f, const T& g) {
		first = f;
		second = g;
	}
};

template <class CoefType>
class Polynomial {
	int number;
	CoefType* coefficients;
public:
	Polynomial();
	Polynomial(int, CoefType);
	Polynomial(const Polynomial&);
	Polynomial(int, const CoefType*);
	~Polynomial();
	int degree() const;
	CoefType operator[](int) const;
	template <class VarType>
	CoefType operator()(const VarType&);
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
	template <class ScalarType>
	Polynomial operator*(ScalarType) const;
	template <class ScalarType>
	Polynomial& operator*=(ScalarType);
	Pair <Polynomial> div(const Polynomial& p) {
		const Rational zero = Rational();
		if (number < p.number) {
			return Pair<Polynomial<CoefType>>(Polynomial(), p);
		}
		else {
			CoefType* s = new CoefType[number];
			for (int i = 0; i < number; i++) {
				s[i] = coefficients[i];
			}
			int m = number - p.number + 1;
			Polynomial t(m, zero);
			for (int i = 0; i < m; i++) {
				if (s[number - 1 - i] != zero) {
					CoefType k = s[number - 1 - i] / p[p.number - 1];
					t.coefficients[m - i - 1] = k;
					for (int j = 0; j < p.number; j++) {
						s[number - 1 - i - j] -= k * p[p.number - 1 - j];
					}
				}
			}
			int i = p.number - 1;
			while (i > 0 && s[i - 1] == 0) {
				i--;
			}
			Pair<Polynomial<CoefType>> pair(t, Polynomial(i, s));
			delete[] s;
			return pair;
		}
	}
};

#endif Polynomail_H


template <class CoefType>
void GCD(const Polynomial<CoefType> f, const Polynomial<CoefType> g) {
	const Polynomial<CoefType> zero = Polynomial<CoefType>();
	Polynomial<CoefType> s(g);
	Polynomial<CoefType> t(f);
	Pair<Polynomial<CoefType>>S;
	Polynomial<Rational> A[4];
	A[0] = Polynomial<CoefType>(1, Rational(1));
	A[1] = Polynomial<CoefType>();
	A[2] = Polynomial<CoefType>();
	A[3] = Polynomial<CoefType>(1, Rational(1));
	while (s != zero) {
		S = t.div(s);
		t = s; s = S.second;
		for (int i = 0; i < 2; i++) {
			Polynomial<CoefType> temp = A[i];
			A[i] = A[i + 2];
			A[i + 2] = temp - S.first * A[i + 2];
		}
	}
	cout << t * (1 / t[t.degree()]);
	cout << A[0] * (1 / t[t.degree()]);
	cout << A[1] * (1 / t[t.degree()]);
}

template <class CoefType>
ostream& operator<<(ostream& os, const Polynomial<CoefType>& p) {
	int k = 0;
	for (int i = 0; i <= p.degree(); i++) {
		if (p[i] != 0) {
			k++;
		}
	}
	if (k) {
		k--;
		for (int i = p.degree(); i >= 0; i--) {
			if (p[i] != 0) {
				os << "(" << p[i] << ")";
				if (i > 1) {
					os << "*x^" << i;
					if (k > 0) {
						os << "+";
						k--;
					}
				}
				else if (i == 1) {
					os << "*x";
					if (k > 0) {
						os << "+";
						k--;
					}
				}
			}
		}
		cout << endl;
	}
	return os;
}

template<class CoefType>
Polynomial<CoefType> Polynomial<CoefType>::operator*(const Polynomial& p) {
	if (number != 0 && p.number != 0) {
		int n = number + p.number - 1;
		const CoefType zero = CoefType();
		Polynomial t(n, zero);
		for (int u = 0; u < n; u++) {
			for (int i = 0; i < number; i++) {
				for (int j = 0; j < p.number; j++) {
					if (i + j == u) {
						t.coefficients[u] += coefficients[i] * p[j];
					}
				}
			}
		}
		return t;
	}
	else
	{
		return Polynomial();
	}
}

template<class CoefType>
Polynomial<CoefType>::Polynomial() {
	number = 0;
	coefficients = 0;
}

template<class CoefType>
Polynomial<CoefType>::Polynomial(int n, CoefType a) {
	number = n;
	coefficients = new CoefType[number];
	for (int i = 0; i < number; i++) {
		coefficients[i] = a;
	}
}

template<class CoefType>
Polynomial<CoefType>::Polynomial(const Polynomial& p) {
	number = p.number;
	if (!number) {
		coefficients = 0;
	}
	else {
		coefficients = new CoefType[number];
		for (int i = 0; i < number; i++) {
			coefficients[i] = p[i];
		}
	}
}

template<class CoefType>
Polynomial<CoefType>::Polynomial(int n, const CoefType* a) {
	number = n;
	coefficients = new CoefType[number];
	for (int i = 0; i < number; i++) {
		coefficients[i] = a[i];
	}
}

template<class CoefType>
Polynomial<CoefType>::~Polynomial() {
	delete[] coefficients;
}

template<class CoefType>
int Polynomial<CoefType>::degree() const {
	return number - 1;
}

template<class CoefType>
inline CoefType Polynomial<CoefType>::operator[](int i) const {
	return coefficients[i];
}

template<class CoefType>
inline Polynomial<CoefType> Polynomial<CoefType>::operator+(const Polynomial& p) {
	if (number > p.number) {
		Polynomial t(*this);
		for (int i = 0; i < p.number; i++) {
			t.coefficients[i] += p[i];
		}
		return t;
	}
	else if (number < p.number) {
		Polynomial t(p);
		for (int i = 0; i < number; i++) {
			t.coefficients[i] += coefficients[i];
		}
		return t;
	}
	else {
		int k = number;
		while (k > 0 && coefficients[k - 1] + p[k - 1] == 0) {
			k--;
		}
		if (!k) {
			return Polynomial();
		}
		else {
			Polynomial t(k, coefficients);
			for (int j = 0; j < t.number; j++) {
				t.coefficients[j] += p[j];
			}
			return t;
		}
	}
}

template<class CoefType>
inline Polynomial<CoefType>& Polynomial<CoefType>::operator+=(const Polynomial& p) {
	if (number > p.number) {
		for (int i = 0; i < p.number; i++) {
			coefficients[i] += p[i];
		}
		return *this;
	}
	else if (number < p.number)
	{
		CoefType* a = new CoefType[p.number];
		for (int i = 0; i < p.number; i++) {
			a[i] = p[i];
		}
		for (int i = 0; i < number; i++) {
			a[i] += coefficients[i];
		}
		number = p.number;
		delete[] coefficients;
		coefficients = a;
		return *this;
	}
	else {
		int k = number;
		while (k > 0 && coefficients[k - 1] + p[k - 1] == 0) {
			k--;
		}
		if (!k) {
			number = 0;
			delete[] coefficients;
			coefficients = 0;
			return *this;
		}
		else {
			CoefType* t = new CoefType[k];
			for (int i = 0; i < k; i++) {
				t[i] = coefficients[i];
			}
			for (int j = 0; j < k; j++) {
				t[j] += p[j];
			}
			number = k;
			delete[] coefficients;
			coefficients = t;
			return *this;
		}
	}
}

template<class CoefType>
inline Polynomial<CoefType> Polynomial<CoefType>::operator-(const Polynomial& p) {
	if (number > p.number) {
		Polynomial t(number, coefficients);
		for (int i = 0; i < p.number; i++) {
			t.coefficients[i] -= p[i];
		}
		return t;
	}
	else if (number < p.number) {
		CoefType* a = new CoefType[p.number];
		for (int i = 0; i < number; i++) {
			a[i] = -p[i];
		}
		for (int i = 0; i < number; i++) {
			a[i] += coefficients[i];
		}
		Polynomial t(p.number, a);
		delete[] a;
		return t;
	}
	else {
		int k = number;
		while (k > 0 && coefficients[k - 1] - p[k - 1] == 0) {
			k--;
		}
		if (!k) {
			return Polynomial();
		}
		else {
			Polynomial t(k, coefficients);
			for (int j = 0; j < t.number; j++) {
				t.coefficients[j] -= p[j];
			}
			return t;
		}
	}
}

template<class CoefType>
inline Polynomial<CoefType>& Polynomial<CoefType>::operator-=(const Polynomial& p) {
	if (number > p.number) {
		for (int i = 0; i < p.number; i++) {
			coefficients[i] -= p[i];
		}
		return *this;
	}
	else if (number < p.number)
	{
		CoefType* a = new CoefType[p.number];
		for (int i = 0; i < p.number; i++) {
			a[i] = -p[i];
		}
		for (int i = 0; i < number; i++) {
			a[i] += coefficients[i];
		}
		delete[] coefficients;
		coefficients = a;
		number = p.number;
		return *this;
	}
	else {
		int k = number;
		while (k > 0 && coefficients[k - 1] - p[k - 1] == 0) {
			k--;
		}
		if (!k) {
			number = 0;
			delete[] coefficients;
			coefficients = 0;
			return *this;
		}
		else {
			CoefType* t = new CoefType[k];
			for (int i = 0; i < k; i++) {
				t[i] = coefficients[i];
			}
			for (int j = 0; j < k; j++) {
				t[j] -= p[j];
			}
			number = k;
			delete[] coefficients;
			coefficients = t;
			return *this;
		}
	}
}

template<class CoefType>
inline Polynomial<CoefType> Polynomial<CoefType>::operator-() {
	Polynomial t(*this);
	for (int i = 0; i < number; i++) {
		t.coefficients[i] = -t.coefficients[i];
	}
	return t;
}

template<class CoefType>
inline Polynomial<CoefType>& Polynomial<CoefType>::operator*=(const Polynomial& p) {
	if (!number) {
		return*this;
	}
	else if (!p.number) {
		number = 0;
		delete[] coefficients;
		coefficients = 0;
		return *this;
	}
	else {
		if (p.number == 1) {
			for (int i = 0; i < number; i++) {
				coefficients[i] *= p[0];
			}
			return *this;
		}
		else {
			int n = number + p.number - 1;
			CoefType* a = new CoefType[n];
			for (int i = 0; i < n; i++) {
				a[i] = 0;
			}
			for (int u = 0; u < n; u++) {
				for (int i = 0; i < number; i++) {
					for (int j = 0; j < p.number; j++) {
						if (i + j == u) {
							a[u] += coefficients[i] * p[j];
						}
					}
				}
			}
			delete[] coefficients;
			coefficients = a;
			number = n;
			return *this;
		}
	}
}

template<class CoefType>
Polynomial<CoefType>& Polynomial<CoefType>::operator=(const Polynomial& p) {
	if (number != p.number) {
		number = p.number;
		delete[] coefficients;
		coefficients = new CoefType[p.number];
		for (int i = 0; i < p.number; i++) {
			coefficients[i] = p[i];
		}
		return *this;
	}
	else {
		for (int i = 0; i < number; i++) {
			coefficients[i] = p[i];
		}
		return *this;
	}
}

template<class CoefType>
bool Polynomial<CoefType>::operator==(const Polynomial& p) {
	if (number == p.number) {
		for (int i = 0; i < number; i++) {
			if (coefficients[i] != p[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

template<class CoefType>
bool Polynomial<CoefType>::operator!=(const Polynomial& p) {
	if (number == p.number) {
		for (int i = 0; i < number; i++) {
			if (coefficients[i] != p[i]) {
				return true;
			}
		}
		return false;
	}
	else {
		return true;
	}
}

template<class CoefType>
template <class ScalarType>
Polynomial<CoefType> Polynomial<CoefType>::operator*(ScalarType a) const {
	const ScalarType zero = ScalarType();
	if (a == zero) {
		return Polynomial();
	}
	else {
		Polynomial P(number, coefficients);
		for (int i = 0; i < number; i++) {
			P.coefficients[i] *= a;
		}
		return P;
	}
}

template<class CoefType>
template<class VarType>
CoefType Polynomial<CoefType>::operator()(const VarType& x) {
	CoefType res = 0;
	for (int i = 0; i < number; i++) {
		res = res * x + coefficients[number - i - 1];
	}
	return res;
}

template <class CoefType>
template <class ScalarType>
Polynomial<CoefType>& Polynomial<CoefType>::operator*=(ScalarType a) {
	const ScalarType zero = ScalarType();
	if (a == zero) {
		delete[] coefficients;
		coefficients = 0;
		number = 0;
		return *this;
	}
	else {
		for (int i = 0; i < number; i++) {
			coefficients[i] *= a;
		}
		return *this;
	}
}
template<class ScalarType, class CoefType>
inline Polynomial<CoefType> operator*(ScalarType a, const Polynomial<CoefType>& p) {
	return p * a;
}
