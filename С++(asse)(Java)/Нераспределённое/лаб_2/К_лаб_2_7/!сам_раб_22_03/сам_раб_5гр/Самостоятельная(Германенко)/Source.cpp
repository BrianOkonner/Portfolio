#include "Header.h"
#include <iostream>

my_stack::my_stack()
{
	max_elem = 1;
	last = 0;
	data = new int[max_elem];
}

my_stack::my_stack(int n)
{
	max_elem = n;
	last = 0;
	data = new int[max_elem];
}

my_stack::~my_stack()
{
	delete[] data;
}

int my_stack::top()
{
	if (last)
		return data[last - 1];
	else return -1;
}

void my_stack::pop()
{
	if (last)
	{
		data[last-1] = 0;
		last--;
	}
}

void my_stack::push(int a)
{
	if (last < max_elem)
		data[last++] = a;
	else
	{
		max_elem *= 2;
		int *new_data = new int[max_elem];
		memcpy(new_data, data, max_elem * sizeof(int));

		delete[] data;
		data = new_data;
		data[last++] = a;
	}
}

bool my_stack::empty()
{
	return !last;
}
