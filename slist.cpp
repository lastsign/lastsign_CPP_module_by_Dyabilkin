#include "slist.h"
#include <iostream>

Single_node::Single_node()
{
	next = 0;
}

Single_node::Single_node(int a, Single_node* n)
{
	val = a;
	next = n;
}

Single_node::Single_node(int a)
{
	val = a;
}

void Single_list::copy(const Single_list& l)
{
	if (l.head != l.tail)
	{
		head = new Single_node(l.head->val);
		Single_node* t = head;
		Single_node* p = l.head->next;
		while (p != l.tail)
		{
			t->next = new Single_node(p->val);
			t = t->next;
			p = p->next;
		}
		t->next = tail;
	}
}

Single_list::Single_list()
{
	head = tail = new Single_node();
}

Single_list::Single_list(int a)
{
	tail = new Single_node();
	head = new Single_node(a, tail);
}

Single_list::Single_list(const Single_list& l)
{
	head = tail = new Single_node();
	copy(l);
}

Single_list& Single_list::operator=(const Single_list& l)
{
	clear();
	copy(l);
	return *this;
}

Single_list::~Single_list()
{
	Single_node* temp;
	while (head != tail)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
	delete head;
}

void Single_list::push_front(int value)
{
	Single_node* temp = new Single_node(value, head);
	head = temp;
}

void Single_list::push_back(int value)
{
	if (!head)
	{
		head = new Single_node(value, tail);
	}
	else
	{
		Single_node* t = head;
		Single_node* t_prev = t;
		while (t != tail)
		{
			t_prev = t;
			t = t->next;
		}
		Single_node* temp = new Single_node(value, tail);
		t_prev->next = temp;
	}
}

void Single_list::pop_front()
{
	Single_node* temp = head;
	head = temp->next;
	delete temp;
}

void Single_list::pop_back()
{
	Single_node* t = head;
	Single_node* t_prev = t;
	while (t != tail)
	{
		t_prev = t;
		t = t->next;
	}
	tail = t_prev;
	delete t;
}

bool Single_list::empty()
{
	return head == tail;
}

void Single_list::clear()
{
	Single_node* temp;
	while (head != tail)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

int Single_list::size()
{
	int k = 0;
	Single_node* t = head;
	while (t != tail)
	{
		k++;
		t = t->next;
	}
	return k;
}

int& Single_list::front()
{
	return head->val;
}

void Single_list::print()
{
	Single_node* t = head;
	while (t != tail)
	{
		std::cout << t->val << " ";
		t = t->next;
	}
	std::cout << std::endl;
}
