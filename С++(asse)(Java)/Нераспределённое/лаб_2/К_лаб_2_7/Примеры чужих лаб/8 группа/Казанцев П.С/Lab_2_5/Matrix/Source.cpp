/* Казанцев Павел Сергеевич
   1 курс 8 группа
   
   Лабораторная работа №5
   Класс матриц

*/
#include "Matrix.h"
#include <locale>
int main(void)
{
	setlocale(LC_ALL, "rus");
	try
	{
		ifstream in;
		in.open("Matrix.txt");
		Matrix A;
		in >> A;
		Matrix B;
		//cout << "Введите размеры и элементы матрицы B" << endl;
		in >> B;
		in.close();

		cout << A;
		cout << B;

		cout <<"~~~"<< B(1, 0);
		//cout << "det B = " << B.Determinant();
		Matrix C = -A;
		cout << C;
	}
	catch (incorrect_matrix_size) // works
	{
		cout << "Incorrect matrix size" << endl;
	}
	catch (out_of_bounds)
	{
		cout << "Out of bounds" << endl;
	}
	catch (unequal_matrix_sizes) // works
	{
		cout << "Unequal matrix sizes" << endl;
	}
	catch (multiplication_is_impossible) // works
	{
		cout << "Multiplication is impossible" << endl;
	}
	catch (no_determinant) // works
	{
		cout << "There are no determinant for this matrix" << endl;
	}
	catch (...)
	{
		cout << "Unknown exeption" << endl;
	}
	system("pause");
	return 0;
}