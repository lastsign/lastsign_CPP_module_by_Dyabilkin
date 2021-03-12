#include "pch.h"
#include "Hash_table.h"
#include <iostream>
using namespace std;

int Hash_table::hash(int k)
{
	return k % table_size;
}
Cell::Cell(int k, const char * d, Cell * n)
{
	key = k;
	data = d;
	next = n;
}
Hash_table::Hash_table(const char * n, int s)
{
	table_size = s;
	not_found = n;
	table = new Cell *[table_size];
	for (int i = 0; i < table_size; i++)
	{
		table[i] = NULL;
	}
}

Hash_table::~Hash_table()
{
	for (int i = 0; i < table_size; i++)
	{
		Cell * t = table[i];
		while (t)
		{
			Cell * temp = t;
			t = t->next;
			delete temp;
		}
	}
	delete[] table;
}

bool Hash_table::add(const char * d, int k)
{
	int i = hash(k);
	Cell * temp = table[i];
	while (temp && temp->key != k)
	{
		temp = temp->next;
	}
	if (temp && temp->key == k)
	{
		return false;
	}
	else
	{
		int j = 0;
		while (d[j])
		{
			j++;
		}
		char * s = new char[j + 1];
		for (int u = 0; u < j + 1; u++)
		{
			s[u] = NULL;
		}
		for (j = 0; d[j]; j++)
		{
			s[j] = d[j];
		}
		table[i] = new Cell(k, s, table[i]);
		return true;
	}
}

void Hash_table::remove(int k)
{
	int i = hash(k);
	Cell * t = table[i];
	Cell * t_prev = t;
	while (t && t->key != k)
	{
		t_prev = t;
		t = t->next;
	}
	if (t)
	{
		if (table[i] == t)
		{
			table[i] = t->next;
			delete t;
		}
		else
		{
			t_prev->next = t->next;
			delete t;
		}
	}
}

const char * Hash_table::find(int k)
{
	int i = hash(k);
	Cell * temp = table[i];
	while (temp)
	{
		if (temp->key == k)
		{
			return temp->data;
		}
		temp = temp->next;
	}
	return not_found;
}

void Hash_table::print()
{
	for (int i = 0; i < table_size; i++)
	{
		Cell * t = table[hash(i)];
		if (t)
		{
			cout << i << ": ";
			while (t)
			{
				cout << "[" << t->data << "," << t->key << "] ";
				t = t->next;
			}
			cout << endl;
		}
	}
}
