#include "pch.h"
#include <iostream>
using namespace std;
void Swap(int * a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void qs(int * a, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		if (a[l] < a[m])
		{
			if (a[m] < a[r])
			{
				Swap(a, l, m);
			}
			else
			{
				if (a[l] < a[r])
				{
					Swap(a, l, r);
				}
			}
		}
		else
		{
			if (a[r] < a[m])
			{
				Swap(a, l, m);
			}
			else
			{
				if (a[r] < a[l])
				{
					Swap(a, l, r);
				}
			}
		}
		int i = l, j = l + 1, k = r, pe = a[l];
		while (j <= k)
		{
			if (a[j] == pe)
			{
				j++;
			}
			else if (a[j] < pe)
			{
				Swap(a, i, j);
				j++;
				i++;
			}
			else
			{
				Swap(a, j, k);
				k--;
			}
		}
		qs(a, l, i - 1);
		qs(a, k + 1, r);
	}
}