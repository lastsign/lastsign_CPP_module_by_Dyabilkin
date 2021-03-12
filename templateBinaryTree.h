#ifndef templateBinaryTree_H
#define templateBinaryTree_H

#include <iostream>
using namespace std;

template <typename T>
class AVL_tree
{
private:
	struct AVL_node
	{
		T val;
		AVL_node* left_child;
		AVL_node* right_child;
		AVL_node* parent;
		AVL_node(T v) { val = v; left_child = right_child = parent = 0; }
	};
	AVL_node* root;
	void avl_tree(AVL_node* r)
	{
		if (r)
		{
			avl_tree(r->left_child);
			avl_tree(r->right_child);
			delete r;
		}
	}
	int Height(AVL_node* r)
	{
		if (r)
		{
			int tLeft = Height(r->left_child);
			int tRight = Height(r->right_child);
			return 1 + (tLeft > tRight ? tLeft : tRight);
		}
		else
		{
			return 0;
		}
	}
	int Size(AVL_node* r)
	{
		return r ? 1 + Size(r->left_child) + Size(r->right_child) : 0;
	}
	void Print(AVL_node* r, int i)
	{
		if (r == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				cout << "/./.";
			}
			cout << "@" << endl;
		}
		else
		{
			Print(r->right_child, ++i);
			i--;
			for (int j = i; j > 0; j--)
			{
				cout << "/./.";
			}
			cout << r->val << endl;
			Print(r->left_child, ++i);
		}
	}
	void Print_in_order(AVL_node* r)
	{
		if (r)
		{
			Print_in_order(r->left_child);
			cout << r->val << " ";
			Print_in_order(r->right_child);
		}
	}
public:
	AVL_tree();
	AVL_tree(T);
	~AVL_tree();
	bool add(T);
	bool find(T);
	int height();
	int size();
	void print();
	void print_in_order();
	class Iterator {
	private:
		AVL_node* node;
		void inc() {
			if (node->right_child) {
				node = node->right_child;
				while (node->left_child) {
					node = node->left_child;
				}
			}
			else {
				while (node == node->parent->right_child) {
					node = node->parent;
				}
				node = node->parent;
			}
		}
		void dec() {
			if (node->left_child) {
				node = node->left_child;
				while (node->right_child) {
					node = node->right_child;
				}
			}
			else if (node == node->parent->right_child) {
				node = node->parent;
			}
			else {
				while (node == node->parent->left_child) {
					node = node->parent;
				}
				node = node->parent;
			}
		}
	public:
		Iterator() {
			node = NULL;
		}
		Iterator(AVL_node* a) {
			node = a;
		}
		T& operator*() const {
			return node->val;
		}
		Iterator operator+(int a) {
			Iterator t(node);
			for (int i = 0; i < a; i++) {
				++t;
			}
			return t;
		}
		Iterator operator++(int) {
			Iterator t(node);
			inc();
			return t;
		}
		Iterator& operator++() {
			inc();
			return *this;
		}
		Iterator operator--(int) {
			Iterator t(node);
			dec();
			return t;
		}
		Iterator& operator--() {
			dec();
			return *this;
		}
		Iterator operator-(int a) {
			Iterator t(node);
			for (int i = 0; i < a; i++) {
				--t;
			}
			return t;
		}
		bool operator==(Iterator l) {
			return node == l.node;
		}
		bool operator!=(Iterator l) {
			return node != l.node;
		}
		int operator-(Iterator l) {
			int k = 0;
			while (l != *this) {
				++l;
				k++;
			}
			return k;
		}
	};
	Iterator begin() {
		AVL_node* r = root;
		while (r->left_child) {
			r = r->left_child;
		}
		return Iterator(r);
	}
	Iterator end() {
		return Iterator(root);
	}
};



template<typename T>
inline AVL_tree<T>::AVL_tree()
{
	root = new AVL_node(1000000);
}

template<typename T>
inline AVL_tree<T>::AVL_tree(T v)
{
	AVL_node* t = new AVL_node(v);
	root = new AVL_node(100000);
	root->left_child = t;
	t->parent = root;
}


template<typename T>
inline AVL_tree<T>::~AVL_tree()
{
	avl_tree(root);
}


template<typename T>
inline bool AVL_tree<T>::add(T v)
{
	if (root)
	{
		AVL_node* t = root;
		AVL_node* t_prev = t;
		while (t)
		{
			if (t->val == v)
			{
				return false;
			}
			else if (t->val > v)
			{
				t_prev = t;
				t = t->left_child;
			}
			else
			{
				t_prev = t;
				t = t->right_child;
			}
		}
		if (t_prev->val > v)
		{
			t = new AVL_node(v);
			t_prev->left_child = t;
			t->parent = t_prev;
		}
		if (t_prev->val < v)
		{
			t = new AVL_node(v);
			t_prev->right_child = t;
			t->parent = t_prev;
		}
	}
	else
	{
		root = new AVL_node(v);
		return true;
	}
}
template<typename T>
inline bool AVL_tree<T>::find(T v)
{
	AVL_node* t = root;
	while (t)
	{
		if (t->val == v)
		{
			return true;
		}
		else if (t->val > v)
		{
			t = t->left_child;
		}
		else
		{
			t = t->right_child;
		}
	}
	return false;
}

template<typename T>
inline int AVL_tree<T>::height()
{
	return Height(root->left_child);
}
template<typename T>
inline int AVL_tree<T>::size()
{
	return Size(root->left_child);
}
template<typename T>
inline void AVL_tree<T>::print()
{
	Print(root->left_child, 0);
}
template<typename T>
inline void AVL_tree<T>::print_in_order()
{
	Print_in_order(root->left_child);
	cout << endl;
}
#endif // !templateBinaryTree_H
