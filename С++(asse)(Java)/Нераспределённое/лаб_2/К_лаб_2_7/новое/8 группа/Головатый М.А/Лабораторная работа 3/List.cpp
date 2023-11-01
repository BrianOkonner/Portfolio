#include "list.h"
#include <iostream>
using namespace std;
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
void List::push_head(int n)
{
	node *tmp =new node;
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
void List::push_back(int n)
{
	node *q = head;
	node *t = new node;
	t->item = n;
	t->p = NULL;

	while (true)
	{
		if (q->p==nullptr)
		{
			q->p = t;
			break;
		}
		q = q->p;
	}
}
List::node*List::remove_tail()
{
	node *q = head;
	
	while (true)
	{
		if (q->p->p == nullptr)
		{
			q->p = nullptr;
			break;
		}
		q = q->p;
	}
	return nullptr;
}
void List::delchet()
{
		node *tmp, *current;
		for (tmp = head; tmp && tmp->p; tmp = tmp->p)
		{
			current = tmp->p;
			tmp->p = current->p;
			delete current;
		}
}

void List::print()
{
	for (node *tmp = head; tmp; tmp = tmp->p)
	{
		cout << tmp->item << " ";
	}
	cout << endl;
}

bool List::isEmpty()
{
	return head;
}
int List::del()
{
	try
	{
		if (!head)
		{
			throw 1;
		}
	}
	catch (...)
	{
		cout << "Error. List is empty." << endl;
		return 0;
	}
	node *current = head;
	head = head->p;
	//int a = current->item;
	delete current;
}
List::node* List::remove_head()
{
	try
	{
		if (!head)
		{
			throw 1;
		}
	}
	catch (...)
	{
		cout << "Error. List is empty." << endl;
		return 0;
	}
	
	node *current = head;
	remove(current);
	//head = head->p;
	//int a = current->item;
	//delete current;
	return nullptr;
}
List::node* List::search()
{
	node *tmp;
	for (tmp = head; tmp; tmp = tmp->p)
	{
		if (tmp->item % 2 == 0)
		{
			cout << "ѕервый чЄтный: " << tmp->item;
			return tmp;
		}
	}
	return nullptr;
}

int List::remove(int pos)
{
	node *tmp = head, *current;
	if (pos == 1)
	{
		return remove_head()->item;
	}
	for (int i = 1; i < pos - 1; i++, tmp = tmp->p);
	int a = tmp->p->item;
	current = tmp->p;
	tmp->p = current->p;
	delete current;
	return a;
}

void List::remove(node*adr)
{
	node *tmp = head, *current;
	if (adr==head)
	{
		node *current = head;
		head = head->p;
		delete current;
		//remove_head();
		return;
	}
	node* i;
	for (i = head; i > adr; i = i->p);
	current = i->p;
	i->p = current->p;
	delete current;
}
int List::smin()
{
	node *tmp;
	int a = head->item;
	for (tmp = head->p; tmp; tmp = tmp->p)
	{
		if (a > tmp->item)
		{
			a = tmp->item;
		}
	}
	return a;
}
//
void List::invert()
{
	int N = 10;
	node *tmp1 = head, *tmp2 = head->p, *tmp3 = head->p->p;
	for (int i = 0; i < N / 2 - 1; i++)
	{
		tmp2->p = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp3;
		tmp3 = tmp3->p;
	}
	head->p = tmp2;
	head = tmp1;
}