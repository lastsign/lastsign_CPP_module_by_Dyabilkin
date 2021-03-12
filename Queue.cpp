#include "pch.h"
#include "dlist.h"
#include "Queue.h"
#include <iostream>

Queue::Queue()
{
}
Queue::~Queue()
{
}
bool Queue::empty()
{
	return l.empty();
}
int Queue::size()
{
	return l.size();
}
int & Queue::front()
{
	return l.back();
}
int & Queue::back()
{
	return l.front();
}
void Queue::push(int a)
{
	l.push_front(a);
}
void Queue::pop()
{
	l.pop_back();
}
