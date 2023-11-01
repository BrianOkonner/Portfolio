#include <stdio.h>
#include <math.h>
#include <time.h>
void input_matr ( int Ma[100][100],int *n,int *m)
//  ввод  размерности и элементов   матрицы

{  
    printf("Enter dimension n<=100 , m<=100 \n");
	scanf("%d%d",n,m);
	printf(" Enter Items  ");
	for (int i=0;i<*n;i++)
	 for (int j=0;j<*m;j++)
	    scanf("%d",&Ma[i][j]);  
 }

int ** input_matr ( int **ma,int *n,int *m)
//  ввод  размерности и элементов  днамической  матрицы
{int i,j;
    printf("Enter dimension n and  m\n ");
	scanf("%d%d",n,m);
	
	printf(" Enter Items  ");   

    ma =  (int**) malloc(*n*4);

	for (i=0;i<*n;i++)
		ma[i] = (int*) malloc(*m*sizeof(int));

	for (i=0;i<*n;i++) 
		for (j=0;j<*m;j++)
	    scanf("%d",&ma[i][j]); 
	 return ma;
 }

void rnd_matr ( int Ma[100][100],int *n,int *m)
{
	//  ввод  размерности и генерация элементов   матрицы
    srand(time(0));
    printf("Enter dimensionn<=100 , m<=100 \n");
	scanf("%d%d",n,m);
	for (int i=0;i<*n;i++)
	 for (int j=0;j<*m;j++)
	    Ma[i][j]= rand()%100;  
 }


int ** rnd_matr (int **ma,int *n,int *m)
{
   //  ввод  размерности и генерация элементов   динамической матрицы
	int i,j;
    printf("Enter dimension n and  m\n");
	scanf("%d%d",n,m);
    ma =  (int**) malloc(*n*4);

	for (i=0;i<*n;i++)
		ma[i] = (int*) malloc(*m*sizeof(int));

	for (i=0;i<*n;i++) 
		for (j=0;j<*m;j++)
	    ma[i][j]=rand()%100;  ; 
	 return ma;
 }
void print_matr ( int ma[][100],int n,int m)
	//  вывод   элементов    матрицы
{
	 printf("Items Matrix\n");
	for ( int i=0;i<n;i++)
		{
		for (int j=0;j<n;j++)
           printf("%5d",ma[i][j]);

		printf("\n");
	}
}
void print_matr ( int **ma,int n,int m)
	//  вывод   элементов   динамической матрицы
{
for ( int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
           printf("%5d",ma[i][j]);

		printf("\n");
	}
}
 void main( )

{ 
	srand(time(0));
    int ma [100][100],m,n ;
	int **mad;
	int *pn,int *pm;
  
 pn=&n;
 input_matr(ma,pn,pn);
 print_matr ( ma,n,n);

  mad=input_matr(mad,pn,pn);
  print_matr ( mad,n,n);

  rnd_matr(ma,pn,pn);
  print_matr ( ma,n,n);

  mad=input_matr(mad,pn,pn);
  print_matr ( mad,n,n);

	printf("\n");
}
