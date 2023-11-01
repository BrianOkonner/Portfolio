#pragma once
#include <iostream>
class List
{
	struct item	/* элемент списка */
	{
		int value;		 /* данные */
		item*  next;	 /* указатель на следующий элемент */
	}*first, *last;
public:
	//item *first, *last;	 /* указатель на первый элемент в списке */

	List();             /* конструктор */
	List(const List&);   // конструктор копирования
	~List();	/* деструктор */

	bool isEmpty();	       /* пустой список? */
	void push_head(int);		//включить элемент в начало списка
	void push_back(int);		//включить элемент в конец списка
	int remove_head();		// исключить элемент из начала списка
	int remove_tail();		// исключить элемент из конца списка
	void print();		//Печать содержимого списка
	int size;
	int front() { return first->value; }
	int back() { return last->value; }
};