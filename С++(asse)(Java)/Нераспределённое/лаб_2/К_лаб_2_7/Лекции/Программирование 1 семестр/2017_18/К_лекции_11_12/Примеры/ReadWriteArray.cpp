#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


void Input_array( int ar[],int *n)
//  ввод  размерности и элементов   массива
{  
    printf("Enter dimension n<=100 \n");
	scanf("%d",n);
	printf(" Enter Items  ");
	for (int i=0;i<*n;i++)
	    scanf("%d",&ar[i]);  
 }

int* Input_arrayD ( int *ar,int *n)
//  ввод  размерности и элементов  массива
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
	//  ввод  размерности и генерация элементов   массива
    srand(time(0));
    printf("Enter dimensionn n<=100\n");
	scanf("%d",n);
	for (int i=0;i<*n;i++)
	    ar[i]= rand()%100;  
 }


int * Rnd_arrayD (int *ar,int *n)
{
   //  ввод  размерности и генерация элементов   динамического массива
	int i,j;
    printf("Enter dimension n \n");
	scanf("%d",n);
    ar =  (int*) malloc(*n*sizeof(int));

	for (i=0;i<*n;i++) 
	    ar[i]=rand()%100;  ; 
	 return ar;
 }
void Print_array ( int ar[],int n)
	//  вывод   элементов    массива
{
	 printf("Items array\n");
	for ( int i=0;i<n;i++)
		           printf("%5d",ar[i]);

		printf("\n");
}
void Print_arrayD ( int *ar,int n)
	//  вывод   элементов   динамического массива
{
for ( int i=0;i<n;i++)
	
           printf("%5d",ar[i]);

		printf("\n");
}
 void main( )

{ 
	srand(time(0));
    int a [100],n ;
	int *ar;
	int *pn,int *pm;
  
/* pn=&n;
 Input_array(a,pn);
 Print_array ( a,n);

  ar=Input_arrayD(ar,pn);
  Print_arrayD ( ar,n);*/

  Rnd_array(a,pn);
  Print_array ( a,n);

  ar=Rnd_arrayD(ar,pn);
  Print_array ( ar,n);

	printf("\n");
}
