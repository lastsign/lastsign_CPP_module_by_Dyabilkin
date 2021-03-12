#include <iostream>
#include "Priority_queue.h"
using namespace std;
void error_msg(bool a)
{
	if (!a)
	{
		cout << "Error\n";
	}
}
Priority_Queue::Priority_Queue(int n)
{
	qSize = n;
	a = new int[qSize];
	k = 0;
}

Priority_Queue::~Priority_Queue()
{
	delete[] a;
}
void up(int* a, int i)
{
	int p = (i - 1) / 2;
	int temp = a[i];
	while (i >= 0 && temp < a[p])
	{
		a[i] = a[p];
		i = p;
		p = (i - 1) / 2;
	}
	a[i] = temp;
}
void Priority_Queue::push(int v)
{
	a[k++] = v;
	up(a, k - 1);
}
void down(int* a, int i, int k)
{
	int temp = a[i];
	int g;
	while (2 * i + 1 < k)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (r < k)
		{
			g = a[l] > a[r] ? r : l;
			if (a[g] < temp)
			{
				a[i] = a[g];
				i = g;
			}
			else
			{
				break;
			}
		}
		else
		{
			g = l;
			if (a[g] < temp)
			{
				a[i] = a[g];
				i = g;
			}
			else
			{
				break;
			}
		}
	}
	a[i] = temp;
}
void Priority_Queue::pop()
{
	a[0] = a[--k];
	down(a, 0, k);
}

const int& Priority_Queue::top()
{
	return a[0];
}

int Priority_Queue::size()
{
	return k;
}

bool Priority_Queue::empty()
{
	return !k;
}
