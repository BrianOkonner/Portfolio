#pragma once
class List		/* список однонаправленный*/
{
	//public:
	struct node	/* элемент списка */
	{
		int item;		     /* данные */
		struct node*  next;	 /* указатель на следующий элемент */
		node(int, node *);
		~node();
	};
	struct node *head;

public:
	List();	                 /* конструктор*/
	List(const List& lst);   /* конструктор копирования*/
	~List();	             /* деструктор */
	bool isEmpty();	         /* пустой список? */

	void push_head(int n);
	void push_back(int n);   //включить элемент в конец списка
	node* remove_head();	 // исключить элемент из начала списка
	node* remove_tail();	 // исключить элемент из конца списка
	int front();
	node* search();          // найти элемент первый четный
	void remove(node* adr);	 // удалить элемент c адресом  adr
	void print();            //Печать содержимого списка
	int remove(int pos);
	void delchet();		     //Удаление с четными номерами
	int smin();		    	 //Поиск min

};