#pragma once
#include "Header.h"
class Deque		/* дек – двустороння очередь */
{
	struct node			/* элемент дека */
	{
		int  item;	/* данные */
		struct  node*  next;  /* указатель на следующий элемент */
		struct  node*  prev;  /* указатель на предыдущий элемент */
	};
	/* указатели на первый и последний элементы в списке */
	struct node *head, *tail;
public:
	Deque();			// конструктор
	Deque(const Deque& d);	// конструктор копирования
	~Deque();		/* деструктор */
	void insНead(int n);	/* включить элемент в голову дека */
	void insTail(int n);	/* включить элемент в хвост дека */
	int delHead();	      /* исключить элемент из головы дека */
	int delTail();	      /* исключить элемент из хвоста дека */
	bool isEmpty();		/* пустой дек? */
	void print(ostream&);
};


