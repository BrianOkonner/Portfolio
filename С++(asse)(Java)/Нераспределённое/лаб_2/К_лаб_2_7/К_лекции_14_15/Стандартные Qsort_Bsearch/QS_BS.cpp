
/*Функция qsort выполняют сортировку массива, элементы которого имеют
 произвольный тип. Эта функция реализует "быстрый алгоритм" сортировки
 массивов и имеет следующий прототип:

void  qsort(void *base, size_t n, size_t size, 
			int (*cmp) (const void *e1, const void *e2));
который описан в заголовочном файле stdlib.h. 
назначение параметров этой функции:
base	адрес массива,
n	количество элементов в массиве,
size	длина элемента массива,
cmp	указатель на функцию сравнения, которая возвращает:
-	отрицательное число, если элемент e1 меньше элемента e2;
-	0, если элемент e1 равен элементу e2;
-	положительное число, если элемент e1 больше элемента e2.

Функция bsearch выполняет бинарный поиск элемента в отсортированном массиве.
 Эта функция имеет следующий прототип:
 void*  bsearch(const void *key, const void *base,
     size_t n, size_t size, int (*cmp)(const void *ck, const void  *ce);

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

/* функция для сравнения элементов массива */
int comp_int(const int* e1, const int* e2)
{
	return *e1 - *e2;
}

/* программа сортировки элементов массива и поиска целого числа в отсортированном массиве */
int main()
{
	int  n;		/* размер массива */
	int* a;		/* массив */
	int  i;		/* индекс */
	int  k;		/* число для поиска */
	int* s;		/* адрес найденного числа */

	cout<<"Input an array size: ";
	cin>>n;
	a =  new int [n];

	/* вводим массив */
	cout<<"Input elements: ";
	for (i = 0; i < n; ++i)
		cin>>a[i];

	/* сортируем массив */
	qsort(a, n, sizeof(int), 
		(int (*)(const void*, const void*))comp_int);


	/* выводим отсортированный массив */
	cout<<"The sorted array: ";
	for (i = 0; i < n; ++i)
		cout<<a[i]<<' ';
	
	/* вводим число для поиска */
	cout<<endl<<"Input a number to search>";
	cin>>k;

	/* ищем это число в отсортированном массиве */
	if(!(s = (int*) bsearch(&k, a, n, sizeof(int), 
			(int (*)(const void*, const void*))comp_int)))
		cout<<"There is no such an integer"<<endl;
	else
		cout<<"The integer index = "<<s-a<<endl;
	free(a);

	return 0;
}
