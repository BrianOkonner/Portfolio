#include "Matrix.h"
Matrix::Matrix(int m, int n)
{
	if (m > 0 && n > 0)
	{
		rows = m;
		columns = n;
		matr = new double* [rows];
		for (int i = 0; i < rows; i++)
		{
			matr[i] = new double[columns];
		}
	}
	else
	{
		incorrect_matrix_size err;
		throw err;
	}
		
}
Matrix::Matrix(const Matrix& A)
{
	if (A.rows > 0 && A.columns > 0)
	{
	rows = A.rows;
	columns = A.columns;
	matr = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		matr[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matr[i][j] = A[i][j];
	}
	else
	{
		incorrect_matrix_size err;
		throw err;
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete matr[i];
	delete matr;
}


Matrix Matrix::operator= (Matrix& m)
{
	if (m.rows > 0 && m.columns > 0)
	{
		this->~Matrix();
		rows = m.rows;
		columns = m.columns;
		matr = new double*[rows];
		for (int i = 0; i < rows; i++)
		{
			matr[i] = new double[columns];
		}
		for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matr[i][j] = m[i][j];
		return *this;
	}
	else
	{
		incorrect_matrix_size err;
		throw err;
	}
}

istream& operator>>(istream& is, Matrix& m)
{
	int r, c;
	is >> r >> c;
	if (r > 0 && c > 0)
	{
		m.~Matrix();
		Matrix temp(r, c);
		m = temp;
		for (int i = 0; i < m.rows; i++)
		{
			for (int j = 0; j < m.columns; j++)
			{
				is >> m[i][j];
			}
		}
	}
	else
	{
		incorrect_matrix_size err;
		throw err;
	}
	return is;
}

ostream& operator<<(ostream& os, Matrix& m)
{
	if (!m.columns || !m.rows) 
		return os;
	os << endl;
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j<m.columns; j++)
			os << setw(6) << left << m[i][j];
		os << endl;
	}
	return os;
}

Matrix Matrix::operator+= (Matrix& m)
{
	if (rows != m.rows || columns != m.columns)
	{
		unequal_matrix_sizes err;
		throw err; // unequal sizes
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matr[i][j] += m[i][j];
	return *this;
}

Matrix Matrix::operator-= (Matrix& m)
{
	if (rows != m.rows || columns != m.columns)
	{
		unequal_matrix_sizes err;
		throw err; // unequal sizes
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matr[i][j] -= m[i][j];
	return *this;
}

Matrix Matrix::operator*= (Matrix& m)
{
	if (rows <= 0 || columns <= 0 || m.columns <= 0 || m.rows <= 0)
	{
		incorrect_matrix_size err;
		throw err;
	}
	if ( columns != m.rows)
	{
		multiplication_is_impossible err;
		throw err; //		multiplication is impossible
	}

	Matrix result(rows, m.columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < m.columns; j++)
		{
			double s = 0;
			for (int k = 0; k < columns; k++)
			{
				s += matr[i][k] * m[k][j];
			}
			result.matr[i][j] = s;
		}
	}
	*this = result;
	return *this;
}

Matrix operator+(Matrix& m1, Matrix& m2)
{
	if (m1.matr == NULL || m2.matr == NULL)
	{
		incorrect_matrix_size err;
		throw err;
	}
	Matrix result(m1);
	result+= m2;
	return result;
}

Matrix operator-(Matrix& m1, Matrix& m2)
{
	if (m1.matr == NULL || m2.matr == NULL)
	{
		incorrect_matrix_size err;
		throw err;
	}
	Matrix result(m1);
	result -= m2;
	return result;
}

Matrix operator*(Matrix& m1, Matrix& m2)
{
	if (m1.matr == NULL || m2.matr == NULL)
	{
		incorrect_matrix_size err;
		throw err;
	}
	Matrix result(m1);
	result *= m2;
	return result;
}

Matrix Matrix::operator*= (double operand)
{
	if (matr == NULL)
	{
			incorrect_matrix_size err;
			throw err;
	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matr[i][j] *= operand;
	return *this;
}

Matrix Matrix::operator/= (double operand)
{
	if (matr == NULL)
	{
		incorrect_matrix_size err;
		throw err;
	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matr[i][j] /= operand;
	return *this;
}

Matrix operator*(Matrix& m1, double operand)
{
	if (m1.matr == NULL)
	{
		incorrect_matrix_size err;
		throw err;
	}
	Matrix result(m1);
	result *= operand;
	return result;
}

Matrix operator/(Matrix& m1, double operand)
{
	if (m1.matr == NULL)
	{
		incorrect_matrix_size err;
		throw err;
	}
	Matrix result(m1);
	result /= operand;
	return result;
}

Matrix operator*(double operand, Matrix& m1)
{
	if (m1.matr == NULL)
	{
		incorrect_matrix_size err;
		throw err;
	}
	Matrix result(m1);
	result *= operand;
	return result;
}

Matrix operator-(const Matrix& m)
{
	if (m.matr == NULL)
	{
		incorrect_matrix_size err;
		throw err;
	}
	Matrix result(m);
	result *= -1;
	return result;
}

Matrix operator+(const Matrix& m)
{
	if (m.matr == NULL)
	{
		incorrect_matrix_size err;
		throw err;
	}
	Matrix result(m);
	return result;
}

void Matrix::set_single_value(int m, int n, double value)
{
	if (m < 0 || n < 0 || m >= rows || n >= columns)
	{
		out_of_bounds err;
		throw err;
	}
	matr[m][n] = value;
}

double Matrix::Determinant()
{
	if (matr == NULL)
	{
		incorrect_matrix_size err;
		throw err;
	}
	if (columns != rows)
	{
		no_determinant err;
		throw err; // no determinant here
	}
	double sum, mul;
	sum = 0;
	if (2 == rows)
	{
		sum = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
		return sum;
	}
	for (int i = 0; i < rows; i++)
	{
		mul = 1;
		int k = i;
		for (int j = 0; j < rows; j++)
		{
			mul *= matr[j][k];
			k = k == rows - 1 ? 0 : k + 1;
		}
		sum += mul;
	}
	for (int i = 0; i < rows; i++)
	{
		mul = 1;
		int k = i;
		for (int j = 0; j < rows; j++)
		{
			mul *= matr[j][k];
			k = k == 0 ? rows - 1 : k - 1;
		}
		sum -= mul;
	}
	return sum;
}
