#include "ArrayQueue.h"
#include "Header.h"


ArrayQueue::ArrayQueue(int size)
{
	p = new int[size];
	head = n = 0;
	this->size = size;
}


ArrayQueue::~ArrayQueue()
{
	delete[] p;
}
ArrayQueue::ArrayQueue(const ArrayQueue& q)  // конструктор копирования
{
	p = new int[q.size];
	size = q.size;
	n = q.n;
	for (int i = 0; i < size; i++)
	{
		p[i] = q.p[i];
	}
}
void ArrayQueue::push(int n)
{
	p[head++] = n;
	this->n++;
}
int ArrayQueue::del()
{
	n--;
	return p[head--];
}

bool ArrayQueue::isEmpty()
{
	if (head == 0) return true;
	else return false;
}
bool ArrayQueue::isFool()
{
	if (head == 0) return false;
	else return true;
}
void ArrayQueue::printQueue(ostream&out)
{	
	for (int i = 0; i < head; i++)
		out << p[i] << "   ";
	out << endl;
}