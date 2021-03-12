#ifndef Hash_table2_H
#define Hash_table2_H

#include <iostream>
#include <string>
using namespace std;
struct Cell2
{
	int val;
	const char * key;
	Cell2 * next;
	Cell2(int, const char *, Cell2 *);
};
class Hash_table2
{
private:
	Cell2 ** table;
	int table_size;
	int n_entries;
	int not_found;
	int hash(const char *);
public:
	Hash_table2(int size, int notfound);
	~Hash_table2();
	bool add(int, const char *);
	void remove(const char *);
	int find(const char *);
	void print();
};

#endif