#ifndef Queue2_H
#define Queue2_H
#include <iostream>
using namespace std;

class Queue2
{
private:
	int i;
	int k;
	int sz;
	int * A;
public:
	Queue2(int);
	~Queue2();
	bool empty();
	int size();
	int & front();
	int & back();
	void push(int);
	void pop();
};
#endif // !Queue2_H
