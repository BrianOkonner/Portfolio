#include"QUEUE.h"
Queue::Queue()
{
	tail = 0;
	head = 0;
	i = 0;
}
Queue::~Queue()
{
	while (!empty())
		pop();
}
bool Queue::empty()
{
	if (tail == 0)
		return 1;
	return 0;
}
void Queue::push(int dat)
{
	if (empty())
	{
		Link* temp = new Link;
		temp->data = dat;
		temp->next = 0;
		temp->prev = 0;
		head = temp;
		tail = temp;
		i++;
	}
	else
	{
		Link* temp = new Link;
		temp->data = dat;
		temp->next = tail;
		temp->next->prev = temp;
		tail = temp;
		i++;
	}
}
void Queue::pop()
{
	if (tail == 0)
		return;
	Link* old = head;
	head = head->prev;
	/*if(i!=1)
		head->next=0;*/
	delete old;
	i--;
}
int Queue::front()
{
	if (!empty())
	{
		return head->data;
	}
}
int Queue::back()
{
	if (!empty())
	{
		return tail->data;
	}
}
int Queue::size()
{
	return i;
}
