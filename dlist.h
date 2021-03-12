#ifndef Double_list_H
#define Double_list_H
struct Double_node
{
	int val;
	Double_node * next;
	Double_node * prev;
};

class Double_list
{
private:
	int sz;
	Double_node * tail;
public:
	Double_list();
	Double_list(int);
	~Double_list();
	void push_front(int);
	void push_back(int);
	void pop_front();
	void pop_back();
	int size();
	bool empty();
	void clear();
	int &front();
	int &back();
	void print();
};
#endif // !Double_list_H