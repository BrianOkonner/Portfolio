#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream.h>
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

void flip_ci( int **p,int n)
	//  транспонирование динамической матрицы
{
for ( int i=0;i<n;i++)
{
	for (int j=0;j<n;j++)
	{
	int  c=p[i][j];
      p[i][j]=p[j][i];
      p[j][i]=c;
	}
          
}
}


int offset(int n,int i,int j)
{
     return i*n+j;
}

void flip_maAr(int * p, int n)
{
_asm
{
  pushad
   mov ebx,p
   mov eax,n
   shl eax,2
   mov ecx,n
_for1:
      push ecx
      xor esi,esi
      xor edi,edi
_for2:
      push dword ptr [ebx][esi]
      mov edx,dword ptr [ebx][edi]
      mov dword ptr [ebx][esi],edx
      pop dword ptr [ebx][edi]
      add esi,4
      add edi,eax
_ef2: loop _for2
      add ebx,eax
      add ebx,4
      pop ecx
_ef1: loop _for1
  popad
}
}

void flip_ma(int ** p, int n)
{
_asm
{
  pushad
   mov ebx,p      // для строк
   xor eax,eax
   mov ecx,n
      xor edi,edi
_for1:
      push ecx
      mov edx,ebx     //для столбцов
      mov esi,[ebx]   //адрес начала строки матрицы

  _for2:
      mov edi,[edx]
      push dword ptr [esi][eax]    //обмен
      push dword ptr [edi][eax]
      pop dword ptr [esi][eax]
      pop dword ptr [edi][eax]
      add esi,4               //по строке
      add edx,4               // к следующей строке 
      loop _for2

      add ebx,4
      add eax,4               // диагональный элемент
      pop ecx
      loop _for1
  popad
}
}

void main()
{
int i,j,n;
int **matr; 
matr = rnd_matr (matr, &n,&n);
printf("before\n");
print_matr ( matr, n,n);

flip_ma (matr,n);
printf("after\n");
print_matr ( matr, n,n);



int *matr_array; 
n=4;
matr_array = (int*) malloc(n*n*sizeof(int));

for (i=0;i<n;i++) 
	for (j=0;j<n;j++)
      matr_array[offset(n,i,j)] = rand()%100;

printf("before\n");

//flip_maAr (matr_array,n);
for (i=0;i<n;i++) 
{	for (j=0;j<n;j++)
      printf("%5d",matr_array[offset(n,i,j)]);
printf("\n");
}


printf("after\n");

for (i=0;i<n;i++) 
{ 
for (j=0;j<n;j++)
printf("%5d",matr_array[offset(n,i,j)]);
printf("\n");
}

}

