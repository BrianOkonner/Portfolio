#include "stdafx.h"
struct list
{
	int item;
	list *next;
	list *prev;
	bool isEmpty()
	{
		return (head == NULL)||(tail == NULL) ? true : false;
	}
	void init()
	{
		head = NULL;
		tail = NULL;
	}
	void push_in_head(int tmp)
	{
		list *temp;
		temp = new list;
		temp->item = tmp;
		temp->next = head;
		temp->prev = NULL;
		if (!head->isEmpty())
		{
			head->prev = temp;
			head = temp;
		}
		else 
		{
			head = temp;
			tail = head;
		}
	}
	void push_in_tail(int tmp)
	{
		list *temp;
		temp = new list;
		temp->item = tmp;
		temp->prev = tail;
		temp->next = NULL;
		if (!tail->isEmpty())
		{
			tail->next = temp;
			tail = temp;
		}
		else
		{
			tail = temp;
			head = tail;
		}
	}
	int pop_out_head ()
	{
		if (head->isEmpty())
			return -2148000;
		list *temp;
		int out;
		out = head->item;
		if (head->next != NULL)
			head->next->prev = NULL;
		temp = head;
		head = head->next;
		if (head->isEmpty())
			tail = head;
		delete temp;
		return out;
	}
	int pop_out_tail ()
	{
		if (tail->isEmpty())
			return -2148000;
		list *temp;
		int out;
		out = tail->item;
		if (tail->prev != NULL)
			tail->prev->next = NULL;
		temp = tail;
		tail = tail->prev;
		if (tail->isEmpty())
			head = tail;
		delete temp;
		return out;
	}
} *head, *tail;