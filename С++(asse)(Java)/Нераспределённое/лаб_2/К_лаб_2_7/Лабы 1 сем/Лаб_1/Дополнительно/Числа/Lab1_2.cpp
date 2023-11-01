// Lab1_2.cpp : Defines the entry point for the console application.
/* Разработать программу для вывода на экран компьютера N строк треугольника, 
   состоящего из символов '*' и имеющего вид:

      *
      ***
      *****
      .......

   При этом треугольник строить только в случае если N - нечетное число.*/

#include "stdafx.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int n=-1;
	//ввод N
	printf("Input N:\n");
	scanf("%d",&n);
	//сравнение на четность
	if (n%2)
	{   //печать результата        
		printf("The result:\n");
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=i;++j)
				printf("* ");
            printf("\n");
		}
	}
	else
        printf("N=2*k,k-integer value\n");   //число четное
	return 0;
}
