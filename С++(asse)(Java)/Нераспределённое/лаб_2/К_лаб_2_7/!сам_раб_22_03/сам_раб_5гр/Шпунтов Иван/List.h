#pragma once
#include <iostream>
class Stack
{
	struct item	/* элемент списка */
	{
		int value;		 /* данные */
		item*  next;	 /* указатель на следующий элемент */
	};
public:
	item *first, *last;	 /* указатель на первый элемент в списке */

	Stack();             /* конструктор */
	Stack(const Stack&);   // конструктор копирования
	~Stack();	/* деструктор */

	bool isEmpty();	       /* пустой список? */
	void push_back(int);		//включить элемент в конец списка
	int remove_tail();		// исключить элемент из конца списка
	void print();		//Печать содержимого списка
	int size;
};
