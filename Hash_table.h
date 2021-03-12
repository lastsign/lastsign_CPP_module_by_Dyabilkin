#ifndef Hash_table_H
#define Hash_table_H

#include <iostream>

struct Cell
{
	int key;
	const char * data;
	Cell * next;
	Cell(int, const char *, Cell *);
};
class Hash_table
{
private:
	Cell ** table;
	int table_size;
	const char * not_found;
	int hash(int);
public:
	Hash_table(const char * not_found, int size);
	~Hash_table();
	bool add(const char *, int);
	void remove(int);
	const char * find(int);
	void print();
};

#endif