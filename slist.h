#ifndef Single_list_H
#define Single_list_H

struct Single_node
{
	int val;
	Single_node* next;
	Single_node();
	Single_node(int, Single_node*);
	Single_node(int);
};
class Single_list
{
private:
	Single_node* head;
	Single_node* tail;
	void copy(const Single_list& );
public:
	Single_list();
	Single_list(int);
	Single_list(const Single_list&);
	Single_list& operator=(const Single_list&);
	~Single_list();
	void push_front(int);
	void push_back(int);
	void pop_front();
	void pop_back();
	bool empty();
	void clear();
	int size();
	int& front();
	void print();
};
#endif // !Single_list_H
