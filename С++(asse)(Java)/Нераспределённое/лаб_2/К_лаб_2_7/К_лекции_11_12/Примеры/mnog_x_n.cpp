// ћногозначные вычислени€ n^m
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int  maxsize=100;

void  pown_m(int *a,int n, int m)
/*	возведение в степень */
{
 for(  int i=0;i<maxsize;i++)
    a[i]=0;
 a[maxsize-1]=1;
 for( i=0;i<n;i++)
 {
  int  per=0; 
   for(  int j=maxsize-1; j>0;j--)
   {
     int k=a[j]*m+per;
     per=k / 10;
     a[j]=k % 10;
   }
 }
 
}

