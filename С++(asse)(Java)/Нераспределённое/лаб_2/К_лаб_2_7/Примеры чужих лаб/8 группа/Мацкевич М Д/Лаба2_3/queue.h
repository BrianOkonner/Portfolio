#include <iostream>
using namespace std;
class ArrayQueue		/* кольцевая очередь на массиве */
{
	int	size;		/* размерность массива */
	int*	p;		/* указатель на массив */
	int	head;		/* индекс первого занятого элемента */
	int	n;		/* количество элементов в очереди */
public:
ArrayQueue(int size);	/* инициализация очереди */
ArrayQueue(const ArrayQueue& q);  // конструктор копирования
~ArrayQueue();	/* разрушить очередь */
void push(int n);/* втолкнуть элемент в очередь */
int del();		/* удалить элемент из очереди */
bool isEmpty();	/* пустая очередь? */
bool isFool();	/* полная очередь? */
};
