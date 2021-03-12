#include "C:\Users\user\Desktop\Lib\AVL_node.h"
#include <iostream>
using namespace std;

AVL_tree::AVL_tree()
{
	root = 0;
}

AVL_tree::AVL_tree(int v)
{
	root = new AVL_node(v);
}
void avl_tree(AVL_node* r)
{
	if (r)
	{
		avl_tree(r->left_child);
		avl_tree(r->right_child);
		delete r;
	}
}
AVL_tree::~AVL_tree()
{
	avl_tree(root);
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
int AVL_tree::height()
{
	return Height(root);
}

AVL_node* AVL_tree::RightRotate(AVL_node * a)
{
	AVL_node* b = a->left_child;
	AVL_node* c = b->right_child;
	a->left_child = c;
	if (c)
		c->parent = a;
	b->right_child = a;
	a->parent = b;
	if (a == root)
	{
		root = b;
		b->parent = 0;
	}
	else
	{
		b->parent = a->parent;
	}
	a->bal = a->bal + 1;
	b->bal = b->bal + 2;
	return b;
}
AVL_node* AVL_tree::LeftRotate(AVL_node * a)
{
	AVL_node* b = a->right_child;
	AVL_node* c = b->left_child;
	a->right_child = c;
	if (c)
		c->parent = a;
	b->left_child = a;
	a->parent = b;
	if (root == a)
	{
		root = b;
		b->parent = 0;
	}
	else
	{
		b->parent = a->parent;
	}
	a->bal = a->bal - 2;
	b->bal = b->bal - 1;
	return b;
}
AVL_node* AVL_tree::RightLeftRotate(AVL_node * a)
{
	AVL_node* b = a->right_child;
	AVL_node* c = b->left_child;
	AVL_node* t2 = c->left_child;
	AVL_node* t3 = c->right_child;
	b->left_child = t3;
	if (t3)
	{
		t3->parent = b;
	}
	a->right_child = c;
	c->parent = a;
	c->right_child = b;
	b->parent = c;
	a->right_child = t2;
	if (t2)
	{
		t2->parent = a;
	}
	c->left_child = a;
	a->parent = c;
	if (root == a)
	{
		root = c;
		c->parent = 0;
	}
	else
	{
		c->parent = a->parent;
	}
	if (c->bal > 0)
	{
		a->bal = -1;
		b->bal = 0;
	}
	else
	{
		if (c->bal < 0)
		{
			a->bal = 0;
			b->bal = 1;
		}
		else
		{
			a->bal = 0;
			b->bal = 0;
		}
	}
	c->bal = 0;
	return c;
}
AVL_node* AVL_tree::LeftRightRotate(AVL_node * a)
{
	AVL_node* b = a->left_child;
	AVL_node* c = b->right_child;
	AVL_node* t2 = c->left_child;
	AVL_node* t3 = c->right_child;
	b->right_child = t2;
	if (t2)
	{
		t2->parent = b;
	}
	a->left_child = c;
	c->parent = a;
	c->left_child = b;
	b->parent = c;
	a->left_child = t3;
	if (t3)
	{
		t3->parent = a;
	}
	c->right_child = a;
	a->parent = c;
	if (root == a)
	{
		root = c;
		c->parent = 0;
	}
	else
	{
		c->parent = a->parent;
	}
	if (c->bal > 0)
	{
		a->bal = 0;
		b->bal = -1;
	}
	else
	{
		if (c->bal < 0)
		{
			a->bal = 1;
			b->bal = 0;
		}
		else
		{
			a->bal = 0;
			b->bal = 0;
		}
	}
	c->bal = 0;
	return c;
}
bool AVL_tree::add(int v)
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
		AVL_node* s = t_prev;
		AVL_node* s_next = t;
		while (s)
		{
			if (s->left_child == s_next)
			{
				s->bal--;
				if (s->bal == 0 || s->bal == -2)
				{
					s_next = s;
					break;
				}
			}
			if (s->right_child == s_next)
			{
				s->bal++;
				if (s->bal == 0 || s->bal == 2)
				{
					s_next = s;
					break;
				}
			}
			s_next = s;
			s = s->parent;
		}
		AVL_node* a = s_next;
		if (a->bal < -1 && v < a->left_child->val)
		{
			a = RightRotate(a);
			return true;
		}
		if (a->bal > 1 && v > a->right_child->val)
		{
			a = LeftRotate(a);
			return true;
		}
		if (a->bal < -1 && v > a->left_child->val)
		{
			a->left_child = LeftRotate(a->left_child);
			a = RightRotate(a);
			//a = LeftRightRotate(a);
			return true;
		}
		if (a->bal > 1 && v < a->right_child->val)
		{
			a->right_child = RightRotate(a->right_child);
			a = LeftRotate(a);
			//a = RightLeftRotate(a);
			return true;
		}
	}
	else
	{
		root = new AVL_node(v);
		return true;
	}
}

bool AVL_tree::find(int v)
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
int Size(AVL_node * r)
{
	return r ? 1 + Size(r->left_child) + Size(r->right_child) : 0;
}
int AVL_tree::size()
{
	return Size(root);
}
void Print(AVL_node * r, int i)
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
void AVL_tree::print()
{
	Print(root, 0);
	cout << endl;
}
void Print_pre_order(AVL_node * r)
{
	if (r)
	{
		cout << r->val << " ";
		Print_pre_order(r->left_child);
		Print_pre_order(r->right_child);
	}
}
void AVL_tree::print_pre_order()
{
	Print_pre_order(root);
	cout << endl;
}
void Print_in_order(AVL_node * r)
{
	if (r)
	{
		Print_in_order(r->left_child);
		cout << r->val << " ";
		Print_in_order(r->right_child);
	}
}
void AVL_tree::print_in_order()
{
	Print_in_order(root);
	cout << endl;
}
void Print_post_order(AVL_node * r)
{
	if (r)
	{
		Print_post_order(r->left_child);
		Print_post_order(r->right_child);
		cout << r->val << " ";
	}
}
void AVL_tree::print_post_order()
{
	Print_post_order(root);
	cout << endl;
}