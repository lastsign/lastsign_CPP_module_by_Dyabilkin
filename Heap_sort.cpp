#include <iostream>
using namespace std;

void recovery(int* a, int i, int n)
{
	int temp = a[i];
	int k;
	while (2 * i + 1 < n)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (r < n)
		{
			int k = a[l] > a[r] ? l : r;
			if (a[k] > temp)
			{
				a[i] = a[k];
				i = k;
			}
			else
			{
				break;
			}
		}
		else
		{
			k = l;
			if (a[l] > temp)
			{
				a[i] = a[l];
				i = l;
			}
			else
			{
				break;
			}
		}
	}
	a[i] = temp;
}
void Heap_sort(int* a, int n)
{
	int i = n / 2 - 1;
	while (i >= 0)
	{
		recovery(a, i, n);
		i--;
	}
	int d = n - 1;
	while (d > 0)
	{
		swap(a[0], a[d]);
		recovery(a, 0, d);
		d--;
	}
}
