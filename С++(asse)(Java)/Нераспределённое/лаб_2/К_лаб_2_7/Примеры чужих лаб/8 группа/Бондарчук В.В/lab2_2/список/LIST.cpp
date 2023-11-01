#include"LIST.h"
List::List()
{
	tail = 0;
	head = 0;
	i = 0;
}
List::~List()
{
	while (!empty())
		pop_front();
}
bool List::empty()
{
	if (tail == 0)
		return 1;
	return 0;
}
void List::push_back(int dat)
{
	if (empty())
	{
		Link* temp = new Link;
		temp->data = dat;
		temp->next = 0;
		temp->prev = 0;
		head = temp;
		tail = temp;
		i++;
	}
	else
	{
		Link* temp = new Link;
		temp->data = dat;
		temp->next = tail;
		temp->next->prev = temp;
		tail = temp;
		i++;
	}
}
void List::pop_front()
{
	if (tail == 0)
		return;
	Link* old = head;
	head = head->prev;
	delete old;
	i--;
}
int List::front()
{
	if (!empty())
	{
		return head->data;
	}
}
int List::back()
{
	if (!empty())
	{
		return tail->data;
	}
}
int List::size()
{
	return i;
}
void List:: push_front(int dat)
{
	if (empty())
	{
		Link* temp = new Link;
		temp->data = dat;
		temp->next = 0;
		temp->prev = 0;
		head = temp;
		tail = temp;
		i++;
	}
	else
	{
		Link* temp = new Link;
		temp->data = dat;
		temp->prev = head;
		temp->prev->next = temp;
		head = temp;
		i++;
	}
}
void List::pop_back()
{
	if (tail == 0)
		return;
	Link* old = tail;
	tail = tail->next;
	delete old;
	i--;
}
