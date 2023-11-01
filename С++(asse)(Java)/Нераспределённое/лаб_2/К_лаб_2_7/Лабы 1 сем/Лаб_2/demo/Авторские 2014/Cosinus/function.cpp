#include<iostream>
#include<stdio.h>
#include<math.h>

double Cosin(double x)
{
	double stx,cost,e,i,fakt,z;


	double p,s,n, min_pi, pl_pi, q = 0;
	const double pi = 3.1415926535897932384626433832795;//задаём константу pi
	/*min_pi = - 2*pi;
	pl_pi = 2*pi;
	_asm
	{
		finit
		fld x

M4:		fcom pl_pi
		jnl M1
		fcom min_pi
		jna M1
		jmp M0
		
M1:		fcom q
		jb M2
		jae M3
M2:		fadd pl_pi
		jmp M4
M3:     fadd min_pi
		jmp M4
M0:		fstp x
	}*/

	
	while (( x >= 2*pi ) || ( x <= - 2*pi ))
	{
		if ( x < 0 )
			x = x + 2*pi;
			else 
			x = x - 2*pi;
	}
	p = 1;
	s = 1;
	n = 0;
	


	e=0.5E-8; //точность
	stx=x*x;  //x в степени
	fakt=2;  //значение факториала в знаменателе
	cost=1;  //первый элемент в разложении
	i=2;  //счётчик
	z=-1;  //знак элемента
	double minus=-1;
	double dva=2;
	while(stx/fakt>=e)
	{
		_asm
		{
			finit

				fld z		 //cost=cost+z*stx/fakt
				fmul stx
				fdiv fakt
				fadd cost
				fstp cost

				fld i		 //i=i+2
				fadd dva
				fstp i

				fld stx		//stx=stx*x*x
				fmul x
				fmul x
				fstp stx

				fld i		//fakt=fakt*(i-1)*i
				fmul i
				fsub i
				fmul fakt
				fstp fakt

				fld z		//z=z*(-1)//смена знака
				fmul minus
				fstp z
		}
	}
	return cost;
}
double zn ( double x, double n )//функция нахождения значения x в n степени делённое на 2*n 
{
	double r = 1, q = 1, s, u = 1, h = 2;
	//цикл нахождение значения x в n степени 
	_asm
	{
L1:		finit

			fld q
			fmul x
			fstp q

			fld r
			fadd u 
			fcom n
			fstp r
			jns L2
			jmp L1
L2:			fld q
			fdiv h
			fdiv n
			fstp s
	}
	return s;//возвращение значения s
}
void print(double i, double sum, double j)
{
	printf ( "  |%16.4lf       |%25.4lf|%25.4lf|\n",i,sum,j );
	printf ( "  -----------------------------------------------------------------------------\n" );
}

