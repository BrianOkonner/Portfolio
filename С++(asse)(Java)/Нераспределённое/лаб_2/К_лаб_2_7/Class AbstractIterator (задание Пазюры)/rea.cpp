#include <iostream.>
#include "header.h"
ArrayStack::ArrayStack(int _n)
{
	n=_n;
	p=new int[n];
	top=0;
}
ArrayStack::ArrayStack(ArrayStack &ob)
{
	n=s.n;
	p=new int[n];
	top=s.top;
	for (int i=0;i<top;i++)
			p[i]=s.p[i];
}
ArrayStack::~ArrayStack()
{
	delete[] p;
}
void ArrayStack::push(const int& r)		// ��������� � ����
{
	if (top==r)
		throw "stack is full";
	p[top]=r;
	top++;
}
void ArrayStack::pop(int& r)			// ���������� �� �����
{
	if (top==0)
		throw "stack is empty";
	top--;
	r=p[top];
}
bool ArrayStack::IsEmpty() const
{
	if (top==0)
		return 1;
	else return 0;
}
bool ArrayStack::IsFull() const 
{
	if (top==n)
		return 1;
	else return 0;
}

ArrayStackIterator::ArrayStackIterator(ArrayStack& ob):a(ob),it(_a.top-1){}
bool ArrayStackIterator::InRange() const  // ������ � ���������� ��������
{
	if (it<0)
		return 0;
	return 1;
}
void ArrayStackIterator::Reset()		 // �������� ������ � ������
{
	it=a.top-1;
}
int& ArrayStackIterator::operator *() const	// ������������� (������ ��������)
{
	if (it<0)
		throw "iterator out of bounds";
	return a.p[it];
}
void ArrayStackIterator::operator ++()	// ����� �� �������
{
	it--;
}


