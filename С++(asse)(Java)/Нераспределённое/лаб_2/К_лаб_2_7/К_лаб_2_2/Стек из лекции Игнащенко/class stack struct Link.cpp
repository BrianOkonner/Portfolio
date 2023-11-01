#include <iostream>
#include "class stack struct Link.h"
using namespace std;


Stack::Link::Link(void* data, Link* next)
{
	this->data = data;
	this->next = next;
}

Stack::Link:: ~Link() {}

Stack::Stack()
{
	head = NULL;
}

bool Stack::isEmpty()
{
	return !head;
}

void* Stack::Top()
{
	if (!isEmpty())
		return head->data;
	return NULL;
}

void Stack::Push(void* dat)
{
	head = new Link(dat, head);
}
void Stack::Pop()
{
	if (!isEmpty())
	{
		Link* tmp = head;
		if (head->next)
			head = head->next;
		else head = NULL;
		delete tmp;
	}
}

Stack::~Stack()
{
	while (!isEmpty())
		Pop();
}

void main()
{
	Stack s;
	int *f = new int;
	for (int i = 0; i < 10; i++)
		s.Push(new int (i));
	*f = 228;
	int a = 5, c = 9;
	s.Push(&a);
	s.Push(&c);
	
	/*a = (double*)s.Pop();
	cout << (*a);
	int* y = (int*)s.Pop();
	cout << (*y);
*/

	while (!s.isEmpty())
	{
		int g = *(int*)s.Top();
		s.Pop();
		cout << g << endl;
	}

}



