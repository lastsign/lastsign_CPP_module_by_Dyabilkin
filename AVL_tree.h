#ifndef AVL_tree_H
#define AVL_tree_H

#include <iostream>
using namespace std;
struct AVL_node
{
	int val;
	int bal;
	AVL_node* left_child;
	AVL_node* right_child;
	AVL_node* parent;
	AVL_node(int v) { bal = 0; val = v; left_child = right_child = parent = 0; }
};

class AVL_tree
{
private:
	AVL_node* root;
public:
	AVL_tree();
	AVL_tree(int);
	~AVL_tree();
	bool add(int);
	bool find(int);
	int height();
	int size();
	void print();
	void print_pre_order();
	void print_in_order();
	void print_post_order();
	AVL_node* RightRotate(AVL_node*);
	AVL_node* LeftRotate(AVL_node*);
	AVL_node* RightLeftRotate(AVL_node*);
	AVL_node* LeftRightRotate(AVL_node* );

};
#endif // !AVL_tree_H
