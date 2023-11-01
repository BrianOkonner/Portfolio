#include "DeqOnArray.h"
#include <iostream>

using namespace std;

DeqOnArray::DeqOnArray()
{
	p = new int[100];
	top = 0;
	size = 0;
}


DeqOnArray::~DeqOnArray()
{
	delete[]p;
}

int DeqOnArray::sizeOfStack() 
{
	return size;
}

int DeqOnArray::front()
{
	try
	{
		if (size <= 0)
			throw "No elements to cout. List is empty!!!";
		return p[0];
	}
	catch (char*t)
	{
		cout << t << endl;
	}
}

int DeqOnArray::back()
{
	try
	{
		if (size <= 0)
			throw "No elements to cout. List is empty!!!";
		return p[top-1];
	}
	catch (char*t)
	{
		cout << t << endl;
	}
}

int DeqOnArray::popFront()
{
	try
	{
		if (size == 0)
			throw "List is empty.U can't pop!!!";
		size--;
		int z = p[0];
		for (int i = 0; i < top - 1; i++)
		{
			p[i] = p[i + 1];
		}
		top--;
		return z;
	}
	catch (char*s)
	{
		cout << s << endl;
		return 0;
	}
}

int DeqOnArray::popBack()
{
	try
	{
		if (size == 0)
			throw "List is empty.U can't pop!!!";
		size--;
		return p[--top];
	}
	catch (char*s)
	{
		cout << s << endl;
		return 0;
	}
	
}

void DeqOnArray::pushFront(int k)
{
	try
	{
		if (size >= 100)
			throw "List if full.U cann't push.";
		for (int i = top - 1; i >= 0; i--)
		{
			p[i + 1] = p[i];
		}
		p[0] = k;
		top++;
		size++;
	}
	catch (char*s)
	{
		cout << s << endl;
	}
}

void DeqOnArray::pushBack(int element)
{
	try
	{
		if (size >= 100)
			throw "List if full.U cann't push.";
		p[top] = element;
		top++;
		size++;
	}
	catch (char*s)
	{
		cout << s << endl;
	}
}
	

bool DeqOnArray::isEmpty()
{
	return (size==0);
}

void DeqOnArray::sortAboveCompare()
{
	for (int i = 0; i < top / 2; i++)
	{
		if (p[i] > p[top - i - 1])
		{
			int z = p[i];
			p[i] = p[top - i - 1];
			p[top - i - 1] = z;
		}
	}
}