#include<iostream>
#include "func.h"
using namespace std;

/*double msin(double x)// считаем синус 
{
	double rez=x;

	_asm
	{
		fld rez 
			fsin
			fst rez
	}

	return rez;
}*/


double result (double x)//ассемблер
{
	double rez=x,l=1,j=2, k=10;

	_asm
	{
		
		finit
		fld rez 
		fsin
		fldlg2
		fld rez
		fyl2x
		fld j
		fmulp st(1) , st
		fld l
		faddp st(1), st
		fdivp st(1) , st
		fld k
		fmulp st(1) , st
		fst rez
	}

	return rez;
}
double mylog(double s)//логарифм ассемблер
{
	double rez=s;
	_asm
	{
		finit
		fldlg2
		fld rez
		fyl2x
		fst rez
	}
	return rez;
}

double prow(double x)//сравниваем со значением получинным с использованием стандартных функций
{ 
	double rez;
	rez=10*sin(x)/(1+log(x*x));
	return rez;
   
}

























/*double msin(double x)
{
	double pi = 3.1415926535897932384626433832795;
	if(x>0) 
	{
		while(x>(2*pi))
		{
			x-=(2*pi);
		}
	}
	else 
		if(x!=0)
		{
			x*=-1;
			while(x>(2*pi))
			{
				x-=(2*pi);
			}
			x=-1*x+2*pi;
		}

	double a=x, rez=x,k=2.,l=-1,eps=0.00001,ed =1.,mn=x,eps1=-0.00001;
	_asm
	{
		fldz
	    fldz
		xor ecx, ecx
		mov ecx, 2

		
L1:
		
		fld mn
		fmul l
		fmul a
		fmul a
		fdiv k
		fld     k
        fadd    ed     
        fstp    k
		fdiv k
		fld     k
        fadd    ed     
        fstp    k
		
		fstp mn
		fld rez
		fld mn
		faddp st(1), st
		fstp rez
		fld mn
		fabs
		fcom eps
		loop L1
		fld mn
				
	}

	return rez;
}*/

