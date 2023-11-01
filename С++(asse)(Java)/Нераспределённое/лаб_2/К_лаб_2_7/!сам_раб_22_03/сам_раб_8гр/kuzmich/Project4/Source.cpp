#include "Header.h"

List::List(int n)
{
	size = n;
	p = new int[size];
	top = 0;
}
void List::Push_Front(int n)
{
	p[top] = n;
	top++;
}
void List::Push_Back(int n)
{
	top++;
	for (int i = top - 1; i> 0; i--)
	{
		p[i] = p[i - 1];
	}
	p[0] = n;
}
int List::Top()
{
	return p[top - 1];
}
int List::Tail()
{
	return p[0];
}
void List::Pop_Front()
{
	top--;
}
int List::Size()
{
	return top;
}
void List::Push_pos(int n, int pos)
{
	top++;
	for (int i = top - 1; i> pos; i--)
	{
		p[i] = p[i - 1];
	}
	p[pos] = n;
}
void List::Insert()
{
	int index;
	for (int i = 0; i < top; i++)
	{
		if (p[i] % 2)
		{
			index = i + 1;
			Push_pos(p[i]+1, index);
		}
	}
}
void List::Print()
{
	for (int i = 0; i < top; i++)
	{
		cout << p[i] << endl;
	}
}