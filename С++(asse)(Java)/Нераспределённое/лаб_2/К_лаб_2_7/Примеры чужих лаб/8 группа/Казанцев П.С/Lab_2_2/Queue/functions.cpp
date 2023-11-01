#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Header.h"
MyQueue::item::item(int numb, item * next)
{
	this->number = numb;
	this->next = next;
}

MyQueue::item::~item(){}

MyQueue::MyQueue()
{
	this->head = NULL;
	this->tail = NULL;
}

bool MyQueue::isEmpty()
{
	return !head;
}

void MyQueue::push(int numb)
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


void MyQueue::pop()
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

int MyQueue::front()
{
	if (!isEmpty())
		return this->head->number;
	return NULL;
}

int MyQueue::back()
{
	if (!isEmpty())
		return this->tail->number;
	return NULL;
}

bool MyQueue::queue_search(int numb)
{
	item *tmp = this->head;
	while (tmp != NULL)
	{
		if (tmp->number == numb)
			return true;
		tmp = tmp->next;
	}
	return false;
}

MyQueue::~MyQueue()
{
	while (!isEmpty())
		pop();
}
int is_simple(int x)    // Проверка числа на простоту
{
	int flag, d;
	if (x == 2 || x == 3)
		flag = 1;
	else
	{
		d = 2; flag = 1;
		while ((d <= x / 2) && (flag))
		{
			if (!(x % d))
				flag = 0;
			else
				d++;
		}
	}
	return flag;
}

int is_palindrome(int x)
{
	int flag = 1;
	char s[33];
	sprintf(s, "%d", x);
	int length = strlen(s);
	for (int i = 0; i < length / 2; i++)
	{
		if (s[i] != s[length - i - 1])
			flag = 0;
	}
	return flag;
}

