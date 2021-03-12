#include "pch.h"
#include "C:\Users\user\Desktop\Lib\Stack.h"
#include <iostream>

Stack::Stack()
{
}
Stack::~Stack()
{
}
bool Stack::empty()
{
	return l.empty();
}
int Stack::size()
{
	return l.size();
}
int & Stack::top()
{
	return l.front();
}
void Stack::push(int a)
{
	l.push_front(a);
}
void Stack::pop()
{
	l.pop_front();
}
