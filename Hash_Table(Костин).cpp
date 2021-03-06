#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

struct Cell {
	char* data;
	int key;
	Cell *next;
	Cell() {
		next = 0;
	}
	Cell(const char* d, int k);
	~Cell();
};

Cell::~Cell() {
	delete[] data;
}

class Hash_table {
private:
	Cell **table;
	int table_size;
	const char *not_found;
	int hash(int); //возвращает номер строки
public:
	Hash_table(int size, const char* not_found);
	~Hash_table();
	bool add(const char*, int);
	void remove(int);
	const char* find(int);
	void print();

};

Hash_table::Hash_table(int size, const char* not_f)
{
	table_size = size;
	not_found = not_f;
	table = new Cell*[size];
	for (int i = 0; i < size; i++)
		table[i] = 0;

}
int Hash_table::hash(int k)
{
	return k % table_size;
}
Hash_table::~Hash_table()
{
	for (int i = 0; i < table_size; i++) {
		if (table[i]) {
			Cell *f = table[i];
			while (f) {
				Cell *h = f->next;
				delete f;
				f = h;
			}
		}
	}
	delete[] table;
}

bool Hash_table::add(const char* a, int k)
{

	int i = hash(k);

	Cell *t = table[i];

	while (t && t->key != k)
		t = t->next;

	if (t && t->key == k) return false;
	else {
		Cell *f = new Cell(a, k);
		Cell *help = table[i];
		table[i] = f;
		f->next = help;

		return true;
	}

}

void Hash_table::remove(int k)
{
	int i = hash(k);
	Cell *f = 0;
	Cell *h = table[i];
	while (h && h->key != k)
	{
		f = h;
		h = h->next;
	}
	if (h)
		if (h == table[i])
		{
			Cell *help = table[i]->next;
			delete table[i];
			table[i] = help;
		}
		else
		{
			Cell *help = h->next;
			f->next = help;
			delete h;
		}
}

const char* Hash_table::find(int k)
{
	int i = hash(k);
	Cell *f = table[i];

	while (f && f->key != k)
		f = f->next;

	if (f && f->key == k) return f->data;
	else return not_found;


}

void Hash_table::print()
{
	int c = 0;
	while (c != table_size) {
		Cell *f = table[c];
		bool b = false;
		if (f) b = true;
		if (b) cout << c << ": ";
		while (f) {
			cout << "[" << f->data << ", " << f->key << "] ";
			f = f->next;
		}
		c++;
		if (b) cout << endl;
	}
}

Cell::Cell(const char * d, int k)
{
	int l = 0;
	while (d[l])
		l++;
	data = new char[l + 1];
	for (int i = 0; d[i]; i++)
		data[i] = d[i];
	data[l] = 0;
	key = k;

}



int main()
{
	char s[10];
	strcpy_s(s, "abc");
	Hash_table hash(5, " ");
	hash.add(s, 99);
	hash.add("abc", 100);
	hash.add("def", 100);
	hash.add("ghi", 101);
	hash.print();
	strcpy_s(s, "jkl");
	cout << endl;
	hash.print();
	/*cout << hash.find(99) <<endl;
	cout <<hash.find(100) <<endl;
	cout << hash.find(101) << endl;
	cout <<hash.find(66) << endl;
	hash.remove(99);
	hash.remove(100);
	hash.remove(101);
	hash.remove(5);
	for (int i = 0; i < 25; i++)
		hash.add("xyz", i);
	hash.print();*/
}
