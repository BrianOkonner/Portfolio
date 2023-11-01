#include <iostream>
#include "Stack.h"
using namespace std;


Stack::Link::Link(char data, Link* next)
{
	this->data = data;
	this->next = next;
}


Stack::Link:: ~Link() {}


Stack::Stack()
{
	head = NULL;
}

bool Stack::isEmpty()
{
	return !head;
}

char Stack::Peek()
{
	if (!isEmpty())
		return head->data;
	return NULL;
}

void Stack::Push(char dat)
{
	head = new Link(dat, head);
}
void Stack::Pop()
{
	if (!isEmpty())
	{
		Link* tmp = head;
		if (head->next)
			head = head->next;
		else head = NULL;
		delete tmp;
	}
}

Stack::~Stack()
{
	while (!isEmpty())
		Pop();
}

//--------------------------------------------------------------------

StackInt::Link::Link(int data, Link* next)
{
	this->data = data;
	this->next = next;
}

StackInt::Link:: ~Link() {}

StackInt::StackInt()
{
	head = NULL;
}

bool StackInt::isEmpty()
{
	return !head;
}

int StackInt::Peek()
{
	if (!isEmpty())
		return head->data;
	return NULL;
}

void StackInt::Push(int dat)
{
	head = new Link(dat, head);
}
void StackInt::Pop()
{
	if (!isEmpty())
	{
		if (head == 0)return;
		Link* tmp = head;
		if (head->next)
			head = head->next;
		else head = NULL;
		delete tmp;
	}
}

StackInt::~StackInt()
{
	while (!isEmpty())
		Pop();
}