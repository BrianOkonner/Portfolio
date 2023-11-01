#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class ArrayQueue		/* кольцевая очередь на массиве */
{
	int	size;			/* размерность массива */
	int*	p;			/* указатель на массив */
	int	head;			/* индекс первого занятого элемента */
	int tail;			/* индекс последнего занятого элемента */
	int	n;				/* количество элементов в очереди */
public:
	ArrayQueue(int size);				/* инициализация очереди */
	ArrayQueue(const ArrayQueue& q);	// конструктор копирования
	~ArrayQueue();						/* разрушить очередь */
	void push(int _n);					/* втолкнуть элемент в очередь */
	void push_head(int _n);
	int del();							/* удалить элемент из очереди */
	bool isEmpty();						/* пустая очередь? */
	bool isFull();						/* полная очередь? */
	int front();
};
