#ifndef templateBT_H
#define templateBT_H


#include <iostream>
using namespace std;

template <class T>
class Binary_tree
{
private:
	struct Tree_node
	{
		T val;
		Tree_node* left_child;
		Tree_node* right_child;
		Tree_node* parent;
		Tree_node(T);
	};
	Tree_node* root;
public:
	Binary_tree();
	Binary_tree(T);
	~Binary_tree();
	bool add(T);
	bool find(T);
	int height();
	int size();
	void print();
	void print_preorder();
	void print_inorder();
	void print_postorder();
	void remove(T);
	class Iterator {
	private:
		Tree_node* node;
	public:
		Iterator() {
			node = NULL;
		}
		Iterator(Tree_node* a) {
			node = a;
		}
		T& operator*() {
			return node->val;
		}
		Iterator operator+(int a) {
			Tree_node* t = node->parent;
			for (int i = 0; i < a; i++) {
				if (node->right_child) {
					node = node->right_child;
				}
				else if (node->left_child) {
					node = node->left_child;
				}
				else {
					node = t;
					t = t->parent;
				}
			}
		}
		Iterator& operator++(int) {
			if (node->left_child) {
				Tree_node* r = node;
				node = node->left_child;
				return Iterator(r);
			}
			else if (node->right_child) {
				Tree_node* r = node;
				node = node->right_child;
				return Iterator(r);
			}
			else {
				Tree_node* r = node;
				node = node->parent;
				return Iterator(r);
			}
		}
		Iterator& operator++() {
			if (node->left_child) {
				node = node->left_child;
				return Iterator(node);
			}
			else if (node->right_child) {
				node = node->right_child;
				return Iterator(node);
			}
			else {
				node = node->parent;
				return Iterator(node);
			}
		}
		Iterator& operator--(int) {
			if (node->parent && node->parent->left_child == node) {
				Tree_node* r = node;
				node = node->parent;
				return Iterator(r);
			}
			else if (node->left_child && node->left_child->parent == node) {
				Tree_node* r = node;
				node = node->left_child;
				return Iterator(r);
			}
		}
		Iterator& operator--() {
			if (node->parent && node->parent->left_child == node) {
				node = node->parent;
				return Iterator(node);
			}
			else if (node->left_child && node->left_child->parent == node) {
				node = node->left_child;
				return Iterator(node);
			}
		}
		Iterator operator-(int a) {
		}
		bool operator==(Iterator l) {
			return node == l.node;
		}
		bool operator!=(Iterator l) {
			return node != l.node;
		}
		int operator-(Iterator l) {
			int k = 0;
			while (node != l.node) {
				node--;
				k++;
			}
			return k;
		}
	};
	Iterator begin() {
		Tree_node* r = root;
		while (r->left_child) {
			r = r->left_child;
		}
		return Iterator(r);
	}
	Iterator end() {
		return root;
	}
};

template <class T>
Tree_node<T>::Tree_node(T v)
{
	val = v;
	left_child = right_child = parent = NULL;
}

template <class T>
Binary_tree<T>::Binary_tree()
{
	root = new Tree_node(1000000);
}

template <class T>
Binary_tree<T>::Binary_tree(T v)
{
	root = new Tree_node(100000);
	Tree_node* t = new Tree_node(v);
	root->left_child = t;
	t->parent = root;
}

template <class T>
void binary_tree(Tree_node* r)
{
	if (r)
	{
		binary_tree(r->left_child);
		binary_tree(r->right_child);
		delete r;
	}
}

template <class T>
Binary_tree<T>::~Binary_tree()
{
	binary_tree(root);
}

template <class T>
bool Binary_tree<T>::add(T v)
{
	if (root) {
		Tree_node* t = root;
		Tree_node* t_prev = t;
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
			t = new Tree_node(v);
			t_prev->left_child = t;
			t->parent = t_prev;
			return true;
		}
		else if (t_prev->val < v)
		{
			t = new Tree_node(v);
			t_prev->right_child = t;
			t->parent = t_prev;
			return true;
		}
	}
	else
	{
		root = new Tree_node(v);
		return true;
	}
}

template <class T>
bool Binary_tree<T>::find(T v)
{
	Tree_node* t = root;
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

template <class T>
int Height(Tree_node* r)
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

template <class T>
int Binary_tree<T>::height()
{
	return Height(root);
}

template <class T>
int Size(Tree_node* r)
{
	return  r ? 1 + Size(r->left_child) + Size(r->right_child) : 0;
}


int Binary_tree::size()
{
	return Size(root);
}

template <class T>
void Print(Tree_node* r, int i)
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

template <class T>
void Binary_tree<T>::print()
{
	Print(root, 0);
	cout << endl;
}

template <class T>
void Print_preorder(Tree_node* r)
{
	if (r)
	{
		cout << r->val << " ";
		Print_preorder(r->left_child);
		Print_preorder(r->right_child);
	}
}

template <class T>
void Binary_tree<T>::print_preorder()
{
	Print_preorder(root);
	cout << endl;
}

void Print_inorder(Tree_node* r)
{
	if (r)
	{
		Print_inorder(r->left_child);
		cout << r->val << " ";
		Print_inorder(r->right_child);
	}
}

template <class T>
void Binary_tree<T>::print_inorder()
{
	Print_inorder(root);
	cout << endl;
}

template <class T>
void Print_postorder(Tree_node* r)
{
	if (r)
	{
		Print_postorder(r->left_child);
		Print_postorder(r->right_child);
		cout << r->val << " ";
	}
}

template <class T>
void Binary_tree<T>::print_postorder()
{
	Print_postorder(root);
	cout << endl;
}

template <class T>
void Binary_tree<T>::remove(T v)
{
	Tree_node* t = root;
	Tree_node* t_prev = t;
	while (t && t->val != v)
	{
		if (v > t->val)
		{
			t_prev = t;
			t = t->right_child;
		}
		else if (v < t->val)
		{
			t_prev = t;
			t = t->left_child;
		}
	}
	if (t)
	{
		Tree_node* temp = t;
		if (!t->right_child)
		{
			if (temp == root)
			{
				root = temp->left_child;
				temp->left_child->parent = root;
			}
			else
			{
				if (t_prev->left_child == temp)
				{
					t_prev->left_child = t->left_child;
					t->left_child->parent = t_prev;
				}
				else
				{
					t_prev->right_child = t->left_child;
					t->left_child->parent = t_prev;
				}
			}
			delete temp;
		}
		else
		{
			if (!t->left_child)
			{
				if (temp == root)
				{
					root = temp->right_child;
					temp->right_child->parent = root;
				}
				else
				{
					if (t_prev->right_child == temp)
					{
						t_prev->right_child = t->right_child;
						t->right_child->parent = t_prev;
					}
					else
					{
						t_prev->left_child = t->right_child;
						t->right_child->parent = t_prev;
					}
				}
				delete temp;
			}
			else
			{
				Tree_node* r = t->right_child;
				if (!r->left_child)
				{
					temp->right_child = r->right_child;
					r->right_child->parent = temp;
					temp->val = r->val;
					delete r;
				}
				else
				{
					Tree_node* T_prev = r;
					Tree_node* T = T_prev->left_child;
					while (T->left_child)
					{
						T = T->left_child;
						T_prev = T_prev->left_child;
					}
					t->val = T->val;
					T_prev->left_child = T->right_child;
					T->right_child->parent = T_prev;
					delete T;
				}
			}
		}
	}
}

#endif // !templateBT_H