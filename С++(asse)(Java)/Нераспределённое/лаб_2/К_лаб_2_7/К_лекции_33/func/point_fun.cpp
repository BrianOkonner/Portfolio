#include <stdio.h> 
#include "function_h.h" 
int main ()
{
	int *r,x=1,y=2;  
    double *R,X=1.5,Y=2.3;	
	fp=(void *(*)(const void*, const void* ))AddI;
// Если есть перегруженные функции присвоить указатель нельзя
//	fp=	(double*)(double*, double*)add;
  r=(int*)(*fp)(&x,&y);
  printf("n=%d \n",*r);
 
  fp=(void *(*)(const void*, const void* ))AddD;
 R=(double*)(*fp)(&X,&Y);
 printf("n=%f \n",*R);

 char str[]="sin";
 double z=call_by_name(str, 2.4) ;
 printf("sin=%f \n",z);

 fpI=addI;
 x=fpI(3,4);
 printf("summa=%d \n",x);
 return 1;
}


