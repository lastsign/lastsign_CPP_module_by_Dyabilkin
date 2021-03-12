#ifndef Stack2_H
#define Stack2_H

class Stack2
{
private:
	int * A;
	int sz;
public:
	Stack2(int a);
	~Stack2();
	bool empty();
	int size();
	int & top();
	void push(int a);
	void pop();
};
#endif // !Stack2_H
