#include <stdio.h>
#include <locale>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "iostream"

int Sumcub(int a)
{
	int t=0;
	int b=a;
	while(b)
	{
		int k=b%10;
		t+=(k*(k*k));
		b/=10;
	}
	return t;
}
int posled(int a,int*b,int n)
{
	int t=0,i;
	for(i=0;i<n;i++ )
	{
		if(b[i]==153) return i;
		b[i]=Sumcub(a);
		a=b[i];
	}
	return i;
}