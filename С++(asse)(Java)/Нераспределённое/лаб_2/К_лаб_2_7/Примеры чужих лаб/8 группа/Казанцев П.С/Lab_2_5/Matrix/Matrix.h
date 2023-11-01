#pragma once 
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct out_of_bounds{};
struct incorrect_matrix_size{};
struct unequal_matrix_sizes{};
struct multiplication_is_impossible{};
struct no_determinant{};

class Matrix
{
	int rows;
	int columns;
	double **matr;
public:
	Matrix() :rows(0), columns(0), matr(NULL){};
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	Matrix operator= (Matrix&);

	double* operator [](const int i)const 
	{ 
		if (i < 0 || i >= rows)
		{
			out_of_bounds err;
			throw err;
		}
		return matr[i];
	}

	double& operator()(const int a, const int b)
	{
		if (a < 0 || a >= rows || b < 0 || b >= columns)
		{
			out_of_bounds err;
			throw err;
		}
		return matr[a][b];
	}

	friend istream& operator>>(istream&, Matrix&);
	friend ostream& operator<<(ostream&, Matrix&);

	Matrix operator+= (Matrix&);
	Matrix operator-= (Matrix&);
	Matrix operator*= (Matrix&);
	Matrix operator*= (double);
	Matrix operator/= (double);

	friend Matrix operator+(Matrix&, Matrix&);
	friend Matrix operator-(Matrix&, Matrix&);
	friend Matrix operator*(Matrix&, Matrix&);
	friend Matrix operator*(Matrix&, double);
	friend Matrix operator*(double, Matrix&); 
	friend Matrix operator/(Matrix&, double);

	friend Matrix operator-(const Matrix& m);
	friend Matrix operator+(const Matrix& m);

	void set_single_value(int, int, double);
	double Determinant();
};

