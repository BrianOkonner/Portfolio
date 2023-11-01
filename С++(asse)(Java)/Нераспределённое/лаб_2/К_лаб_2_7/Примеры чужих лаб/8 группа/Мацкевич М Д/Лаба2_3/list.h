#include <iostream>
using namespace std;
class List		/* список однонаправленный*/
{
	struct node	/* элемент списка */
	{
		int item;		 /* данные */
		struct node*  p;	 /* указатель на следующий элемент */
	};
	struct node *head;	 /* указатель на первый элемент в списке */
public:
	List();	             /* конструктор */
	List(const List& lst);   // конструктор копирования
	~List();	             /* деструктор */
	void ins(const int& n);  /* включить элемент в список */
	int del();		       /* исключить элемент из списка */
	bool isEmpty();	       /* пустой список? */
};