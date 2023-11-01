#pragma once
using namespace std;

class List 
{										/* список однонаправленный						*/
public:
	struct node 
	{								/* элемент списка								*/
		int item;								/* данные										*/
		struct node*  next;						/* указатель на следующий элемент				*/
	};
	struct node *head;							/* указатель на первый элемент в списке			*/

	List();							            /* конструктор									*/
	List(const List& lst);						/* конструктор копирования						*/
	~List();									/* деструктор									*/
	bool isEmpty();								/* пустой список?								*/
	int size();
	//Дополнительно 
	void push_head(int n);						/* включить элемент в начало списка				*/
	void push_back(int n);						/* включить элемент в конец списка				*/
	node* remove_head();						/* исключить элемент из начала списка			*/
	node* remove_tail();						/* исключить элемент из конца списка			*/
	int top();	
};