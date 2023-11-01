/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: 5.	Задана целочисленная последовательность A=(ai), i=1..n, n<=100.
Назовем серией группу подряд идущих одинаковых элементов,
а длиной серии — количество этих элементов (длина серии может быть равна 1).
Вывести массив, содержащий длины всех серий исходного массива.

Алгоритм:
Для каждого а[i] в b[i] записываем длину текущей серии.

Тесты:
Условие         Полученый вывод

Initial massive:
4 9 2 5 3 3 2 7 4 6 2 1 9 2 2
Massiv serii
1 1 1 1 1 2 1 1 1 1 1 1 1 1 2

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include "LR9.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	unsigned int clk;
	int i,c=1,j=0,n;
	cin >> n;
	cout << "n = " << n << endl;
	int a[101], b[101];
	srand(time(NULL));
	cout << "Initial massive:" << endl;
	for (i = 0; i < n;i++)
	{
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}

	cout << endl << "Massiv serii" << endl;
	_asm
	{
			mov esi,0					//i
			mov edi,0					//j
			mov ecx,n
	begin1:	mov eax, c					//
			mov b[edi],eax				// b[j++]=c;
			mov eax, a[esi]				//a[i-1]
			add esi,4
			mov ebx, a[esi]				//a[i]
			cmp ebx,eax
			jne label1
			inc c
			jmp end1
	label1:	mov c,1
	end1:	add edi,4
			loop begin1
			mov eax,c
			mov b[edi],eax
			add edi,4					//b[j++]=c;
			mov b[edi],0				//b[j]=0;
			mov j,0						//j=0;
			mov edi,j
			mov ecx,n
	begin2: cmp b[edi],0
			je end2
			push ecx
			push b[edi]
			call print
			pop b[edi]
			pop ecx
			add edi,4
			loop begin2
	end2:
	}

	clk = clock();
	cout << endl << "Vremya vipolneniya: " << clk / 1000.0 << endl;
	return 0;
}
