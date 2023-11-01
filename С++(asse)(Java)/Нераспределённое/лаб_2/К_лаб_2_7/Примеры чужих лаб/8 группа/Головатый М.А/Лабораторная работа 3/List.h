#pragma once
class List		/* список однонаправленный*/
{
	struct node	/* элемент списка */
	{
		int item;		 /* данные */
		struct node*  p;
								/* указатель на следующий элемент */
	};
	struct node *head;			/* указатель на первый элемент в списке */
public:
	List();						/* конструктор */
	List(const List& lst);		// конструктор копирования
	~List();					/* деструктор */
	//чем отличается от push_head?
	void ins(const int& n);		/* включить элемент в список */
	//чем отличается от remove_head?
	int del();					/* исключить элемент из списка */
	bool isEmpty();				/* пустой список? */
 //Дополнительно
	void push_head(int n);		//включить элемент в начало списка
	void push_back(int n);		//включить элемент в конец списка
	node* remove_head();		// исключить элемент из начала списка
	node* remove_tail();		// исключить элемент из конца списка
	node* search();				// найти элемент первый четный
	void remove(node* adr);		// удалить элемент c адресом  adr
	void print();				//Печать содержимого списка
	int remove(int pos);		//исключить  заданный элемент
	void delchet();				//Удаление с четными номерами
	int smin();		    		//Поиск min
	void invert();				//инвертировать элементы первой половины списка
};
