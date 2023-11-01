#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

void Queue::Add(int n)
	{
		node* temp = new node(n);
		if (tail == NULL)
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		count++;
	}

int Queue::Count ()
	{
		return count;
	}


void Queue::Insert (int ind, int val)
	{
		if (ind >= count)
			throw "Invalid index.";
		node* tmp = Get(ind);
		node* newNode = new node(val);
		newNode->next = tmp;
		newNode->prev = tmp->prev;
		tmp->prev = newNode;
	}

Queue::node* Queue::Get (int ind)
	{
		if (ind >= count)
			throw "Invalid index.";
		node* cur = head;
		for (int i = 0; i < ind; i++)
			cur = cur->next;

		return cur;
	}