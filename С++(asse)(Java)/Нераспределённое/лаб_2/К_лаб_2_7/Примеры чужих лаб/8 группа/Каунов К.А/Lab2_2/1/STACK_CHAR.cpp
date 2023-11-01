#include"STACK_CHAR.h"
#include<iostream>
STACK_C::STACK_C()
{
	head = 0;
}
STACK_C::~STACK_C()
{
	while (!empty())
		pop();
}
bool STACK_C::empty()
{
	if (head == 0)
		return 1;
	return 0;
}
void STACK_C::push(char dat)
{
	Link* temp = new Link;
	temp->data = dat;
	temp->prev = head;
	head = temp;
}
void STACK_C::pop()
{
	if (head == 0)
		return;
	Link* old = head;
	head = head->prev;
	delete old;
}
char STACK_C::top()
{
	if (head == 0)
		return 0;
	char temp = head->data;
	return temp;
}
