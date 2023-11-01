#include "MyFunctions.h"

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>

#define Pi 3.1415926535
#define accuracy 0.0000001

const double eps = 0.0000001;
const double pi = 3.1415926535;

using namespace std;
double ABS(double tmp)
{
	return(tmp < 0 ? -tmp : tmp);
}
double CheckEngle(double X)
{

	while (X <0) X += 2 * Pi; //Увеличение отрицательных углов
	while (X>(2 * Pi)) X -= 2 * Pi; //Уменьшение больших углов
	return X;
}
double Power(double base, double power)
{
	return (power ? base * Power(base, power - 1) : 1);
}
double ArcTanh(double X)
{
	double Sum =X, element = 1, k = X*X*X; 
	int n = 1;
		while (ABS(element) >= accuracy)
	{
		element = k / (2 * n + 1); //Вычисление n-ого элемента суммы из ряда Маклорена
		Sum+=element;//Увеличение суммы на n-ый элемент
		n++;
		k*= X*X;
	}
	
	return Sum;
}

double MArcTanh(double X)
{

	double c = 1./2, k, sum=0;
	_asm 
	{//формула 1\2 * ln(1+x)/(1-x)
		fld1// s(0)=x
		fsub X//s(0)=x*x
		fld1//s(0)=x*x*x
		fadd X
		fdiv st, st(1)
		fldln2
		fxch st(1)
		fyl2x
		fmul c
		fstp k
		fstp c
		fstp c

	}
	return k;

}

double MyCos(double X)
{
	double f2 = 1, f1 = 0, s1, s2, cos;
	_asm
	{
		
			fmul st(0), st(0)
			fst s2
			fld1
			fst s1
			fst f1
			fst cos
			fld1
			fmul doubl
			fst f2

		lable :
		
			fld s1
			fmul s2
			fdiv f1
			fdiv f2
			fchs
			fstp s1
			fld f1
			fadd doubl
			fst f1

			fld f2
			fadd doubl
			fst f2

			fld cos
			fadd s1
			fst cos

			fld s1
			fabs
			fst z

			fld z
			fcomp e
			fstsw  ax
			fstp z
			test ax, 1 shl 8
			jz lable

			fld cos
	}
	return cos;
}



double Cos(double X)
{
	X= CheckEngle(X); //Проверка угла с помощью функции CheckEngle
	double sum = 0.0, an = 1.0, sq_x;
	int n = 0;
	sq_x = X*X;

	while (ABS(an) >= accuracy) 
	{
		sum += (n % 2 == 0 ? an : -an);
		n += 1;
		an = an*sq_x / ((2 * n - 1) * 2 * n);
	}
		return sum;
}
double sum(double x0, double m)
{
	double Sum = 0.0;
	for (int n = 1; n <= m; n++) //Подсчет суммы от n=1 до m для текущего значения Х
	{
		Sum += (1 + ArcTanh(x0)) / (1 + Power(n, 3)*Cos(2 * n*x0)); //Подсчет суммы с использованием ф-ций Power, ArcTanh и Cos
	}
	return Sum;
}
double MathCheck(double x0, int m)
{
	double Sum = 0.0;
	for (int n = 1; n <= m; n++) //Подсчет суммы от n=1 до m для текущего значения Х с использованием ф-ций Math.h
	{
		Sum += (1 + atanh(x0)) / (1 + pow(n, 3)*cos(2 * n*x0));
	}
	return Sum;
}

double MathCheckSoProc(double x0, int m)
{
	double Sum = 0.0;
	for (int n = 1; n <= m; n++) //Подсчет суммы от n=1 до m для текущего значения Х с использованием ф-ций Math.h
	{
		Sum += (1 + MArcTanh(x0)) / (1 + pow(n, 3)*cos(2 * n*x0));
	}
	return Sum;
}
void output(double x0, double x1, int m, double spacing)
{

	double Sum = 0.0, mathCheck = 0.0, mathCheckSoProc=0.0;


	//Построение шапки таблицы в файле и консоли
	cout << "______________________________________________________________" << endl;
	cout << "|      x      | my function  | std. function | coprocessor " << endl; //Шапка таблицы
	cout << " -------------------------------------------------------------" << endl;

	ofstream fout("output.txt");//создание и открытие файла для записи
	fout << "| X0= " << setw(1) << x0 << setw(5) << "| X1=" << setw(6) << x1 << setw(5) << "| m= " << setw(2) << m << setw(5) << "| spacing=" << setw(5) << spacing << endl; //запись введенных значений в файл
	fout << "______________________________________________________________" << endl;//Шапка таблицы
	fout << "|      x      | my function  | std. function| coprocessor  " << endl;
	fout << " -------------------------------------------------------------" << endl;

	while (x0 <= x1)//подсчет суммы от X0 до Х1 с шагом h 
	{
		Sum = sum(x0, m); //посдчет суммы разработанной ф-цией
		mathCheck = MathCheck(x0, m); //посдчет суммы ф-циями библиотеки Math.h
		mathCheckSoProc = MathCheckSoProc(x0, m);
		fout << "|" << setw(6) << x0 << setw(8) << "|" << setw(10) << Sum << setw(5) << "|" << setw(10) << mathCheck << setw(5) << "|" << setw(10) << mathCheckSoProc << setw(7) << "|" << endl;
		cout << "|" << setw(6) << x0 << setw(8) << "|" << setw(10) << Sum << setw(5) << "|" << setw(10) << mathCheck << setw(5) << "|" << setw(10) << mathCheckSoProc << setw(7) << "|" << endl;
		x0 += spacing;
	}
	//конец таблицы
	fout << " --------------------------------------------------------------" << endl;
	fout.close();//закрытие файла
	cout << "---------------------------------------------------------------" << endl;
}