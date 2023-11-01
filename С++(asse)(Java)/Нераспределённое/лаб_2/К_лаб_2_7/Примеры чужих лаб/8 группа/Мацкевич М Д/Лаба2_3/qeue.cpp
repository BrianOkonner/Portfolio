#include "queue.h"

ArrayQueue::ArrayQueue(int size)
{
	this->size = size;
	p = new int[size];
	n = 0;
	head = -1;
}

ArrayQueue::ArrayQueue(const ArrayQueue& q)
{   int t=q.head;
	int i;
	size = q.size;
	p = new int[size];
	n = q.n;
    
		for ( i = n-1; i>=0; i--)
		{if (t<0) t+=size;
	     p[i]=q.p[t--];	
		}
 head=n-1;
}


ArrayQueue::~ArrayQueue()
{
	delete[] p;
	n = 0;
	head = -1;
}

void ArrayQueue::push(int n)/* втолкнуть элемент в очередь */
{
	if (this->n != size)
	{
		this->n++;
		if (head == size - 1) head = 0;
		else head++;
		p[head] = n;
	}
	else cout<< "Perepolnenie";
}

int ArrayQueue::del()
{
	if (n) 
	{
		n--;
		if (head - n >= 0) return p[head - n]; 
		else               return p[head + size - n];
	}
	else cout << "empty";
	return 0;
}

bool ArrayQueue::isEmpty()
{
	if (n) return 0;
	else  return 1;
}

bool ArrayQueue::isFool()
{
	if (n == size) return 1;
	else return 0;
}