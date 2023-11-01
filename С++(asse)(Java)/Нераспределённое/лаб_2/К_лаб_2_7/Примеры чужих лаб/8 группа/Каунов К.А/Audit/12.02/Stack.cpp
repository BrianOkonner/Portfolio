#include <iostream>
#include "Stack.h"
using namespace std;


Stack::Link::Link(void* data, Link* next)
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

void* Stack::Top()
{
	if (!isEmpty())
		return head->data;
	return NULL;
}

void Stack::Push(void* dat)
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




