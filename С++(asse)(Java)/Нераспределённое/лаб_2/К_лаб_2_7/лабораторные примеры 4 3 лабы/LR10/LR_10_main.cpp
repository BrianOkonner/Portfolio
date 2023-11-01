/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: B11.	Найти номера столбцов матрицы A=(aij) ,  i=1..n, j=1..m, (n,m<=100),
которые содержат наибольшее количество четных элементов.

Тесты:

n=7, m=4            Matrix:

6    1    5    2
9    5    2    4
1    8    2    1
2    2    5    9
8    8    0    9
3    8    8    4
0    0    8    5

Columns numbers:
2 3
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "LR10.h"
using namespace std;

int main(void)
{
	setlocale(LC_ALL, ".1251");
	unsigned int clk;
	unsigned int n, m, i, j;
	ifstream in;
	in.open("input.txt");
	cin >> n >> m;
	int *a;
	unsigned int *c;

	c = new unsigned int[m];
	a = new int[n*m];
	for ( i = 0; i<n; i++)
	{
		for ( j = 0; j<m; j++)
		{
			in >> a[i*m + j];
		}
	}

	/*srand(time(NULL));
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			a[i*m+j] = rand() % 10;
		}
	}*/
	for ( j = 0; j<m; j++)
	{
		c[j] = 0;
	}
	cout << "Matrix:" << endl << endl;
	for ( i = 0; i<n; i++)
	{
		for ( j = 0; j<m; j++)
		{
			cout << setw(5) << a[i*m+j];
		}
		cout << endl;
	}
	unsigned int m4 = m * 4;
	unsigned int temp_c;
	unsigned int counter = 0;
	_asm
	{
			mov ecx, m
			
			mov j,0
			mov edi, c	// j
		l1:	mov i,0
			mov esi, a	//mi+j = [i][j]	
			add esi, counter
			
		l2:	mov eax,i
			cmp eax, n
			jns label4
											/*mov temp_c, ecx
											mov ebx, [esi]
											push ebx
											call print
											pop ebx
											mov ecx, temp_c
											*/
			mov eax, [esi]
			test eax,1
			jnz label3
			inc [edi]

	label3:	add esi, m4
			inc i
			jmp l2
	label4: add edi,4
			add counter, 4
			loop l1
	}

	unsigned int max_e=c[0];

	_asm
	{
		 mov ecx, m
		 dec ecx
		 mov edi, c
		 add edi, 4
	l21: mov eax, [edi]
		 cmp eax, max_e
		 js lloop
		 mov max_e, eax
	lloop: add edi, 4
			loop l21
		
	}
	cout << "Columns numbers:" << endl;
	for (j = 0; j<m; j++)
	{
		if (c[j] == max_e)
			cout << j + 1 << " ";
	}
	cout << endl;

	
	delete[] a;

	clk = clock();
	cout << "Vremya vipolneniya: " << clk / 1000.0 << endl;
	return 0;
}
