#include <iostream>
#include <cstdio>
#include "Queue.h"
using namespace std;

Queue::item::item(int numb, item * next)
{
	this->number = numb;
	this->next = next;
}

Queue::item::~item(){}

Queue::Queue()
{
	this->head = NULL;
	this->tail = NULL;
}

bool Queue::isEmpty()
{
	return !head;
}

void Queue::push(int numb)
{
	item *temp = new item(numb, NULL);
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


void Queue::pop()
{
	if (!isEmpty())
	{
		item *temp = this->head;
		if (this->head->next)
			this->head = this->head->next;
		else
			this->head = NULL;
		delete temp;
	}
}

int Queue::front()
{
	if (!isEmpty())
		return this->head->number;
	return NULL;
}


Queue::~Queue()
{
	while (!isEmpty())
		pop();
}



