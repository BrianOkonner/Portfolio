#include "Stack.h"

Stack::Stack()
{
	first = 0;
	last = 0;
	size = 0;
}

Stack::Stack(const Stack &Stack)
{
	first = Stack.first;
	last = Stack.last;
	size = Stack.size;
}

Stakc::~Stack()
{
	while (first)
	{
		item *current = first;
		first = first->next;
		delete current;
	}
}

void Stack::push_head(int a)
{
	item *tmp = new item;
	tmp->value = a;
	if (first)
	{
		tmp->next = first;
		first = tmp;
	}
	else
	{
		first = last = tmp;
		first->next = 0;
		last->next = 0;
	}
	size++;
}

void Stack::push_back(int a)
{
	item *tmp = new item;
	tmp->value = a;
	if (last)
	{
		last->next = tmp;
		last = tmp;
		last->next = 0;
	}
	else
	{
		first = last = tmp;
		last->next = 0;
		first->next = 0;
	}
	size++;
}
int Stack::remove_head()
{
	try
	{
		if (!first)
		{
			throw 1;
		}
	}
	catch (...)
	{
		std::cout << "No elements" << std::endl;
		return 0;
	}
	size--;
	item *current = first;
	first = first->next;
	int a = current->value;
	delete current;
	return a;
}

int Stack::remove_tail()
{
	try
	{
		if (!first)
		{
			throw 1;
		}
	}
	catch (...)
	{
		std::cout << "No elements" << std::endl;
		return 0;
	}
	size--;
	int a = last->value;
	item *tmp;
	for (tmp = first; tmp->next->next; tmp = tmp->next);
	tmp->next = 0;
	delete last;
	last = tmp;
	return a;
}

int Stack::remove(int pos)
{
	try 
	{
		if (size < pos)
			throw 1;
	}
	catch (...)
	{
		std::cout << "Invalid size" << std::endl;
		return 0;
	}
	size--;
	item *tmp = first, *current;
	if (pos == 1)
	{
		return Stack::remove_head();
	}
	for (int i = 1; i < pos - 1; i++, tmp = tmp->next);
	int a = tmp->next->value;
	current = tmp->next;
	tmp->next = current->next;
	delete current;
	return a;
}

void Stack::print()
{
	for (item *tmp = first; tmp; tmp = tmp->next)
	{
		std::cout << tmp->value << " ";
	}
	std::cout << std::endl;
}

bool Stack::isEmpty()
{
	if (first)
	{
		return true;
	}
	return false;
}

int Stack::search()
{
	item *tmp;
	for (tmp = first; tmp; tmp = tmp->next)
	{
		if (tmp->value % 2 == 0)
		{
			return tmp->value;
		}
	}
	return -1;
}

void Stack::delchet()
{
	item *tmp, *current;
	for (tmp = first; tmp && tmp->next; tmp = tmp->next)
	{
		current = tmp->next;
		tmp->next = current->next;
		delete current;
	}
}

int Stack::smin()
{
	item *tmp;
	int a = first->value;
	for (tmp = first->next; tmp; tmp = tmp->next)
	{
		if (a > tmp->value)
		{
			a = tmp->value;
		}
	}
	return a;
}

void Stack::invert()
{
	item *tmp1 = first, *tmp2 = first->next, *tmp3 = first->next->next;
	for (int i = 0; i < size / 2 - 1; i++)
	{
		tmp2->next = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp3;
		tmp3 = tmp3->next;
	}
	first->next = tmp2;
	first = tmp1;
}