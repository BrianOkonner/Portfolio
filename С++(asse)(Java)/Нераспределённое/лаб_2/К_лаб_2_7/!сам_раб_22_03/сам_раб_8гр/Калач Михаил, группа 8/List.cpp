#include "List.h"

List::List()
{
	first = 0;
	last = 0;
	N = 0;
}

List::List(const List &Obj)
{
	first = Obj.first;
	last = Obj.last;
	N = Obj.N;
}

List::~List()
{
	while (first)
	{
		item *current = first;
		first = first->next;
		delete current;
	}
}

void List::push_head(int X)
{
	item *tmp = new item;
	tmp->value = X;
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
	N++;
}

void List::push_back(int X)
{
	item *tmp = new item;
	tmp->value = X;
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
	N++;
}
int List::remove_head()
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
		std::cout << "Error. List is empty." << std::endl;
		return 0;
	}
	N--;
	item *current = first;
	first = first->next;
	int a = current->value;
	delete current;
	return a;
}

int List::remove_tail()
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
		std::cout << "Error. List is empty." << std::endl;
		return 0;
	}
	N--;
	int a = last->value;
	item *tmp;
	for (tmp = first; tmp->next->next; tmp = tmp->next);
	tmp->next = 0;
	delete last;
	last = tmp;
	return a;
}

int List::remove(int POS)
{
	try 
	{
		if (N < POS)
			throw 1;
	}
	catch (...)
	{
		std::cout << "Error. Invalid N" << std::endl;
		return 0;
	}
	N--;
	item *tmp = first, *current;
	if (POS == 1)
	{
		return remove_head();
	}
	for (int i = 1; i < POS - 1; i++, tmp = tmp->next);
	int a = tmp->next->value;
	current = tmp->next;
	tmp->next = current->next;
	delete current;
	return a;
}

void List::print()
{
	for (item *tmp = first; tmp; tmp = tmp->next)
	{
		std::cout << tmp->value << " ";
	}
	std::cout << std::endl;
}

bool List::isEmpty()
{
	return first;
}

int List::search()
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

void List::del_even()
{
	item *tmp, *current;
	for (tmp = first; tmp && tmp->next; tmp = tmp->next)
	{
		current = tmp->next;
		tmp->next = current->next;
		delete current;
	}
}

int List::search_min()
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

void List::invert()
{
	item *tmp1 = first, *tmp2 = first->next, *tmp3 = first->next->next;
	for (int i = 0; i < N / 2 - 1; i++)
	{
		tmp2->next = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp3;
		tmp3 = tmp3->next;
	}
	first->next = tmp2;
	first = tmp1;
}

int List::size()
{
	return N;
}