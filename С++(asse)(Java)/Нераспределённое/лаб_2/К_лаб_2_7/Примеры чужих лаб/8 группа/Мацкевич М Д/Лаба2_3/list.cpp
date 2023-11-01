#include "list.h"
List::List()
{
	head = nullptr;
}

List::List(const List &lst)
{
	head = lst.head;
}

List::~List()
{
	while (head)
	{
		node *current = head;
		head = head->p;
		delete current;
	}
}
void List::ins(const int&n)
{
	node *tmp = new node;
	tmp->item = n;
	if (head)
	{
		tmp->p = head;
		head = tmp;
	}
	else
	{
		head = tmp;
		head->p = nullptr;
	}
}
int List::del()
{
		if (!head)
		{
		cout << "Error. List is empty." << endl;
		return 0;
      	}
	node *current = head;
	head = head->p;
	int a = current->item;
	return a;
	delete current;
}
bool List::isEmpty()
{
	return !head;
}