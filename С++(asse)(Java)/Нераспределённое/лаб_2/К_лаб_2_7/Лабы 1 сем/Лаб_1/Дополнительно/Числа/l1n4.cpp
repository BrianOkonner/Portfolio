//4. Нахождение действительных корней квадратного уравнения

#include <stdio.h>
#include <math.h>

void main(void)
{
   double a,b,c,x1,x2;

   printf("input koeficients\n");
   scanf("%lf%lf%lf",&a,&b,&c);
   printf("result:\n");

   if (a==0)
   {
	   if (b==0)
		   printf("incorrect input  ");
	   else
	   {
		   x1=(-c)/b;
		   printf("x=%lf",x1);
	   }
   }
   else
	   if ((b*b-4*a*c)<0)
		   printf("no real x\n");
	   else
	   {
		   x1=(-b+sqrt(b*b-4*a*c))/(2*a);
		   x2=(-b-sqrt(b*b-4*a*c))/(2*a);
		   printf("x1=%lf\n",x1);
		   printf("x2=%lf",x2);
	   }
}