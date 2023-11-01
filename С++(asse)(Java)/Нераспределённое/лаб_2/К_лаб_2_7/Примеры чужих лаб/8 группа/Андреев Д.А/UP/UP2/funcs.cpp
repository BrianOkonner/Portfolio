#include  <math.h>

//считаем синус
double sinus(double x) {

	int n = 1;
	double s, p, e = 0.0000001, k=0;

	/*while ((x >= 2 * pi) || (x<0))
	{
		if (x<0)    x = x + 2 * pi;
		else    x = x - 2 * pi;
	}*/
	

	_asm {
		FINIT		//очищаем от старого
		fld x		//в st(0) - x
	point2: //сделаем х больше 0
		fstp x //вытащим х
		fldz  //в st(0) 0
		fld x //st(0) = x, st(1) = 0
		fcomi	st(0), st(1)	//сравниваем st(0) и 0
		jnbe point1	//st(0) > st(1) (x>0) пропускаем
		fldpi		//st(0) = pi, st(1) = x
		fadd		//st(0) = st(0)+st(1) = x+pi; st(1) = pi
		fadd		//st(0) = st(0)+st(1) = x+pi+pi = x+2pi; st(1) = x+pi
		jmp point2

	point1:
			
		FINIT		//очищаем от старого
		fldpi	//st(0) = pi
		fldpi	//st(0) = pi, st(1) = pi
		fadd	//st(0) = 2pi
		fld x	//st(0) = x, st(1) = 2pi
		
		fcomi	st(0), st(1)
		jb point4	//если меньше, пропускаем
		fsub st(0), st(1)	//st(0) = st(0)-st(1) (x-2pi), st(0) = x-2pi, st(1) = x
		fst x	//копируем х
		jmp point1
			point4:
		}

p = x;   s = x;

	while (fabs(p) >= e)
	{
		p = (-p * x*x) / (2 * n*(2 * n + 1));
		s = s + p;
		n = n + 1;
	}
	return s;
}
//формула
double schet(double x, int m) {

	long double s = 0;
	for (int n = 5; n < m + 5; n++) {
		s += sinus(n*x)*(pow(x, 2 * n + 1)) / (2 * n + 1);
	}

	return s;
}

double schet1(double x, int m) {

	long double s = 0;
	for (int n = 5; n < m + 5; n++) {
		s += sin(n*x)*(pow(x, 2 * n + 1)) / (2 * n + 1);
	}

	return s;
}

double schet2(double x, int m) {

	double s = 0, k, tmp;
	for (int n = 5; n < m + 5; n++) {
		//s += sin(n*x)*(pow(x, 2 * n + 1)) / (2 * n + 1);

		k = pow(x, 2 * n + 1);
		_asm {
			finit
			fild n
			fld x
			fmul
			fsin
			fld k
			fmul
			fst tmp

			fild n
			fild n
			fadd
			fld1
			fadd
			fld tmp
			fdiv st(0), st(1)
			fst tmp
		}
		s += tmp;
	}

	return s;
}