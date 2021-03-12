#include "pch.h"
#include "dlist.h"
#include <iostream>
using namespace std;

Double_list::Double_list()
{
	sz = 0;
	Double_node * temp = new Double_node;
	tail = temp;
	tail->next = tail->prev = tail;
}

Double_list::Double_list(int value)
{
	sz = 1;
	Double_node * T = new Double_node;
	Double_node * temp = new Double_node;
	tail = T;
	temp->val = value;
	T->next = temp;
	T->prev = temp;
	temp->next = T;
	temp->prev = T;
}

Double_list::~Double_list()
{
	Double_node * temp = tail->next;
	Double_node * T = tail->next;
	while (temp != tail)
	{
		T = T->next;
		delete temp;
		temp = T;
	}
	delete tail;
}

void Double_list::push_front(int value)
{
	sz++;
	Double_node * T = new Double_node;
	Double_node * temp = tail->next;
	tail->next = T;
	T->val = value;
	T->prev = tail;
	T->next = temp;
	temp->prev = T;
}

void Double_list::push_back(int value)
{
	sz++;
	Double_node * T = new Double_node;
	Double_node * temp = tail->prev;
	tail->prev = T;
	T->val = value;
	T->next = tail;
	T->prev = temp;
	temp->next = T;
}

void Double_list::pop_front()
{
	sz--;
	Double_node * T = tail->next;
	Double_node * temp = T->next;
	delete T;
	tail->next = temp;
	temp->prev = tail;
}

void Double_list::pop_back()
{
	sz--;
	Double_node * T = tail->prev;
	Double_node * temp = T->prev;
	delete T;
	temp->next = tail;
	tail->prev = temp;
}

int Double_list::size()
{
	return sz;
}

bool Double_list::empty()
{
	return !sz;
}

void Double_list::clear()
{
	Double_node * T = tail->next;
	Double_node * f;
	while (T != tail)
	{
		f = T->next;
		delete T;
		T = f;
	}
	tail->prev = tail->next = tail;
	sz = 0;
}

int & Double_list::front()
{
	return tail->next->val;
}

int & Double_list::back()
{
	return tail->prev->val;
}

void Double_list::print()
{
	Double_node * temp = tail->next;
	while (temp != tail)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}
