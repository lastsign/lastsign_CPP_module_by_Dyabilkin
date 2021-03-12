#ifndef Binary_tree_H
#define Binary_tree_H

#include <iostream>

struct Tree_node
{
	int val;
	Tree_node * left_child;
	Tree_node * right_child;
	Tree_node(int);
};

class Binary_tree
{
private:
	Tree_node * root;
public:
	Binary_tree();
	Binary_tree(int);
	~Binary_tree();
	bool add(int);
	bool find(int);
	int height();
	int size();
	void print();
	void print_pre_order();
	void print_in_order();
	void print_post_order();
	void remove(int);
};

#endif