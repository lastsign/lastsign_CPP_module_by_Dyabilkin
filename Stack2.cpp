#include "pch.h"
#include "C:\Users\user\Desktop\Lib\Stack2.h"
#include <iostream>

Stack2::Stack2(int a)
{
	sz = 0;
	A = new int[a];
}
Stack2::~Stack2()
{
	sz = 0;
	delete[] A;
}
bool Stack2::empty()
{
	return !sz;
}
int Stack2::size()
{
	return sz;
}
int & Stack2::top()
{
	return A[sz - 1];
}
void Stack2::push(int a)
{
	A[sz] = a;
	sz++;
}
void Stack2::pop()
{
	A[sz] = NULL;
	sz--;
}
