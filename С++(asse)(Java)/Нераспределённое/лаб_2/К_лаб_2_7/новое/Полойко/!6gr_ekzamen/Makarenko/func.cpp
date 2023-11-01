//экзаменационная работа
//Макаренко Анастасии
//6 группа

//функции
#include <stdio.h>
#include <locale>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "iostream"
long long StepenAsm(int chislo,int n)
{
	long long result;
	_asm
	{
			mov		eax, 1
			mov		ebx, chislo
			mov		ecx, n
			cdq
	_cikl:	mul		ebx
			loop	_cikl
			mov		dword ptr result, eax
			mov		dword ptr result+4, edx
	}	
	return result;
}
int cub(int a)
{
	return (a*(a*a));
}

void sort(int *a, int m)
{  int  x,k;   long i, j;
   for ( i=0; i < m; i++)
 {     x = a[i]%10;
		k=a[i];
	    for ( j=i-1; j>=0 && (a[j]%10) > x; j--)
		{
			a[j+1]= a[j]; 
			a[j+1] = k; 
		}   
}
}
int kod(char a)
{
	int h=(int)a;
	return h;
}   