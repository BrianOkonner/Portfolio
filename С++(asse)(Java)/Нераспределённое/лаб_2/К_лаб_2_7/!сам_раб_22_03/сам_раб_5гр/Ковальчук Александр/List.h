#pragma once
#include <iostream>
class List
{
	struct item	/* элемент списка */
	{
		int value;		 /* данные */
		item*  next;	 /* указатель на следующий элемент */
	};
	item *first, *last;	 /* указатель на первый элемент в списке */
	int size;
public:

	List();             /* конструктор */
	List(const List&);   // конструктор копирования
	~List();	/* деструктор */

	bool isEmpty();	       /* пустой список? */
	void push_head(int);		//включить элемент в начало списка
	void push_back(int);		//включить элемент в конец списка
	int remove_head();		// исключить элемент из начала списка
	int remove_tail();		// исключить элемент из конца списка
	int search();		// найти элемент первый четный
	void print();		//Печать содержимого списка
	int remove(int); //Удаляет на позиции
	void delchet();		//Удаление с четными номерами
	int smin();	    	//Поиск min
	void invert();		//инвертировать элементы первой половины списка
	int s() { return size; }
};
