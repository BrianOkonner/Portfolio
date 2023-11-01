#include "Deque.h"

Deque::Deque()
{
	head = nullptr;
	tail = nullptr;
}

Deque::Deque(const Deque&d)
{

}
Deque::~Deque()
{
	delete head;
	delete tail;
}
bool Deque::isEmpty()
{
	return (head == tail) ? 1 : 0;
}
void Deque::insTail(int n)
{
	node*it = new node;
	it->next = nullptr;
	it->prev = nullptr;
	it->item = n;
	if (tail == 0)
	{
		head = tail = it;
	}
	else
	{
		tail->next = it;
		it->prev = tail;
		tail = it;
	}
}
void Deque::insÍead(int n)
{
	node*it = new node;
	it->next = nullptr;
	it->prev = nullptr;
	it->item = n;
	if (head == 0)
	{
		head = tail = it;
	}
	else
	{
		head->prev = it;
		it->next = head;
		head = it;
	}
}
int Deque::delHead()
{
	node *it = head->next;
	delete head;
	if (it == 0)
	{
		head = tail = 0;
	}
	else
	{
		it->prev = 0;
		head = it;
	}
	return it->item;
}
int Deque::delTail()
{
	node *it = tail->prev;
	delete tail;
	if (it == 0)
	{
		head = tail = 0;
	}
	else
	{
		it->next = 0;
		tail = it;
	}
	return it->item;
}
void Deque::print(ostream&)
{
	for (node *tmp = tail; tmp; tmp = tmp->prev)
	{
		cout << tmp->item << " ";
	}
	cout << endl;
}