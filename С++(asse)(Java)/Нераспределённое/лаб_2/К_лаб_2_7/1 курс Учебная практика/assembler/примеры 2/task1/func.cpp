#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

ifstream in;
ofstream out;

const double eps = 0.000001; //константа точности

double myCh(double x)
{
	double c = 2, d, i = 1, t = 1;
	_asm
	{
		fld1				// s(0) = 1 
		fld x				// s(0) = x s(1) = 1
		fmul x				// s(0) = x*x
		fdiv c				// s(0) = x*x/2
	
	_f1:
		
		// add to sum new term
		fxch st(1)			// s(0) = s s(1) = p
		fadd st, st(1)		// s(0) = s_new s(1) = p

		
		fxch st(1)			// s(0) = p s(1) = s_new
		// The next term of the sum
		fld i				// i ++
		fadd t
		fst i
		fmul c				// 2*i

		fxch st(1)			// s(0) = p s(1) = 2*i 
		fdiv st, st(1)
		fxch st(1)			// s(0) = 2*i s(1) = p/2*i 
		fsub t				// 2*i - 1
		fxch st(1)			// s(0) = p s(1) = 2*i-1
		fdiv st, st(1)		// s(0) = p/(2*i-1)/(2*i)
		fxch st(1)			// s(0) = 2*i-1 s(1) = p_new 
		fstp d				// s(0) = p_new s(1) = s_new
		fmul x
		fmul x				// p*x*x

		// compare with epsilon
		fld eps
		fcomip st, st(1)
		jae _end
		jmp _f1

	_end:
		fstp c
		fstp c
	}

	return c;
}

double myAsin2(double x)
{
	double c = 2, d, i = 1, t = 1, k;
	_asm
	{
		fld x				// s(0) = x 
		fld x				// s(0) = x s(1) = x
		fmul x				// s(0) = x*x
		fmul x				// s(0) = x*x*x
		fdiv c				// s(0) = x*x*x/2
	
	_f1:
		
		// add to sum new term
		fst d
		fld i				// 
		fmul c				// 2*i
		fadd t				// 2*i + 1
		fdivp st(1), st		// p / (2*i + 1)
		fstp k				// p_
		fld d				// p_norm
		fxch st(1)		
		fadd st, st(1)		// s(0) = s_new s(1) = p

		
		fxch st(1)			// s(0) = p s(1) = s_new
		
		// The next term of the sum
		fld i				// i ++
		fadd t
		fst i
		fmul c				// 2*i
		fsub t				// 2*i - 1

		fxch st(1)			// s(0) = p s(1) = 2*i-1
		fdiv c
		fdiv i
		fmul st, st(1)		// s(0) = p* 2*i-1
		fxch st(1)			// s(0) = 2*i-1 s(1) = p_new 
		fstp d				// s(0) = p_new s(1) = s_new
		fmul x
		fmul x				// p*x*x

		// compare with epsilon
		fst d
		fld i				// 2 * i - 1
		fmul c
		fadd t
		fdivp st(1), st		// p / 2*i-1
		
		fld eps
		fcomip st, st(1)
		jae _end
		fstp k
		fld d
		jmp _f1

	_end:
		fstp c
		fstp c
	}

	return c;
}

double myAsin(double x)
{
	double p, s = x, s1 = 0;
	p = x*x*x / 2;
	int i = 1;
	while (abs(s1 - s) > eps)
	{
		s1 = s;
		s += p / (2 * i + 1);
		i++;
		p = p*x*x*(2 * i - 1) / 2 / i;

	}
	return s;
}

void openFiles()
{
	in.open("input.txt");
	out.open("output.txt");

	if (!in.is_open())
	{
		cout << "ERROR: input.txt cannot be load" << endl;
		system("pause");
		abort();
	}
}

void input(double &a, double &b, double &h)
{
	in.precision(10);
	in >> a >> b >> h;
	in.close();
	/* Проверка на валидность данных */
	if (b < a) swap(a, b);

	if (a < -1)
	{
		out << "ERROR: a must be in [-1..1]" << endl;
		out.close();
		abort();
	}

	if (b > 1)
	{
		out << "ERROR: b must be in [-1..1]" << endl;
		out.close();
		exit(0);
	}

}

void calcAndOutput(double a, double b, double h)
{
	double myAns, mathAns, maxX, maxY;
	// myAns-содержит ответ вычисленный при помощи собственных функций (mych,myasin)
	// mathAns - содержит ответ вычисленный при помощи функций библиотеки cmath(cosh,asin)
	// maxY, maxX - максимальное значение функции и аргумент при котором функция принимает максимальное значение
	out << "|           x           |  y with my function  |  y with math function  |" << endl;

	maxX = a;
	maxY = -2 * myAsin(maxX) + 3 * myCh(maxX) + 1.5;

	for (double x = a; x <= b; x += h)
	{

		myAns = -2 * myAsin(x) + 3 * myCh(x) + 1.5;
		mathAns = -2 * asin(x) + 3 * cosh(x) + 1.5;

		out << "|" << setw(23) << x << "|" << setw(22) << myAns << "|" << setw(24) << mathAns << "|" << endl;

		/* Поиск максимального значения функции */
		if (myAns > maxY)
		{
			maxY = myAns;
			maxX = x;
		}
	}


	out << "The function takes the maximum value when the argument is x=" << maxX << ". The maximum value of the function is equal to " << maxY << endl;
}

void outputTime(unsigned int startTime)
{
	unsigned int endTime, workTime;
	endTime = clock();
	workTime = endTime - startTime;
	out << "Programm finnished in " << workTime << "ms" << endl;
	out.close();
}