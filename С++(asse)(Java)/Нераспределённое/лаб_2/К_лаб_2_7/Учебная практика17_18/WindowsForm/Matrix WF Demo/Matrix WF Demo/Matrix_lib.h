#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>

enum
{
	inverse,
	determinant,
	Kramer,
	Gauss	
};

class Matrix
{
private:
	int m; // height
	int n; // width
	double **matr;
	bool delete_zero_lines(); // deleting of zero lines and checking existence of solution
	void replace_column(int index, const Matrix& column);
	void delete_row(int index);
	void delete_column(int index);
	void add_column(const Matrix& column);
	Matrix make_triangle();
	Matrix make_right_triangle();

public:
	// Convertors
	static std::string double_to_string(double variable);
	static System::String^ string_to_String(std::string source);
	static void String_to_string(System::String^ source, std::string &str);

	// "system" methods
	Matrix(int height = 1, int width = 1); // creation of matrix
	Matrix(const Matrix &a); // copy constructor
	~Matrix(void); // deleting of matrix
	double& operator()(int a, int b);
	const Matrix& operator=(Matrix a);
	
	// common methods
	void create_random_value();
	void rewrite_values(int height = 0, int width = 0);
	void exchange_two_rows(int index1, int index2);
	std::string get_string_value(int i, int j) const;
	std::vector<std::string> get_string_matrix() const;
	
	// dealing with matrix
	std::vector<std::string> Gauss_method(const Matrix &b);
	const Matrix operator+(const Matrix& a);
	const Matrix operator-(const Matrix& a);
	const Matrix operator*(const Matrix& a);
	const Matrix& operator+=(const Matrix& a);
	const Matrix& operator-=(const Matrix& a);
	const Matrix& operator*=(const Matrix& a);
	
	// dealing with squared matrix
	double determinant();
	std::vector<std::string> Kramer_rule(const Matrix &b);
	std::vector<std::string> inverse();
};