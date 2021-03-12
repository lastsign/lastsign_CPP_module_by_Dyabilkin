#include "pch.h"
#include "Binaty_tree.h"
#include <iostream>
using namespace std;

Tree_node::Tree_node(int v)
{
	val = v;
	left_child = right_child = NULL;
}

Binary_tree::Binary_tree()
{
	root = NULL;
}

Binary_tree::Binary_tree(int v)
{
	root = new Tree_node(v);
}

void binary_tree(Tree_node * r)
{
	if (r)
	{
		binary_tree(r->left_child);
		binary_tree(r->right_child);
		delete r;
	}
}

Binary_tree::~Binary_tree()
{
	binary_tree(root);
}

bool Binary_tree::add(int v)
{
	if (root) {
		Tree_node * t = root;
		Tree_node * t_prev = t;
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
			return true;
		}
		else if (t_prev->val < v)
		{
			t = new Tree_node(v);
			t_prev->right_child = t;
			return true;
		}
	}
	else
	{
		root = new Tree_node(v);
		return true;
	}
}

bool Binary_tree::find(int v)
{
	Tree_node * t = root;
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

int Height(Tree_node * r)
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

int Binary_tree::height()
{
	return Height(root);
}

int Size(Tree_node * r)
{
	return  r ? 1 + Size(r->left_child) + Size(r->right_child) : 0;
}

int Binary_tree::size()
{
	return Size(root);
}

void Print(Tree_node * r, int i)
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

void Binary_tree::print()
{
	Print(root, 0);
	cout << endl;
}

void Print_pre_order(Tree_node * r)
{
	if (r)
	{
		cout << r->val << " ";
		Print_pre_order(r->left_child);
		Print_pre_order(r->right_child);
	}
}

void Binary_tree::print_pre_order()
{
	Print_pre_order(root);
	cout << endl;
}

void Print_in_order(Tree_node * r)
{
	if (r)
	{
		Print_in_order(r->left_child);
		cout << r->val << " ";
		Print_in_order(r->right_child);
	}
}

void Binary_tree::print_in_order()
{
	Print_in_order(root);
	cout << endl;
}

void Print_post_order(Tree_node * r)
{
	if (r)
	{
		Print_post_order(r->left_child);
		Print_post_order(r->right_child);
		cout << r->val << " ";
	}
}

void Binary_tree::print_post_order()
{
	Print_post_order(root);
	cout << endl;
}

void Binary_tree::remove(int v)
{
	Tree_node * t = root;
	Tree_node * t_prev = t;
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
		Tree_node * temp = t;
		if (!t->right_child)
		{

			if (temp == root)
			{
				root = temp->left_child;
			}
			else
			{
				if (t_prev->left_child == temp)
				{
					t_prev->left_child = t->left_child;
				}
				else
				{
					t_prev->right_child = t->left_child;
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
				}
				else
				{
					if (t_prev->right_child == temp)
					{
						t_prev->right_child = t->right_child;
					}
					else
					{
						t_prev->left_child = t->right_child;
					}
				}
				delete temp;
			}
			else
			{
				Tree_node * r = t->right_child;
				if (!r->left_child)
				{
					temp->right_child = r->right_child;
					temp->val = r->val;
					delete r;
				}
				else
				{
					Tree_node * T_prev = r;
					Tree_node * T = T_prev->left_child;
					while (T->left_child)
					{
						T = T->left_child;
						T_prev = T_prev->left_child;
					}
					t->val = T->val;
					T_prev->left_child = T->right_child;
					delete T;
				}
			}
		}
	}
}