// ��� �������

#include <iostream>
using namespace std;

int stepen(int ch);
void sort(int m[],int c);
struct elem
{
	int value;
	elem *prev;
};
struct Stack
{
	elem *head;
	void init()
	{
		head=NULL;
	}
	bool is_empty()
	{
		return (head==NULL);
	}
	int peek ()// ����� �������� �� �������� �����
	{ 
			return head->value;
	}
	void push(int val)//�������
	{
		elem *newel=new elem;
		newel->value=val;
		newel->prev=head;
		head=newel;
	}
	int pop()//��������
	{
		int val=head->value;
		elem *dl=head;
		head=head->prev;
		delete dl;
		return val;
	}
	void clear()
	{
		while (!is_empty())
			pop();
	}

};