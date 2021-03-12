#ifndef Sparse_Matrix2_H
#define Sparse_Matrix2_h

struct Cell
{
	int row;
	int col;
	int data;
	Cell * right;
	Cell * down;
	Cell();
	Cell(int, int, int);
};

class Sparse_Matrix2
{
private:
	Cell * head;
	int def_value;
public:
	Sparse_Matrix2(int);
	int r_access(int, int) const;
	int &w_access(int, int);
	~Sparse_Matrix2();
	void print();
};

#endif // !Sparse_Matrix2_H