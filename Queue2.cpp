#include "pch.h"
#include "Queue2.h"
#include <iostream>

Queue2::Queue2(int n)
{
	A = new int[n];
	sz = n;
	i = 0;
	k = 0;
}
Queue2::~Queue2()
{
	delete[] A;
}
bool Queue2::empty()
{
	return !k;
}
void Queue2::push(int U)
{
	i = i % sz;
	A[i++] = U;
	k++;
}
void Queue2::pop()
{
	k--;
}
int Queue2::size()
{
	return k;
}
int & Queue2::front()
{
	return A[(sz - k + i) % sz];
}
int & Queue2::back()
{
	return A[i - 1];
}
