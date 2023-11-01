#include"Header.h"
#include<iostream>
using namespace std;


List::List()
{
	head = tail = 0;
}

void List::del_nech() 
{
	node* temp = head;
	while (temp != NULL) 
	{
		if (temp->_item & 1) 
		{
			if (temp == head)
			{
				head = head->next;
				delete temp;
				temp = head;
				head->prev = NULL;
			}
			else
			{
				if (temp == tail) 
				{
					tail = tail->prev;
					delete temp;
					temp = NULL;
					tail->prev = NULL;
				}
				else
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					node* a = temp->next;
					delete temp;
					temp=a;
				}
			}
		}
		else 
		{
			temp = temp->next;
		}
	}
}

List::~List()
{
	node *tmp = head;
	while (tmp != 0)
	{
		node *tmp1 = tmp;
		tmp = tmp->next;
		delete tmp1;
	}
	head = 0;
	tail = 0;
}

void List::insTail(int n)
{
	node* tmp = new node();
	tmp->_item = n;
	tmp->next = NULL;
	tmp->prev = tail;
	if (tail)
		tail->next = tmp;
	else
		tail = tmp;
	head = tmp;
}

void List::insÍead(int n)
{
	node* tmp = new node;
	tmp->_item = n;
	tmp->prev = NULL;
	tmp->next = head;
	if (head)
	{
		node* tmp1 = head;
		tmp1->prev = tmp;
	}
	else
		tail = tmp;
	head = tmp;
}

int List::delHead()
{
	if (head)
	{
		int res = head->_item;
		node *tmp = head;
		if (head->next)
			head->next->prev = 0;
		else
			tail = 0;
		head = head->next;
		delete tmp;
		return res;
	}
	return NULL;
}


int List::delTail()
{
	if (tail)
	{
		int res = tail->_item;
		node *tmp = tail;
		if (tail->prev)
			tail->prev->next = 0;
		else
			head = 0;
		tail = tail->prev;
		delete tmp;
		return res;
	}
	return 0;
}



bool List::isEmpty()
{
	if (head == 0)
		return true;
	else
		return false;
}

bool nechet(int x)
{
	if ((x % 2) == 0)
		return false;
	else
		return true;
}