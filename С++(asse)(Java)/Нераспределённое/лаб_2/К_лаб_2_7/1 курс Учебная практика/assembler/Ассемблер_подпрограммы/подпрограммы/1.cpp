// ������ ����� main.cpp
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


void Input_array( int ar[],int *n)
//  ����  ����������� � ���������   �������
{  
    printf("Enter dimension n<=100 \n");
	scanf("%d",n);
	printf(" Enter Items  ");
	for (int i=0;i<*n;i++)
	    scanf("%d",&ar[i]);  
 }

int* Input_arrayD ( int *ar,int *n)
//  ����  ����������� � ���������  �����������  �������
{int i;
    printf("Enter dimension n\n ");
	scanf("%d",n);
	
	printf(" Enter Items  ");   

    ar =  (int*) malloc(*n*sizeof(int));

	for (i=0;i<*n;i++) 
	    scanf("%d",&ar[i]); 
	 return ar;
 }

void Rnd_array ( int ar[],int *n)
{
	//  ����  ����������� � ��������� ���������   �������
    srand(time(0));
    printf("Enter dimensionn n<=100\n");
	scanf("%d",n);
	for (int i=0;i<*n;i++)
	    ar[i]= rand()%100;  
 }


int * Rnd_arrayD (int *ar,int *n)
{
   //  ����  ����������� � ��������� ���������   ������������ �������
	int i,j;
    printf("Enter dimension n \n");
	scanf("%d",n);
    ar =  (int*) malloc(*n*sizeof(int));

	for (i=0;i<*n;i++) 
	    ar[i]=rand()%100;  ; 
	 return ar;
 }
void Print_array ( int ar[],int n)
	//  �����   ���������    �������
{
	 printf("Items array\n");
	for ( int i=0;i<n;i++)
		           printf("%5d",ar[i]);

		printf("\n");
}
void Print_arrayD ( int *ar,int n)
	//  �����   ���������   ������������ �������
{
for ( int i=0;i<n;i++)
	
           printf("%5d",ar[i]);

		printf("\n");
}
 

#include "3.h"
#include <iostream.h>
void main()
{
	srand(time(0));
    int a [100],n ;
	int *ar;
	int *pn,int *pm;
  
      int  c;
     int x=5;
	 _asm
	 {push x
	 call fact
	 pop edx
	 mov c,eax
	 }
	 
	 cout <<c;

	 // ����� �������  
       int x10 = fact(5); 
	 cout <<x10;

	

 pn=&n;
 _asm // Input_array(a,pn);
 { lea edx,a
    lea esi ,n // ����� n
	 
		 push esi
		 push edx
		 call Input_array
		 pop esi
		 pop esi
 }

_asm //Print_array ( a,n);
{        lea edx,a 
 		 push n
		 push edx
		 call Print_array
		 pop esi
		 pop esi
 }
 
 _asm // ar=Input_arrayD(ar,pn);
 {     lea edx,ar
    lea esi ,n // ����� n
	 
		 push pn
		 push ar
		 call Input_arrayD
		 mov pn,eax
		 pop esi
		 pop esi
 }

_asm //Print_arrayD ( ar,n);
{  
		 push n
		 push pn
		 call Print_arrayD
		 pop esi
		 pop esi
 }
 
}