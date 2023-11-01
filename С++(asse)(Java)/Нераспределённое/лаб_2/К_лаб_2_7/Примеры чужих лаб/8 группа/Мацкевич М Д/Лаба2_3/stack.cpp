
#include "stack.h"

ArrayStack::ArrayStack(const int& size)
{
	p = new int[size];
	this->size = size;
	top = 0;
}
ArrayStack::ArrayStack(const ArrayStack& s)
{
	size = s.size;
	p = new int[s.size];
	top = s.top;
		for (int i = 0; i < size; i++)
			p[i] = s.p[i];
}
ArrayStack::~ArrayStack()
{
	delete[] p;
	top=0;
}

void ArrayStack::push(const int& n)
{
	p[top++] = n;
}
int ArrayStack::pop()
{
	return p[--top];
}
bool ArrayStack::isEmpty()
{
	if (!top) return 1;
	else  return 0;
}

bool ArrayStack::isFull()
{
	if (top == size) return 1;
	else             return 0;
}
