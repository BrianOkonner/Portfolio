//���� � �������������� �������

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

enum { Size = 100 };
	int  size;		/* ����������� ������� */
	int* p;			/* ��������� �� ������ */
	int  top;		/* �������� ����� */
 int* ArrayStack(int _size)  
{	
	size = _size > Size ? _size : Size;
	p = new int[size];
	top = -1;
	return p;
	
}
 bool isEmpty()         /* ������ ����? */
{
	return top == -1;
}

bool isFull()   	        /* ������ ����? */
{
	return top + 1 == size;
}
	
void DeleteStack()	        /* �������� ����� */
{
	top = -1;
	size = 0;
	delete []p;
	p = 0;
}

int push(const int n)  /* ��������� ������� � ���� */
{
	if(isFull())
		return -1;
	top++;
	p[top] = n;
	return top;
}

int pop()	              /* ���������� ������� �� ����� */
{
	if(!isEmpty())
	{
		int res = p[top];
		top--;
		return res;
	}
	return 0;
}


	
void main()
{
	int *Stack;
	size=7;
	p=ArrayStack(size);  
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);


	
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;
	cout<<pop()<<endl;

	
}
