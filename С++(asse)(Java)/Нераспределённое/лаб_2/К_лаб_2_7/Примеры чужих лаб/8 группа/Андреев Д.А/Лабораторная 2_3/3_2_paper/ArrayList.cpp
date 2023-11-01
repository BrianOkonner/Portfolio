#include <iostream>
#include <cstdio>
#include "ArrayList.h"
using namespace std;

List::node::node(int numb, node * next)
{
	this->item = numb;
	this->next = next;
}

List::node::~node() {}

List::List()
{
	head = NULL;
}

List::List(const List& lst)
{
	head->item = lst.head->item;
	head->next = lst.head->next;
}

bool List::isEmpty()
{
	return !head;
}


void List::push_head(int n)
{
	head = new node(n, head);
}



void List::push_back(int n)
{
	node *temp = new node(n, NULL);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		node* tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		tmp->next = temp;

	}
}


List::node* List::remove_head()
{
	if (!isEmpty())
	{
		node *temp = head;
		if (head->next)
			head = head->next;
		else
			head = NULL;
		delete temp;
	}
	return head;
}


List::node* List::remove_tail()
{
	if (head)
	{
		node* tmp = head;
		node *temp = head->next;
		while (temp->next != NULL)
		{
			tmp = tmp->next;
			temp = temp->next;
		}

		tmp->next = 0;
		node* a = temp;
		delete temp;
		return a;
	}
	return 0;
}

int List::front()
{
	return head->item;
}

List::~List() {

	while (head != 0)
		remove_head();
}


List::node* List::search()
{
	if (head)
	{
		node* tmp = head;
		while (tmp->next != NULL)
		{
			if (tmp->item % 2 == 0)
				return tmp;
			tmp = tmp->next;
		}
		return 0;
	}
	return 0;
}

void List::remove(node* adr)
{
	if (head)
	{
		node *temp = head;
		if (temp == adr)
		{
			head = head->next;
			delete temp;
		}
		else
		{
			while (temp->next && temp->next != adr)
				temp = temp->next;
			if (temp->next)
			{
				temp->next = adr->next;
				delete adr;
			}
			else
			{
				cout << "No element with this address" << endl;
			}
		}
	}
}

void List::print()
{
	if (head)
	{
		node* tmp = head;
		while (tmp)
		{
			cout << tmp->item << " ";
			tmp = tmp->next;
		}
	}
}

int List::remove(int pos)
{
	node* tmp = head;
	for (int i = 1; i <= pos - 1 && tmp->next; i++)
	{
		tmp = tmp->next;
	}
	if (tmp->next)
	{
		int res = tmp->next->item;
		node *tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		delete tmp2;
		return res;
	}
	return 0;
}

void List::delchet()
{
	if (head)
	{
		node *temp = head;
		while (temp && temp->next)
		{
			node *temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
			temp = temp->next;
		}
	}
}

int List::smin()
{
	if (head)
	{
		node *temp = head;
		int k = temp->item;
		while (temp->next)
		{
			temp = temp->next;
			if (temp->item < k)
				k = temp->item;
		}
		return k;
	}
	return 0;
}