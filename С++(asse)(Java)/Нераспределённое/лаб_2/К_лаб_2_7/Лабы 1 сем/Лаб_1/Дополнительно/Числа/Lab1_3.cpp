// Lab1_3.cpp : Defines the entry point for the console application.
/*Разработать программу для вывода на экран компьютера треугольника Паскаля 
 имеющего N строк. При этом треугольник строить только в случае 
 если N - нечетное число  */

#include "stdafx.h"
#include <stdio.h>
//функция подсчета числа сочетаний
int binomial(int n,int k)
{
	if ((k<0)||(n<0)||(k>n))
		return 0;
	else
		if ((k==0)||(k==n))
			return 1;
		else
			 return (n-k+1)*binomial(n,k-1)/k;
}
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
		for (int i=0;i<=n;++i)
		{
			for (int j=0;j<=i;++j)
				printf("%d ",binomial(i,j));
            printf("\n");
		}
	}
	else
        printf("N=2*k,k-integer value\n");   //число четное
	return 0;
}
