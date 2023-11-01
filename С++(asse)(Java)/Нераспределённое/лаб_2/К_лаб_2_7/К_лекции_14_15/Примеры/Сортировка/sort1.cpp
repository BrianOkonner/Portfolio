/*1. Функция для сортировки массива строк. 
Строки вводятся с консоли.
 Для сортировки используется стандартная функция.*/
#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int N;
char **a;
int comp(void* x,void* y)
{
	return strcmp(*(char **)x,*(char**)y);
}

int main()
{
	cout<<"Input N"<<endl;
	cin>>N;
	fflush(stdin);	// убираем символ новой строки из потока stdin

	a=(char**)malloc(N*sizeof(char*));
		for (int i=0;i<N;i++)
		a[i]=(char*)malloc(sizeof(char*));
	
	cout<<"Input strings\n";
	for (i=0;i<N;i++)
		gets(a[i]);
	cout<<endl;
		qsort(a,N,sizeof(char*),(int (*)(const void*, const void*))comp);
	for (i=0;i<N;i++)
		puts(a[i]);
	
return 1;
}