#include <iostream>
#include "stack.h"
using namespace std;


MyStack::Link::Link(void* data, Link* next)
{
	this->data = data;
	this->next = next;
}

MyStack::Link:: ~Link() {}

MyStack::MyStack()
{
	head = NULL;
}

bool MyStack::isEmpty()
{
	return !head;
}

void* MyStack::Top()
{
	if (!isEmpty())
		return head->data;
	return NULL;
}

void MyStack::Push(void* dat)
{
	head = new Link(dat, head);
}
void MyStack::Pop()
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

MyStack::~MyStack()
{
	while (!isEmpty())
		Pop();
}