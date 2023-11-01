#include "header.h"
#include <iostream>
using namespace std;
double step_asm(double x, int n)
{double y;
	_asm
	{
		mov ecx, n
		sub ecx, 1
		finit
		fld x
    M1: fmul x
	    loop M1
        fst y 
	}
  return y;
}

long double Cos_asm( long double x)
{long double s=0,p=1,t,one=1,one1=-1; 
double i=1;
double h=0.000001;
const double pi2 = 3.14159265*2;
 
while (x>pi2)
x-=pi2;
while (x<0)
x+=pi2;
while (p>=h || -p>=h )
_asm
   {finit
    fld  s
    fadd p  //s+=p*1.
	fstp  s
	fld  i
	fadd one  //i+1
	fmul i     //(i+1)*i
	fstp  t
	fld  x
    fmul x     //x*x
    fmul one1    // (-1)*x*x
	fdiv t   // (-1)*x*x/(i+1)*i
	fstp  t
    fld p
	fmul t    //p*=(-1.0*x*x)/(i*(i+1))
    fstp  p
    fld   i   //i=i+2;
	fadd  one
	fadd  one
	fstp  i
    }
return s;
}

long double Arctanh_asm (long double x)
{long double s=0,p,two=2,t; 
double i=3;
double h=0.000000001;
p=x;
while (p>=h || -p>=h)
   _asm
     {finit
      fld  s
      fadd p  //s+=p*1.
	  fstp s
      fld  i
      fsub two   //(i-2)
	  fmul x
	  fmul x      //x*x(i-2)
	  fdiv i
      fstp t     //((1.0*x*x)*(i-2))/i
	  fld  p
	  fmul t
	  fstp p     //p*=((1.0*x*x)*(i-2))/i
	  fld  i
	  fadd two
	  fstp i
      }
return s;
}

double fcos_asm(double x)
{const double pi2 = 3.14159265*2;
while (x>pi2)
x-=pi2;
while (x<0)
x+=pi2;
_asm
  {   fld  x
      fcos 
	  fstp x
  }
return x;
}

double farctanh_asm(double x)
{                              //0.5*log((1+x)/(1-x))
double one=1,half=0.5;
_asm
  {finit
   fld x
   fadd one   //(x+1)
   fld one
   fsub x       //(1-x)
   fdiv 
   fstp x    // x=(1+x)/(1-x)
   fstp one   //выбросилт мусор
   fldln2     //e
   fld x
   fyl2x    //ln((1+x)/(1-x))
   fmul half
   fstp x
  }
return x;
}