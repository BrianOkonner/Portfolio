/*Карабанова Ксения Вариант 1.
Условие: 1. В файле input.txt задан набор целых чисел.
Записать их в память используя свой двунаправленный динамический список.
Просматривая один раз список, элементы по тройкам из списка,поменять крайние,
результат записать в стандартный стек и вывести в файл Output.txt*/
#include <iostream>
#include "List.cpp"
#include "list.h"
#include <fstream>
#include <stack>

#include "List.h"

List::List()
{
	first = 0;
	last = 0;
	size = 0;
}

List::List(const List &list)
{
	first = list.first;
	last = list.last;
	size = list.size;
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

void List::push_head(int a)
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

void List::push_back(int a)
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
	if (first)
	{
		return true;
	}
	return false;
}



using namespace std;

void main()
{
	ifstream fin;
	ofstream fout;
	fin.open("Input.txt");
	fout.open("Output.txt");
	List lt;
	stack <int> st1;
	stack <int> st2;
	int n;
	while (!fin.eof())
	{
		fin >> n;
		lt.push_back(n);
	}
	lt.print();
	int a1, a2, a3;
	while (lt.size > 2)
	{
		a1 = lt.front();
		lt.remove_head();
		a2 = lt.front();
		lt.remove_head();
		a3 = lt.front();
		lt.remove_head();
		st1.push(a3);
		lt.push_head(a1);
		lt.push_head(a2);
	}
	st1.push(lt.front());
	lt.remove_head();
	st1.push(lt.front());
	lt.remove_head();
	while (!st1.empty())
	{
		st2.push(st1.top());
		st1.pop();
	}
	while (!st2.empty())
	{
		cout << st2.top()<< ' ';
		fout << st2.top() << ' ';
		st2.pop();
	}


	system("pause");
}