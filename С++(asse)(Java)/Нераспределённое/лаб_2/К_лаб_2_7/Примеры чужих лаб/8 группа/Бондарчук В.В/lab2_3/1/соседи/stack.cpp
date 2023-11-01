#include"stack.h"
ArrayStack::ArrayStack(const int& _size)
{
	size = _size;
	if (_size < 0)
	{
		size = 0;
	}
	
	p = new int[size];
	top = 0;
}
ArrayStack::ArrayStack(const ArrayStack& s)
{
		size = s.size;
		p = new int[size];
		for (int i = 0; i < size; i++)
		{
			p[i] = s.p[i];
		}
		top = s.top;
}
ArrayStack::~ArrayStack()
{
	delete[] p;
} 
void ArrayStack:: push(const int& n)
{
	if (isFull()||size==0) 
	{
		return;
	}
	p[top] = n;
	top++;
}
int ArrayStack::pop()
{
	if (!isEmpty())
	{
		top--;
		int tmp = p[top];
		
		return tmp;
	}
	if (isEmpty() || size == 0)
	{
		return 0;
	}
}
bool ArrayStack::isEmpty()
{
	return top == 0;
}
bool ArrayStack::isFull()
{
	return top == size;
}
int ArrayStack::Top() 
{
	int res, tmp;
	tmp = top;
	tmp--;
	return p[tmp];
}