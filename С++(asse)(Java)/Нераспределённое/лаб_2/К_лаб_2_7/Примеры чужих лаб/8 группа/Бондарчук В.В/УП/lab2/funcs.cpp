#include"Header.h"
const double pi = 3.1415926;
const double e = 0.00000000000000000000001;
double APOW(double a, int n)
{
	long double res = 1;
	if (a == 0) return 0;
	_asm
	{
		mov ecx, n
		finit
		fld res
		METKA1 :
			fld a
			fmul
			loop METKA1
			fst res
	}
	return res;
}
double POW(double a, int n)
{
	double res = 1;
	for (int i = 1; i <= n; i++)
		res = res * a;
	return res;
}
long double SIN(double x)
{
	while ((x >= 2 * pi) || (x<0))
	{
		if (x<0)    x = x + 2 * pi;
		else    x = x - 2 * pi;
	}
	_asm
	{
		fld x
		fsin
		fst x
	}
	return x;
}
double ASIN(double x)
{
	while ((x >= 2 * pi) || (x<0))
	{
		if (x<0)    x = x + 2 * pi;
		else    x = x - 2 * pi;
	}
	double  n = 1, d = 2, ed = 1;
	double r, p = x, s = x;
	int sw;
	_asm
	{
		finit
		METKA1 :
		//------------(2 * n*(2 * n + 1))----------------------
			fld  n
			fmul d
			fst  r
			fmul r
			fadd r
			fst  r
		//-----------(p *= -1.0 * x * x /(2 * n*(2 * n + 1)))--
		//-----------(sum += p)--------------------------------
			fld  x
			fld  x
			fmul
			fchs
			fdiv r
			fmul p
			fst  p
			fadd s
			fstp s
		//-----------(n++)--------------------------------------
			fld  n
			fadd ed
			fstp n
		//-----------(while (fabs(p) > e))----------------------
			finit
			fld  p
			fabs
			fcom  e    // st(0)>e:c3=0,c0=0;   st(0)<e:c3=0,c0=1;  st(0)=e:c3=1,c0=0;
			fstsw ax
			sahf       //устанавливаем флаги ассемблера из флагов сопроцессора
			ja  METKA1
	}
	return s;
}