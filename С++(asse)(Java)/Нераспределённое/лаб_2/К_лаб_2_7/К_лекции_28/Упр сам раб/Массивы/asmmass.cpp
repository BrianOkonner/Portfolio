#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
int * rnd_mas (int *n)
{  int *mas;
   //  ввод  размерности и генерация элементов   динамической матрицы
	int i,j;
    printf("Enter dimension n \n");
	scanf("%d",n);
    mas =  (int*) malloc(*n*4);
	for (i=0;i<*n;i++) 
		    mas[i]=rand()%100;  ; 
	 return mas;
 }

void  sort (int *array,int len)
{  
_asm
{        mov ecx,len
	     dec ecx
loop1:   push ecx
	     mov esi,array
  loop2:  mov eax,[esi]
          cmp eax,[esi+4]  
          jle then
          xchg eax,[esi+4]
          mov [esi],eax
  then:   add esi,4
	     loop  loop2
	     pop  ecx
         loop loop1           } 
 }

int ** rnd_matr (int *n,int *m)
{  int **ma;
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
void print_mas ( int *mas,int n)
	//  вывод   элементов   динамической матрицы
{
for ( int i=0;i<n;i++)
           printf("%5d",mas[i]);
		printf("\n");
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
int *mas;


matr = rnd_matr (&n,&n);
printf("before\n");
print_matr ( matr, n,n);

flip_ma (matr,n);
printf("after\n");
print_matr ( matr, n,n);

mas = rnd_mas (&n);
printf("before\n");
print_mas ( mas,n);

sort (mas,n);
print_mas ( mas,n);

int ar[]={3,5,2,5,6,1,7,8,9,2,3}; 
n=sizeof(ar)/4;

_asm
{        mov ecx,n
	     dec ecx
loop1:   push ecx
	     mov esi,0
loop2:   mov eax,ar[esi]
          cmp eax,ar[esi+4]  
          jle then
          xchg eax,ar[esi+4]
          mov ar[esi],eax
  then:   add esi,4
	     loop  loop2
	     pop  ecx
         loop loop1        
 }

print_mas ( ar,n);
}

