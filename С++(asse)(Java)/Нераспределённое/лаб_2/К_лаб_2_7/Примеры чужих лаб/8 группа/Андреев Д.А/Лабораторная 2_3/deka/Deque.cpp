#include "deque.h"

Deque::Deque()
{
	head = 0;
	tail = 0;
}

Deque::Deque(const Deque&d)
{
	head = 0;
	tail = 0;
	node *temp = d.head;
	while (temp) {
		insTail(temp->item);
		temp = temp->next;
	}
}

void Deque::insÍead(int n)
{
	node*tmp = new node;
	tmp->next = 0;
	tmp->prev = 0;
	tmp->item = n;
	if (head == 0)
	{
		head = tail = tmp;
	}
	else
	{
		head->prev = tmp;
		tmp->next = head;
		head = tmp;
	}
}

void Deque::insTail(int n)
{
	node*tmp = new node;
	tmp->next = 0;
	tmp->prev = 0;
	tmp->item = n;
	if (head == 0)
	{
		head = tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
	}
}

int Deque::delHead()
{
	node *t = head->next;
	delete head;
	if (t == 0)
	{
		head = tail = 0;
	}
	else
	{
		t->prev = 0;
		head = t;
	}
	return t->item;
}
int Deque::delTail()
{
	node *t = tail->prev;
	delete tail;
	if (t == 0)
	{
		head = tail = 0;
	}
	else
	{
		t->next = 0;
		tail = t;
	}
	return t->item;
}

bool Deque::isEmpty()
{
	if (head == tail)
		return  true;
	return false;
}

Deque::~Deque()
{
	delete head;
	delete tail;
}