#include "pch.h"
#include "sMatrix.h"
#include <iostream>
using namespace std;

Cell::Cell()
{

}
Cell::Cell(int r, int c, int d)
{
	row = r;
	col = c;
	data = d;
	down = NULL;
	right = NULL;
}
Sparse_Matrix::Sparse_Matrix(int r, int c, int d)
{
	n_rows = r;
	n_cols = c;
	def_value = d;
	head = new Cell(-1, -1, def_value);
	Cell * temp = head;
	for (int i = 0; i < n_cols; i++)
	{
		Cell * t = new Cell(-1, i, def_value);
		temp->right = t;
		temp = temp->right;
	}
	temp = head;
	for (int i = 0; i < n_rows; i++)
	{
		Cell * t = new Cell(i, -1, def_value);
		temp->down = t;
		temp = temp->down;
	}
}
Sparse_Matrix::~Sparse_Matrix()
{
	while (head)
	{
		Cell * t = head;
		head = head->down;
		while (t)
		{
			Cell * T = t;
			t = t->right;
			delete T;
		}
	}
}
int Sparse_Matrix::r_access(int row, int col) const
{
	Cell * t = head;
	while (t->row < row)
	{
		t = t->down;
	}
	while (t && t->col < col)
	{
		t = t->right;
	}
	if (t && t->col == col)
	{
		return t->data;
	}
	else
	{
		return def_value;
	}
}
int & Sparse_Matrix::w_access(int row, int col)
{
	Cell * t = head;
	while (t->col < col)
	{
		t = t->right;
	}
	Cell * t_prev = t;
	while (t && t->row < row)
	{
		t_prev = t;
		t = t->down;
	}
	if (t && t->row == row)
	{
		return t->data;
	}
	else
	{
		Cell * T = head;
		while (T->row < row)
		{
			T = T->down;
		}
		Cell * T_prev = T;
		while (T && T->col < col)
		{
			T_prev = T;
			T = T->right;
		}
		Cell * temp = new Cell(row, col, def_value);
		temp->down = t;
		t_prev->down = temp;
		temp->right = T;
		T_prev->right = temp;
		return temp->data;
	}
}
void Sparse_Matrix::print()
{
	Cell * temp = head->down;
	while (temp)
	{
		if (temp->right)
		{
			cout << temp->row << ": ";
			Cell * t = temp->right;
			while (t)
			{
				cout << "[(" << t->row << "," << t->col << ")" << t->data << "] ";
				t = t->right;
			}
			cout << endl;
		}
		temp = temp->down;
	}
}