#include "pch.h"
#include "sMatrix2.h"
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

Sparse_Matrix2::Sparse_Matrix2(int def)
{
	def_value = def;
	head = new Cell(-1, -1, def_value);
}

Sparse_Matrix2::~Sparse_Matrix2()
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

int Sparse_Matrix2::r_access(int row, int col) const
{
	Cell * t = head;
	while (t && t->row < row)
	{
		t = t->down;
	}
	while (t && t->col < col)
	{
		t = t->right;
	}
	if (t && t->col == col && t->row == row)
	{
		return t->data;
	}
	else
	{
		return def_value;
	}
}

int & Sparse_Matrix2::w_access(int r, int c)
{
	Cell * t = head;
	Cell * t_prev = t;
	while (t && t->col < c)
	{
		t_prev = t;
		t = t->right;
	}
	if (t && t->col == c)
	{
		while (t && t->row < r)
		{
			t_prev = t;
			t = t->down;
		}
		if (t && t->row == r)
		{
			return t->data;
		}
		else
		{
			Cell * b = head;
			Cell * b_prev = b;
			while (b && b->row < r)
			{
				b_prev = b;
				b = b->down;
			}
			if (b && b->row == r)
			{
				while (b && b->col < c)
				{
					b_prev = b;
					b = b->right;
				}
				Cell * temp = new Cell(r, c, def_value);
				b_prev->right = temp;
				t_prev->down = temp;
				temp->right = b;
				temp->down = t;
				return temp->data;
			}
			else
			{
				Cell * p = new Cell(r, -1, def_value);
				b_prev->down = p;
				p->down = b;
				Cell * temp = new Cell(r, c, def_value);
				t_prev->down = temp;
				temp->down = t;
				p->right = temp;
				return temp->data;
			}
		}
	}
	else
	{
		Cell * p = new Cell(-1, c, def_value);
		t_prev->right = p;
		p->right = t;
		Cell * b = head;
		Cell * b_prev = b;
		while (b && b->row < r)
		{
			b_prev = b;
			b = b->down;
		}
		if (b && b->row == r)
		{
			while (b && b->col < c)
			{
				b_prev = b;
				b = b->right;
			}
			Cell * temp = new Cell(r, c, def_value);
			p->down = temp;
			b_prev->right = temp;
			temp->right = b;
			return temp->data;
		}
		else
		{
			Cell * d = new Cell(r, -1, def_value);
			b_prev->down = d;
			d->down = b;
			Cell * temp = new Cell(r, c, def_value);
			p->down = temp;
			d->right = temp;
			return temp->data;
		}
	}
}

void Sparse_Matrix2::print()
{
	Cell * temp = head->down;
	while (temp)
	{
		if (temp->right)
		{
			cout << temp->row << ":";
			Cell * t = temp->right;
			while (t)
			{
				cout << "[(" << t->row << "," << t->col << ")" << t->data << "]";
				t = t->right;
			}
			cout << endl;
		}
		temp = temp->down;
	}
}