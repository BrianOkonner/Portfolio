#include "Queue.h"
#include <stddef.h>
#include <iostream>

Queue::Queue()
{
	this->head = NULL;
	this->tail = NULL;
}

Queue::~Queue()
{
	delete this->head;
	delete this->tail;
}

void Queue::push(int n)
{
	queue* tmp = new queue();
	tmp->data=n;
	tmp->next = NULL;
	if(this->head == NULL)
	{
		this->head = tmp;
		this->tail = head;
	}
	else
	{
	this->tail->next = tmp;
	this->tail = tmp;
	this->tail->next=NULL;
	}
}

int Queue::pop()
{
	
	queue* tmp = this->head;
	int tdata = this->head->data;
	this->head = this->head->next;
	delete tmp;
	
	return tdata;
}

bool Queue::isEmpty()
{
	return this->head == NULL;
}

