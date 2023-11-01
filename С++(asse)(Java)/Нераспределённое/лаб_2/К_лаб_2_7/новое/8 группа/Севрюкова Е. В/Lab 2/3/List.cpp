#include <iostream>
#include <cstdio>
#include "List.h"
using namespace std;

List::item::item(int numb, item * next, item * prev)
{
	this->number = numb;
	this->next = next;
	this->prev = prev;
}

List::item::~item() {}

List::List()
{
	this->head = NULL;
	this->tail = NULL;
}

bool List::empty()
{
	return !head;
}

void List::push_back(int numb)
{
	item *temp = new item(numb, NULL, NULL);
	if (this->head == NULL)
	{
		this->head = temp;
		this->tail = temp;
	}
	else
	{
		this->tail->next = temp;
		this->tail = temp;
	}
}


void List::pop_front()
{
	if (!empty())
	{
		item *temp = this->head;
		if (this->head->next)
			this->head = this->head->next;
		else
			this->head = NULL;
		delete temp;
	}
}

int List::front()
{
	if (!empty())
		return this->head->number;
	return NULL;
}


List::~List()
{
	while (!empty())
		pop_front();
}