#ifndef Double_list_H
#define Double_list_H
#include "pch.h"
#include <ostream>
using namespace std;

template <class T>
class Double_list
{
private:
	T sz;
	template <class T> 
	Double_nde * tail;
	struct Double_node
	{
		T val;
		Double_node * next;
		Double_node * prev;
		Double_node();
		Double_node(T, T);
	};
public:
	Double_list();
	Double_list(T);
	~Double_list();
	void push_front(T);
	void push_back(T);
	void pop_front();
	void pop_back();
	T size();
	bool empty();
	void clear();
	T &front();
	T &back();
	void print();
	class Iterator {
	private:
		struct Double_node
		{
			T val;
			Double_node * next;
			Double_node * prev;
		};
	public:
		Iterator begin();
		Iterator end();
		Iterator insert(Iterator pos, const T&x);
		Iterator erase(Iterator);
	};

};
template <class T>
Double_list<T>::Double_list()
{
	sz = 0;
	tail = new Double_node;
	tail->next = tail->prev = tail;
}

template <class T>
Double_list<T>::Double_list(T value)
{
	sz = 1;
	tail = new Double_node;
	Double_node * temp = new Double_node;
	temp->val = value;
	T->next = temp;
	T->prev = temp;
	temp->next = T;
	temp->prev = T;
}

template <class T>
Double_list<T>::~Double_list()
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

template <class T>
void Double_list<T>::push_front(T value)
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

template <class T>
void Double_list<T>::push_back(T value)
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

template <class T>
void Double_list<T>::pop_front()
{
	sz--;
	Double_node * T = tail->next;
	Double_node * temp = T->next;
	delete T;
	tail->next = temp;
	temp->prev = tail;
}

template <class T>
void Double_list<T>::pop_back()
{
	sz--;
	Double_node * T = tail->prev;
	Double_node * temp = T->prev;
	delete T;
	temp->next = tail;
	tail->prev = temp;
}

template <class T>
T Double_list<T>::size()
{
	return sz;
}

template <class T>
bool Double_list<T>::empty()
{
	return !sz;
}

template <class T>
void Double_list<T>::clear()
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

template <class T>
T & Double_list<T>::front()
{
	return tail->next->val;
}

template <class T>
T & Double_list<T>::back()
{
	return tail->prev->val;
}

template <class T>
void Double_list<T>::print()
{
	Double_node * temp = tail->next;
	while (temp != tail)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}
#endif // !Double_list_H