#include "Header.h"

void Stack::InitIntStack()
{
	top_int = NULL;
}

void Stack::push_int(int a)
{
	IntStack*tmp = new IntStack;
	tmp->prev = top_int;
	tmp->item = a;
	top_int = tmp;
}

bool Stack::isEmptyInt()
{
	return top_int == NULL;
}

int Stack::TopInt()
{
	if (top_int)
		return top_int->item;
}

void Stack::PopInt()
{
	int res;
	IntStack*tmp;
	tmp = top_int;
	top_int = top_int->prev;
	delete tmp;
}
