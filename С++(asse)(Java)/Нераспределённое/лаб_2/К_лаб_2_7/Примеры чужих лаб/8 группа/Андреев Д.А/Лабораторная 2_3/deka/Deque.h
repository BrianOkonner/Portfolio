#pragma once
#include <iostream>
using namespace std;

class Deque						/* дек – двустороння очередь */
{
	struct node					/* элемент дека */
	{
		int  item;				/* данные */
		struct  node*  next;	/* указатель на следующий элемент */
		struct  node*  prev;	/* указатель на предыдущий элемент */
	};
	struct node *head, *tail;	/* указатели на первый и последний элементы в списке */

public:
	Deque();					// конструктор
	Deque(const Deque& d);		// конструктор копирования
	~Deque();					/* деструктор */
	void insНead(int n);		/* включить элемент в голову дека */
	void insTail(int n);		/* включить элемент в хвост дека */
	int delHead();				/* исключить элемент из головы дека */
	int delTail();				/* исключить элемент из хвоста дека */
	bool isEmpty();				/* пустой дек? */
};