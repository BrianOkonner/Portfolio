#include "queue.h"

ArrayQueue::ArrayQueue(int _size)
{
	size = _size;
	p = new int[size];
	head = 0;
	n = 0;
}

ArrayQueue::ArrayQueue(const ArrayQueue& q)
{
	size = q.size;
	head = q.head;
	n = q.n;
	p = new int[size];
	for (int i = 0; i<n; i++)
	{
		p[i] = q.p[i];
	}
}
ArrayQueue::~ArrayQueue()
{
	size = 0;
	head = 0;
	tail = 0;
	n = 0;
	delete[] p;
	p = NULL;
}


bool ArrayQueue::isFull()
{
	if (n == (size))
		return true;
	return false;
}

bool ArrayQueue::isEmpty()
{
	if (n == 0)
		return true;
	return false;
}

void ArrayQueue::push(int _n)
{
	p[(head + n)>size ? (head + n) % size : head + n] = _n;
	n++;
}

void ArrayQueue::push_head(int _n)
{
	for (int i = head + 1; i <= n; i++)
	{
		p[i] = p[i - 1];
	}
	p[head] = _n;
	n++;
}

int ArrayQueue::del()
{
	if (!isEmpty())
	{
		int t = p[head];
		n--;
		head++;
		head %= (size);
		return t;
	}
	return 0;
}

int  ArrayQueue::front()
{
	return p[head];
}