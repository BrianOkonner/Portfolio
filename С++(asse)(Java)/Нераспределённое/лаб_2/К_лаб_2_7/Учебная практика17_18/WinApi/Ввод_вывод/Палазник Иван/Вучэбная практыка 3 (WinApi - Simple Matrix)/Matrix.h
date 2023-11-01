#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <Windows.h>

enum TaskBar
{
	view,
	new_value,
	new_size,
	determinant,
	Gauss,
	Kramer,
	inverse,
	exit_prog
};

class Matrix
{
private:
	int m; // height
	int n; // width
	double **matr;
	bool delete_zero_lines(); // deleting of zero lines and checking existence of solution

public:
	// "system" methods
	Matrix(int height = 1, int width = 1); // creation of matrix
	Matrix(const Matrix &a); // copy constructor
	~Matrix(void); // deleting of matrix
	const Matrix& operator=(Matrix a);
	double& operator()(int a, int b);
	void print(HWND hWnd);

	// common methods
	void create_value();
	void get_value(); // getting values from user
	void view();
	void rewrite_values(int height = 0, int width = 0);
	void replace_column(int index, Matrix& column);
	void exchange_two_rows(int index1, int index2);
	void delete_row(int index);
	void delete_column(int index);
	void add_column(std::vector<int> column);
	std::string get_string_value(int i, int j);
	std::string double_to_string(double);
	
	// dealing with matrix
	Matrix make_triangle();
	Matrix make_right_triangle();
	std::vector<std::string> Gauss_method();
	
	// dealing with squared matrix
	double determinant(bool test = 0);
	const Matrix& Kramer_rule();
	const Matrix inverse();
};