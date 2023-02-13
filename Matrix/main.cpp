#include<iostream>
using namespace std;

//TODO:
//Реализовать класс Matrix, описывающий матрицу, и написать все необходимые методы для этого класса.

class Matrix
{
public:
	int x;
	int y;
	int matrix;
	//					Setters:
	void set_cell(int x, int y, int number)
	{
		cout << "x = " << x << " y = " << y << endl;
		cout << "&x = " << &x << " &y = " << &y << endl;
		this->matrix[&x][&y] = number;
	}
	//					Getters:
	int get_cell(int x, int y)
	{
		//cout << "getter begin" << endl;
		int i = x;
		cout << "matrix[&y][&x] = ";
		cout << this->matrix[&y][&x];
		return this->matrix[&x][&y];
	}
	int get_rows()
	{
		return y;
	}
	int get_cols()
	{
		return x;
	}
	//					Constructors:
	Matrix(int x, int y = 1)
	{
		this->x = x;
		this->y = y;
		int** matrix = new int* [y];
		for (int i = 0; i < y; i++)
		{
			matrix[i] = new int[x];
			cout << "matrix[i] = " << matrix[i] << endl;
			//cout << "*matrix[i] = " << *matrix[i] << endl;
			for (int j = 0; j < x; j++)
			{
				matrix[i][j] = i*10+j;
				//cout << "i j " << i << ' ' << j << endl;
				//cout << "x y " << x << ' ' << y << endl;
				cout << "matrix[i][j] " << matrix[i][j] << endl;
			}
		}
		cout << "Constructor:\t\t" << this << endl;
	}
	~Matrix()
	{
		for (int i = 0; i < get_rows(); i++)
		{
			//delete[] matrix[i];
		}
		delete[] &matrix;
		cout << "Destructor:\t\t" << endl;
	}
	//					Methods:
	void print()
	{
		cout << "begin printing..." << endl;
		for (int i = 0; i < get_rows(); i++)
		{
			//cout << "--matrix[" << i << "] = " << matrix[i] << endl;
			for (int j = 0; j < get_cols(); j++)
			{
				cout << "---" << matrix[&i][&j] << endl;
				//cout << "get_cell[" << i << "][" << j << "] = " << this->get_cell(i, j) << '\t';
			}
			cout << endl;
		}
		cout << "printed" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	//int B[] = { 1, 2, 3 };
	Matrix A(2, 3);
	cout << "rows " << A.get_rows() << endl;
	cout << "cols " << A.get_cols() << endl;
	cout << "--------------------------------" << endl;
	//cout << "matrix[x][y] = " << matrix[1][1] << endl;
	cout << "getters--------------------------------" << endl;
	cout << "get_cells() ";
	cout << A.get_cell(0, 0) << endl;
	cout << "get_cells() " << A.get_cell(0, 1) << endl;
	cout << "get_cells() " << A.get_cell(0, 2) << endl;
	cout << "get_cells() " << A.get_cell(1, 0) << endl;
	cout << "get_cells() " << A.get_cell(1, 1) << endl;
	cout << "get_cells() " << A.get_cell(1, 2) << endl;
	cout << "print---------------------------------" << endl;
	A.print();
	//A.set_cell(0, 0, 11);
	//A.set_cell(1, 0, 21);
	//A.set_cell(2, 0, 31);
	////cout << A.get_cell(0, 0);
	//A.set_cell(0, 1, 12);
	//A.set_cell(1, 1, 22);
	//A.set_cell(2,1, 32);
	cout << "---------------------------------" << endl;
	A.print();
}
