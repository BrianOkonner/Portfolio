#include "ArrayQueue.h"
ArrayQueue::ArrayQueue(int _size)
{
	p=new int[_size];
	head=0;
	n=0;
	size=_size;
}
ArrayQueue::ArrayQueue(const ArrayQueue& q)
{
	p=new int[q.size];
	head=q.head;
	n=q.n;
	size=q.size;
	for (int i=0;i<n;i++)
	{
		p[i] = q.p[i];
	}
}
ArrayQueue::~ArrayQueue()
{
	head=0;
	n=0;
	size=0;
	delete p;
}
void ArrayQueue::push(int _n)
{
	if(n==size)
		throw 1;
	if(!head)
	{
		p[0]=_n;
		head++;
	}
	else
		if(head+n>size)
		{
			p[head+n-size]=_n;
		}
		else
			p[n+head-1]=_n;
	n++;
}
int ArrayQueue::del()
{
	if(head==0)
		throw 2;
	int np=p[head-1];
	p[head-1]=0;
	if(head==size)
		head=0;
	head++;
	n--;
	return np;
}
bool ArrayQueue::isEmpty()
{
	if(head==0)
		return 1;
	else 
		return 0;
}
bool ArrayQueue::isFool()
{
	if(n==size)
		return 1;
	else 
		return 0;
}