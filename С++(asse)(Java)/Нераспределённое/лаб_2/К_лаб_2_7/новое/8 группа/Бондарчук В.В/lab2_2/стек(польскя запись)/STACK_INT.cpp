#include"STACK_INT.h"
#include<iostream>
STACK_I::STACK_I()
{
	head = 0;
}
STACK_I::~STACK_I()
{
	while (!empty())
		pop();
}
bool STACK_I::empty()
{
	if (head == 0)
		return 1;
	return 0;
}
void STACK_I::push(int dat)
{
	Link* temp = new Link;
	temp->data = dat;
	temp->prev = head;
	head = temp;
}
void STACK_I::pop()
{
	if (head == 0)
		return;
	Link* old = head;
	head = head->prev;
	delete old;
}
char STACK_I::top()
{
	if (head == 0)
		return 0;
	int temp = head->data;
	return temp;
}
