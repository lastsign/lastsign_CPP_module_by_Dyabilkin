#include "pch.h"
#include "Hash_table2.h"
#include <iostream>
using namespace std;

int h(const char * k)
{
	int s = 0;
	for (int i = 0; k[i]; i++)
	{
		s += k[i];
	}
	return s;
}

int Hash_table2::hash(const char * k)
{
	int s = 0;
	int u = 1;
	for (int i = 0; k[i]; i++)
	{
		s += u * k[i];
		u *= -1;
	}
	return s > 0 ? s % table_size : -s % table_size;
}
Cell2::Cell2(int d, const char * k, Cell2 * n)
{
	val = d;
	key = k;
	next = n;
}

Hash_table2::Hash_table2(int size, int notfound)
{
	table_size = size;
	not_found = notfound;
	n_entries = 0;
	table = new Cell2 *[table_size];
	for (int i = 0; i < table_size; i++)
	{
		table[i] = NULL;
	}
}

Hash_table2::~Hash_table2()
{
	for (int i = 0; i < table_size; i++)
	{
		Cell2 * temp = table[i];
		while (temp)
		{
			Cell2 * t = temp;
			temp = temp->next;
			delete t;
		}
	}
	delete[] table;
}

bool Hash_table2::add(int d, const char * k)
{
	int j = hash(k);
	Cell2 * temp = table[hash(k)];
	while (temp)
	{
		for (int i = 0; k[i] && temp->key; i++)
		{
			if (k[i] == temp->key[i])
			{
				return false;
			}
		}
		temp = temp->next;
	}
	n_entries++;
	if (n_entries > 5)
	{
		table_size *= 2;
		Cell2 ** tableD = new Cell2 *[table_size];
		for (int i = 0; i < table_size; i++)
		{
			tableD[i] = NULL;
		}
		for (int i = 0; i < table_size / 2; i++)
		{
			Cell2 * t = table[i];
			while (t)
			{
				Cell2 * p = t;
				t = t->next;
				int l = hash(p->key);
				p->next = tableD[l];
				tableD[l] = p;
			}
		}
		delete[] table;
		n_entries /= table_size;
		table = tableD;
	}
	int i = 0;
	while (k[i])
	{
		i++;
	}
	char * p = new char[i + 1];
	for (int u = 0; u < i + 1; u++)
	{
		p[u] = NULL;
	}
	for (i = 0; k[i]; i++)
	{
		p[i] = k[i];
	}
	Cell2 * T = new Cell2(d, p, table[j]);
	table[j] = T;
	return true;
}

void Hash_table2::remove(const char * k)
{
	Cell2 * t = table[hash(k)];
	Cell2 * t_prev = t;
	int i = hash(k);
	while (t && hash(t->key) != i)
	{
		t_prev = t;
		t = t->next;
	}
	if (t && hash(t->key) == i)
	{
		t_prev->next = t->next;
		delete t;
		n_entries--;
	}
}

int Hash_table2::find(const char * k)
{
	Cell2 * temp = table[hash(k)];
	while (temp)
	{
		for (int i = 0; k[i] && temp->key; i++)
		{
			if (k[i] == temp->key[i])
			{
				return temp->val;
			}
		}
		temp = temp->next;
	}
	return not_found;
}

void Hash_table2::print()
{
	for (int i = 0; i < table_size; i++)
	{
		Cell2 * temp = table[i];
		if (temp)
		{
			cout << i << ": ";
			while (temp)
			{
				cout << "[" << temp->val << "," << temp->key << "] ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
}
