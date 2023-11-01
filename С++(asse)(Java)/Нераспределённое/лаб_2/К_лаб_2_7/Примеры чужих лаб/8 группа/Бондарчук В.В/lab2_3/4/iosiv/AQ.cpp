#include<iostream>
#include "AQ.h"

using namespace std;
ArrayQueue:: ArrayQueue(int size)
{
	if (size < 0) { throw ; }
	else
	{
		this->size = size;
		p = new int[size];
		n = 0;
		head = 0;
		tail =0;
	}
}
ArrayQueue::ArrayQueue(const ArrayQueue& q)
{
	p = new int[q.size];
	size = q.size;
	n = q.n;
	head = q.head;
	tail = q.tail;
	for (int i = 0; i < n; i++)
	{
		p[i] = q.p[i];
	}
}
ArrayQueue::~ArrayQueue()
{
	delete[]p;
}
void ArrayQueue::push(int n)
{
	if (this->n < size)
	{
		p[tail] = n;
		(this->n)++;
		tail++;
		if (tail >= size) tail = 0;
	}
	else throw 1;
}
int ArrayQueue::del()
{
	if (n!=0)
	{
		int tmp = this->p[head];
		head++;
		if (head >= size) head = 0;
		n--;
		return tmp;
	}
	else throw 2;
		
}
int ArrayQueue::Size()
{
	return n;
}
bool ArrayQueue::isEmpty()
{
	return n == 0;
}
bool ArrayQueue::isFull()
{
	return n == size;
}
int ArrayQueue::top()
{
	return this->p[head];
}