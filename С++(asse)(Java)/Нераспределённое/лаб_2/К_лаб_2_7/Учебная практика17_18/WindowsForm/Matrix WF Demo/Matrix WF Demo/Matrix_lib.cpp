#include "stdafx.h"
#include "Matrix_lib.h"

using namespace System;

//------------------
// Convertors
//------------------

std::string Matrix::double_to_string(double variable)
{
	std::string value;
	int first = fabs(variable);
	double second = fabs(variable) - first;

	if(first == 0)
		value.push_back(char('0'));

	while(first)
	{
		value.push_back(char(first%10 + '0'));
		first /= 10;
	}

	if(variable < 0)
		value.push_back('-');

	for(int h=0, temp; h<value.size()/2; ++h)
	{ // Reverse
		temp = value[h];
		value[h] = value[value.size()-1-h];
		value[value.size()-1-h] = temp;
	}

	std::string float_tail;
	if(second != 0) // ��������� 4-� ����� ����� ����
	{
		value.push_back('.');
		first = second * 10000; // ������ ���� ����� ����

		while(first)
		{
			float_tail.push_back(char(first%10 + '0'));
			first /= 10;
		}

		while(!float_tail.empty()) // �������������� � ���� ������ ����� ����
		{
			value.push_back(float_tail.back());
			float_tail.pop_back();
		}

		while(value.back() == '0') // ��������� ��������� ��븢
			value.pop_back();
	}

	return value;
}

String^ Matrix::string_to_String(std::string source)
{
	using namespace System::Runtime::InteropServices;

	
	char *out = new char[source.size() + 1];
	for(int i=0; i<source.size(); ++i)
		out[i] = source[i];
	out[source.size()] = '\0';

	String^ ms = Marshal::PtrToStringAnsi(static_cast<IntPtr>(out));
	return ms;
}

