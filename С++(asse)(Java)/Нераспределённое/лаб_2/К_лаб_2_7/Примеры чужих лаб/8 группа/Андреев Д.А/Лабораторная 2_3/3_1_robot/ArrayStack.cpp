#include <iostream>
#include "ArrayStack.h"

ArrayStack::ArrayStack(const int& _size)
{
	size = _size;
	p = new int*[size];
	for (int i = 0; i< size; i++)
		p[i] = new int[2];
	top = 0;
}
ArrayStack::~ArrayStack()
{
	//cout << "destruct" << endl;
	size = 0;
	top = 0;
	for (int i = 0; i < size; i++)
	{
		p[i] = new int[2];
		delete[] p[i];
	}
	delete[] p;
	p = NULL;
}


bool ArrayStack::isFull()
{
	if (top == (size))
		return true;
	return false;
}

bool ArrayStack::isEmpty()
{
	if (top == 0)
		return true;
	return false;
}

void ArrayStack::push(const int& n1, const int& n2)
{
	if (!isFull())
	{
		top++;
		p[top][0] = n1;
		p[top][1] = n2;
	}
}

void ArrayStack::pop()
{
	if (!isEmpty())
	{
		top--;
	}
}

void ArrayStack::topel(int* n1, int* n2)
{
	if (!isEmpty())
	{
		*n1 = p[top][0];
		*n2 = p[top][1];
	}
}

ArrayStack::ArrayStack(const ArrayStack& s)
{
	size = s.size;
	top = s.top;
	p = new int*[size];
	for (int i = 0; i<top; i++)
	{
		p[i][0] = s.p[i][0];
		p[i][1] = s.p[i][1];
	}
}