#include "List.h"

LIST::LIST()
{
	head = 0;
	tail = 0;
}

LIST::LIST(LIST &list_)
{
	item *tmp;
	for (tmp = list_.head; tmp; tmp = tmp->next)
	{
		this->push_back(tmp->n);
	}
}

LIST::~LIST()
{
	while (head)
	{
		item *current = head;
		head = head->next;
		delete current;
	}
}

void LIST::push_back(int a)
{
	item *tmp = new item;
	tmp->n = a;
	if (head)
	{
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
		tail->next = 0;
	}
	else
	{
		tail = head = tmp;
		head->next = 0;
		tail->next = 0;
		head->prev = 0;
		tail->prev = 0;
	}
}

void LIST::push_head(int a)
{
	item *tmp = new item;
	tmp->n = a;
	if (head)
	{
		head->prev = tmp;
		tmp->next = head;
		head = tmp;
		head->prev = 0;
	}
	else
	{
		tail = head = tmp;
		head->next = 0;
		tail->next = 0;
		head->prev = 0;
		tail->prev = 0;
	}
}

int LIST::remove_head()
{
	try
	{
		if (!head)
		{
			throw 1;
		}
	}
	catch (...)
	{
		cout << "NO ELEMENTS" << endl;
		return 0;
	}
	int a = head->n;
	item *tmp = head;
	head = head->next;
	head->prev = 0;
	delete tmp;
	return a;
}

int LIST::remove_tail()
{
	try
	{
		if (!head)
		{
			throw 1;
		}
	}
	catch (...)
	{
		cout << "NO ELEMENTS" << endl;
		return 0;
	}
	int a = tail->n;
	item *tmp = tail;
	tail = tail->prev;
	tail->next = 0;
	delete tmp;
	return a;
}

void LIST::print(ostream &out)
{
	item *tmp;
	for (tmp = head; tmp; tmp = tmp->next)
	{
		out << tmp->n << " ";
	}
}

void LIST::change()
{
	item *tmp;
	for (tmp = head; tmp && tmp->next && tmp->next->next;)
	{
		int a = tmp->n;
		tmp->n = tmp->next->next->n;
		tmp->next->next->n = a;
		if (tmp->next->next->next)
		{
			tmp = tmp->next->next->next;
		}
		else
		{
			return;
		}
	}
}

void LIST::copy_to_list(list<int> &a)
{
	item *tmp;
	for (tmp = head; tmp; tmp = tmp->next)
	{
		a.push_back(tmp->n);
	}
}