void Matrix::String_to_string(String^ s, std::string &str)
{
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	str = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

//------------------
// "system" methods
//------------------

Matrix::Matrix(int height, int width)
{
	srand(time(0));
	m = height;
	n = width;

	matr = 0;
	matr = (double **)realloc(matr, height*sizeof(double *));

	for(int i=0; i<height; ++i)
	{
		matr[i] = 0;
		matr[i] = (double *)realloc(matr[i], width*sizeof(double));
		for(int j=0; j<width; ++j)
			matr[i][j] = rand()%10;
	}
}

Matrix::Matrix(const Matrix &a)
{ // copy constructor
	m = a.m;
	matr = 0;	
	matr = (double **)realloc(matr, m*sizeof(double *));

	n = a.n;
	for(int i=0; i<m; ++i)
	{
		matr[i] = 0;
		matr[i] = (double *)realloc(matr[i], n*sizeof(double));

		for(int j=0; j<n; ++j)
			matr[i][j] = a.matr[i][j];
	}		
}

Matrix::~Matrix(void)
{
	for(int i=0; i<m; ++i)
		free(matr[i]);
	free(matr);
}

const Matrix& Matrix::operator=(Matrix a)
{
	for(int i=0; i<m; ++i)
		free(matr[i]);
	free(matr);

	m = a.m;
	matr = 0;
	matr = (double **)realloc(matr, m*sizeof(double *));

	n = a.n;
	for(int i=0; i<m; ++i)
	{
		matr[i] = 0;
		matr[i] = (double *)realloc(matr[i], n*sizeof(double));
	}

	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			matr[i][j] = a.matr[i][j];

	return *this;
}

double& Matrix::operator()(int a, int b)
{
	if(a >= 0 && a < m && b >= 0 && b < n)
		return matr[a][b];
}

Matrix Matrix::make_triangle()
{ 
	Matrix triangle = *this;
	double k; // ���������� ��� ���������� ���������� ����� �������
	double temp; // ������� ���������� ����� ������� ����� ���������� �� k
	
	for(int i=0; i<m && i<n; ++i) // ��������� i-�� ������
		for(int j=i+1; j<m; ++j) // �������� j-�� ����� (� ���������� a[j][i])
		{
			if(triangle.matr[i][i] == 0) // ���������� �������� �� ����
				for(int h=i+1; h<m; ++h) // ����� ����� � ��������� ��������� �� i-�� ������
					if(triangle.matr[h][i] != 0)
					{
						for(int f=i; f<n; ++f)
							triangle.matr[i][f] += triangle.matr[h][f];
						break;
					}

					if(triangle.matr[i][i] == 0) // ��� �� ��������� ��������� �������� �����,
						continue;				 // �� �������� ������ ��� ������.

					k = triangle.matr[j][i]/triangle.matr[i][i];
					triangle.matr[j][i] = 0;

					for(int h=i +1 ; h<n; ++h) // ��������� �������� a[j][i] �� ������:
					{	// ��� �� ����� ������� ������ ����, ��������� �� ������, 
						// �� ������� ��������� �� �������.

						temp = triangle.matr[i][h] * k;
						triangle.matr[j][h] -= temp;
					}
		}

		return triangle;
}

Matrix Matrix::make_right_triangle()
{ // ������� - ������ ������� make_triangle(). ��������� ������� �������� �������������

	Matrix triangle = *this;
	double k; // ���������� ��� ���������� ���������� ����� �������
	double temp; // ������� ���������� ����� ������� ����� ���������� �� k
	std::cout.precision(4); // ����������� ������

	for(int i=m-1; i>=0 && i<n; --i) // ��������� i-�� ������
		for(int j=i-1; j>=0; --j) // �������� j-�� ����� (� ���������� a[j][i])
		{
			if(triangle.matr[i][i] == 0) // ���������� �������� �� ����
				for(int h=i-1; h>=0; --h) // ����� ����� � ��������� ��������� �� i-�� ������
					if(triangle.matr[h][i] != 0)
					{
						for(int f=0; f<n; ++f)
							triangle.matr[i][f] += triangle.matr[h][f];
						break;
					}

					if(triangle.matr[i][i] == 0) // ��� �� ��������� ��������� �������� �����,
						continue;				 // �� �������� ������ ��� ������.

					k = triangle.matr[j][i]/triangle.matr[i][i];

					for(int h=n-1; h>=0; --h) // ��������� �������� a[j][i] �� ������:
					{	// ��� �� ����� ������� ������ ����, ��������� �� ������, 
						// �� ������� ��������� �� �������.

						temp = triangle.matr[i][h] * k;
						triangle.matr[j][h] -= temp;
					}

					triangle.matr[j][i] = 0; 
		}

		return triangle;
}

//----------------
// common methods
//----------------

void Matrix::create_random_value()
{
	srand(time(0));
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			matr[i][j] = rand() % (n+m) - ((n+m)/2);
}

void Matrix::rewrite_values(int height, int width)
{
	if(width != 0)
		n = width;

	if(height != 0 && width != 0)
	{
		m = height;
		n = width;
	}

	if(height != 0 && width == 0)
		m = n = height;


	matr = 0;	
	matr = (double **)realloc(matr, m*sizeof(double *));

	for(int i=0; i<m; ++i)
	{
		matr[i] = 0;
		matr[i] = (double *)realloc(matr[i], n*sizeof(double));
	}		

	create_random_value();
}

void Matrix::replace_column(int index, const Matrix& column)
{
	if(column.m == m && column.n == 1 && index >= 0 && index < n)
		for(int i=0; i<m; ++i)
			matr[i][index] = column.matr[i][0];
	else
		std::cout << "Erroneous attempt of replacing column in matrix!" << std::endl;
}

void Matrix::exchange_two_rows(int index1, int index2)
{
	double temp;
	if(index1 >= 0 && index1 < m && index2 >= 0 && index2 < m)
		for(int i=0; i<n; ++i)
		{
			temp = matr[index1][i];
			matr[index1][i] = matr[index2][i];
			matr[index2][i] = temp;
		}
	else
		std::cout << "Erroneous attempt of exchanging two rows in matrix!" << std::endl;
}

void Matrix::delete_row(int index)
{
	if(index >= 0 && index <= m)
	{
		m--;

		for(int i=index; i<m; i++)
			for(int j=0; j<n; j++)
				matr[i][j] = matr[i+1][j];

		free(matr[m]); // ��������� �������� (������������) �����
		matr = (double **)realloc(matr, m*sizeof(double *));
	}
	else
		std::cout << "Erroneous attempt of deleting row in matrix!" << std::endl;
}

void Matrix::delete_column(int index)
{
	if(index >= 0 && index <= n)
	{
		n--;

		for(int i=0; i<m; i++)
		{
			for(int j=index; j<n; j++)
				matr[i][j] = matr[i][j+1];

			matr[i] = (double *)realloc(matr[i], n*sizeof(double));
		}
	}
	else
		std::cout << "Erroneous attempt of deleting column in matrix!" << std::endl;
}

void Matrix::add_column(const Matrix& column)
{
	if(column.m == m)
	{
		n++;

		for(int i=0; i<m; i++)
			matr[i] = (double *)realloc(matr[i], n*sizeof(double));

		for(int i=0; i<m; ++i)
			matr[i][n-1] = column.matr[i][0];
	}
	else
		std::cout << "Erroneous attempt of adding column in matrix!" << std::endl;
}

std::string Matrix::get_string_value(int i, int j) const
{
	if(i >= 0 && i< m && j >= 0 && j < n)
		return double_to_string(matr[i][j]);
	else
		return "Erroneous attempt to get value in string!..\n";
}

std::vector<std::string> Matrix::get_string_matrix() const
{
	using namespace std;
	vector<string> output;

	for(int i=0; i<m; ++i)
	{
		output.push_back("");
		for(int j=0; j<n; ++j)
		{
			output[i] += double_to_string(matr[i][j]);
			if(j < n-1)
				output[i] += "   ";
		}
	}

	return output;
}

bool Matrix::delete_zero_lines()
{
	bool zero_line;
	for(int i=0; i<m; ++i) // Delete all zero lines
	{
		zero_line = true;

		for(int j=0; j<n; ++j)
			if(matr[i][j] != 0)
			{
				if(j == (n - 1)) // if (0 == 1) than no solution
					return true;

				zero_line = false;
				break;
			}

			if(zero_line)
			{
				delete_row(i);
				i--;
			}
	}

	return false;
}

//---------------------
// dealing with matrix
//---------------------

std::vector<std::string> Matrix::Gauss_method(const Matrix &b)
{
	Matrix expand(*this); // Expand matrix (A*) = (A|B)
	expand.add_column(b);
	expand = expand.make_triangle(); // go to trapezoid form

	std::vector<std::string> solution;

	if(expand.delete_zero_lines()) // Check the existence of solution (0 = 1).
	{							   // And delete zero lines.
		solution.push_back("This system of equations hasn't got solution since 0=1.");
		return solution;
	}

	expand = expand.make_right_triangle();

	if(expand.delete_zero_lines()) // Check the existence of solution (0 = 1).
	{							   // And delete zero lines.
		solution.push_back("This system of equations hasn't got solution since 0=1.");
		return solution;
	}

	for(int i=0; i<expand.m; ++i) // Make single diagonal in expand matrix
		for(int j=expand.n-1; j>=0; --j)
			expand.matr[i][j] /= expand.matr[i][i];

	bool zero_line;
	for(int i=0; i<n; ++i)
	{ // Create solution output
		// Write "xi = ", i = 0,1,...,m
		solution.push_back("x");
		solution[i] += char(i+1+'0');
		solution[i] += " = ";

		if(i >= expand.m)
		{
			solution[i] += char(i+'a'-expand.m);
			continue;
		}

		zero_line = true;
		for(int j=i+1; j<expand.n; ++j)
			if(expand.matr[i][j] != 0)
			{
				zero_line = false;
				break;
			}

			if(zero_line) // write "xi = 0", if this case occured.
			{
				solution[i] += "0";
				continue;
			}

			for(int j=expand.m; j<expand.n; ++j)
			{ // write solution in line
				if(expand.matr[i][j] != 0)
				{
					if(j != (expand.n - 1))
						expand.matr[i][j] = -expand.matr[i][j];

					if(expand.matr[i][j] > 0 && j > expand.m)
						solution[i] += '+';

					solution[i] += expand.get_string_value(i, j);

					if(j != (expand.n - 1))
					{
						solution[i] += "*";
						solution[i] += char(j+'a'-expand.m);
					}
				}
			}
	}

	return solution;
}

const Matrix Matrix::operator+(const Matrix& a)
{
	if(a.m != m || a.n != n)
		return 0;

	Matrix sum(m, n);
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			sum.matr[i][j] = matr[i][j] + a.matr[i][j];

	return sum;
}

const Matrix Matrix::operator-(const Matrix& a)
{
	if(a.m != m || a.n != n)
		return 0;

	Matrix sub(m, n);
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			sub.matr[i][j] = matr[i][j] + a.matr[i][j];

	return sub;
}

const Matrix Matrix::operator*(const Matrix& a)
{
	if(n != a.m)
		return 0;

	Matrix mul(m, n);
	for(int i=0; i<m; ++i)
		for(int j=0; j<a.n; ++j)
			for(int h=0; h<n; ++h)
				mul.matr[i][j] = matr[i][h] + a.matr[h][j];

	return mul;
}

const Matrix& Matrix::operator+=(const Matrix& a)
{
	return (*this + a);
}

const Matrix& Matrix::operator-=(const Matrix& a)
{
	return (*this - a);
}

const Matrix& Matrix::operator*=(const Matrix& a)
{
	return (*this * a);
}

//-----------------------------
// dealing with squared matrix
//-----------------------------

double Matrix::determinant()
{
	Matrix triangle = make_triangle();
	double det = triangle.matr[0][0];
	
	for(int i=1; i<m && i<n; ++i)
		det *= triangle.matr[i][i];

	return det;
}

std::vector<std::string> Matrix::Kramer_rule(const Matrix &b)
{
	using namespace std;
	double d = determinant();
	vector<string> solution;

	if(!d)
	{
		solution.push_back("No solution since det(A) = 0.");
		return solution;
	}

	double delta_d;
	Matrix delta; // Delta-matrix of A
	
	for(int i=0; i<m; ++i)
	{
		delta = *this;
		delta.replace_column(i, b);
		delta_d = delta.determinant();
		
		solution.push_back("x");
		solution[i] += ('0'+i);
		solution[i] += " = ";
		solution[i] += double_to_string(delta_d / d);
	}

	return solution;
}

std::vector<std::string> Matrix::inverse()
{
	Matrix column(m, 1);
	Matrix inv(*this);

	for(int i=0; i<m; ++i)
	{
		for(int j=0; j<m; ++j)
			column(j, 0) = 0;

		column(i, 0) = 1;
		inv.add_column(column);
	}

	inv = inv.make_triangle();
	inv = inv.make_right_triangle();

	for(int i=0; i<m; ++i)
		for(int j=inv.n-1; j>=0; --j)
			inv.matr[i][j] /= inv.matr[i][i];

	for(int i=0; i<m; ++i)
		inv.delete_column(0);

	return inv.get_string_matrix();
}