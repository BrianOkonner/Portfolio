#include "Matrix.h"

//------------------
// "system" methods
//------------------

Matrix::Matrix(int height, int width)
{
	m = height;
	n = width;

	matr = 0;
	matr = (double **)realloc(matr, height*sizeof(double *));

	for(int i=0; i<height; ++i)
	{
		matr[i] = 0;
		matr[i] = (double *)realloc(matr[i], width*sizeof(double));
		for(int j=0; j<width; ++j)
			matr[i][j] = 0;
	}
}

Matrix::Matrix(const Matrix &a)
{ // copy constructor
	/*for(int i=0; i<m; ++i)
	free(matr[i]);
	free(matr);
	*/
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
	return matr[a][b];
}

//----------------
// common methods
//----------------

void Matrix::create_value()
{
	srand(time(0));
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			matr[i][j] = rand() % (n+m) - ((n+m)/2);
}

void Matrix::get_value()
{
	std::cout << "Enter items of matrix " << m << "x" << n << ":\n";
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
		{
			std::cout << "a[" << i << "][" << j << "] = ";
			std::cin >> matr[i][j];
		}
}

void Matrix::view()
{
	for(int i=0; i<m; ++i)
	{
		for(int j=0; j<n; ++j)
			std::cout << std::setw(10) << matr[i][j];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Matrix::print(HWND hWnd)
{
	std::string temp;
	int i=0;

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

	char menu;
	std::cout << "1 - Create random values\n" << "2 - Input your oun values\n\n\n"
		<< "Enter number of required operation: ";

	while(1)
	{
		std::cin >> menu;
		if(menu == '1' || menu == '2')
			break;

		std::cout << "Incorrect input! Please, try again: ";
	}

	system("cls");
	if(menu == '1')
		create_value();
	else
		get_value();
}

void Matrix::replace_column(int index, Matrix& column)
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

		free(matr[m]); // Выдаленне апошняга (непатрэбнага) радка
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

void Matrix::add_column(std::vector<int> column)
{
	if(column.size() == m)
	{
		n++;

		for(int i=0; i<m; i++)
			matr[i] = (double *)realloc(matr[i], n*sizeof(double));

		for(int i=0; i<m; ++i)
			matr[i][n-1] = column[i];
	}
	else
		std::cout << "Erroneous attempt of adding column in matrix!" << std::endl;
}

std::string Matrix::get_string_value(int i, int j)
{
	if(i >= 0 && i< m && j >= 0 && j < n)
		return double_to_string(matr[i][j]);
	else
		return "Erroneous attempt to get value in string!..\n";
}

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

	if(second != 0)
	{
		value.push_back('.');
		second *= 100;
		first = second;
		value.push_back(char(first/10 + '0'));
		value.push_back(char(first%10 + '0'));
	}

	return value;
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

Matrix Matrix::make_triangle()
{ // ! NOTE: This function required vital description
	//		 therefore comments were represented in belarusian.

	Matrix triangle = *this;
	double k; // Каэфіцыент для памнажэння аднімаемага радка матрыцы
	double temp; // Элемент аднімаемага радка матрыцы пасля памнажэння на k
	std::cout.precision(4); // Дакладнасць вываду

	for(int i=0; i<m && i<n; ++i) // Зануленне i-га слупка
		for(int j=i+1; j<m; ++j) // Апрацоўка j-га радка (з зануленнем a[j][i])
		{
			if(triangle.matr[i][i] == 0) // Пазбяганне дзялення на нуль
				for(int h=i+1; h<m; ++h) // Пошук радка з ненулявым элементам на i-ым слупку
					if(triangle.matr[h][i] != 0)
					{
						for(int f=i; f<n; ++f)
							triangle.matr[i][f] += triangle.matr[h][f];
						break;
					}

					if(triangle.matr[i][i] == 0) // Калі не знайшлося ненулявых элементаў пасля,
						continue;				 // то патрэбны слупок ужо нулявы.

					k = triangle.matr[j][i]/triangle.matr[i][i];

					triangle.matr[j][i] = 0; // !NOTE: This operation was made for greceful only.
					// !NOTE: It's temporary action!
					// !NOTE: If you delete this line, please change starting point of 'int h' in next loop (delete '+1')!

					for(int h=i +1 ; h<n; ++h) // Зануленне элемента a[j][i] па правіле:
					{	// Калі ад радка матрыцы адняць іншы, памножаны на скаляр, 
						// то велічыня вызначніка не зменіцца.

						temp = triangle.matr[i][h] * k;
						triangle.matr[j][h] -= temp;
					}
		}

		return triangle;
}

Matrix Matrix::make_right_triangle()
{ // Функцыя - аналаг функцыі make_triangle(). Зануленне правага верхняга трохвугольніка

	Matrix triangle = *this;
	double k; // Каэфіцыент для памнажэння аднімаемага радка матрыцы
	double temp; // Элемент аднімаемага радка матрыцы пасля памнажэння на k
	std::cout.precision(4); // Дакладнасць вываду

	for(int i=m-1; i>=0 && i<n; --i) // Зануленне i-га слупка
		for(int j=i-1; j>=0; --j) // Апрацоўка j-га радка (з зануленнем a[j][i])
		{
			if(triangle.matr[i][i] == 0) // Пазбяганне дзялення на нуль
				for(int h=i-1; h>=0; --h) // Пошук радка з ненулявым элементам на i-ым слупку
					if(triangle.matr[h][i] != 0)
					{
						for(int f=0; f<n; ++f)
							triangle.matr[i][f] += triangle.matr[h][f];
						break;
					}

					if(triangle.matr[i][i] == 0) // Калі не знайшлося ненулявых элементаў пасля,
						continue;				 // то патрэбны слупок ужо нулявы.

					k = triangle.matr[j][i]/triangle.matr[i][i];

					for(int h=n-1; h>=0; --h) // Зануленне элемента a[j][i] па правіле:
					{	// Калі ад радка матрыцы адняць іншы, памножаны на скаляр, 
						// то велічыня вызначніка не зменіцца.

						temp = triangle.matr[i][h] * k;
						triangle.matr[j][h] -= temp;
					}

					triangle.matr[j][i] = 0; // !NOTE: This operation was made for greceful only.
					// !NOTE: It's temporary action!
					// !NOTE: If you delete this line, please change starting point of 'int h' in next loop (delete '+1')!
		}

		//triangle.view(); // !NOTE: This action was made only for testing.
		return triangle;
}

std::vector<std::string> Matrix::Gauss_method()
{
	Matrix b(m); // scalars B in Matrix
	std::vector<int> b_arr; // scalars B

	std::cout << "Enter scalars 'b' from right side of equations X*A = B:" << std::endl;
	b.rewrite_values();
	for(int i=0; i<b.m; ++i)
		b_arr.push_back(b.matr[i][0]);

	Matrix expand(*this);

	std::cout << "Initial matrix:\n";
	expand.view();

	expand.add_column(b_arr); // Expand matrix (A*) = (A|B)
	expand = expand.make_triangle(); // go to trapezoid form
	expand.view();

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

	//-----------Testing-----------
	std::cout << "Single matrix:\n";
	expand.view();
	//-----------Testing-----------

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

//-----------------------------
// dealing with squared matrix
//-----------------------------

double Matrix::determinant(bool test)
{
	Matrix triangle = make_triangle();
	double det = triangle.matr[0][0];
	for(int i=1; i<m && i<n; ++i)
		det *= triangle.matr[i][i];

	if(test)
		triangle.view();

	return det;
}

const Matrix& Matrix::Kramer_rule()
{
	double d = determinant();

	if(!d)
	{
		std::cout << "Determinant of your matrix A is zero, "
			"so Kramer's rule isn't working here! =(" << std::endl;
		return 0;
	}

	Matrix b(m, 1); // scalars B
	std::cout << "Enter scalars 'b' from right side of equations X*A = B:" << std::endl;
	b.rewrite_values();

	Matrix x(m, 1); // Unknown variables X
	double delta_d;
	Matrix delta; // Delta-matrix of A

	for(int i=0; i<m; ++i)
	{
		delta = *this;
		delta.replace_column(i, b);
		delta_d = delta.determinant();
		x.matr[i][0] = delta_d / d;
	}

	std::cout << std::endl << "Solution of this system of linear equations (SLE) is:" << std::endl;
	x.view();
	return x;
}

const Matrix Matrix::inverse()
{
	std::vector<int> column;
	Matrix inv(*this);

	for(int i=0; i<m; ++i)
	{
		for(int i=0; i<m; ++i)
			column.push_back(0);

		column[i] = 1;
		inv.add_column(column);
		column.clear();
	}

	inv = inv.make_triangle();
	inv = inv.make_right_triangle();

	for(int i=0; i<m; ++i)
		for(int j=inv.n-1; j>=0; --j)
			inv.matr[i][j] /= inv.matr[i][i];

	for(int i=0; i<m; ++i)
		inv.delete_column(0);
	inv.view();

	return inv;
}