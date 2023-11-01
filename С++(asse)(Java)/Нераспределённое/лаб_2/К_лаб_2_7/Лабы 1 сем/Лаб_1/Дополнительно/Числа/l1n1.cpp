// 1. Нахождение НОД и НОК двух натуральных чисел,
// используя алгоритм Евклида

#include <stdio.h>

void main(void)
{
   int a,b,nod,nok;

   printf("input numbers\n");
   scanf("%d%d",&a,&b);

   nok=a*b;
   while (a!=b)
   {
	   if (a<b)
		   b=b-a;
	   if (b<a)
		   a=a-b;
   }

   nod=a;
   nok=nok/nod;
   printf("NOD=%d\n",nod);
   printf("NOK=%d\n",nok);
}