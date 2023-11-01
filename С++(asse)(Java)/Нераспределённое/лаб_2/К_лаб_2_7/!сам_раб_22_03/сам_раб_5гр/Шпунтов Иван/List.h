#pragma once
#include <iostream>
class Stack
{
	struct item	/* ������� ������ */
	{
		int value;		 /* ������ */
		item*  next;	 /* ��������� �� ��������� ������� */
	};
public:
	item *first, *last;	 /* ��������� �� ������ ������� � ������ */

	Stack();             /* ����������� */
	Stack(const Stack&);   // ����������� �����������
	~Stack();	/* ���������� */

	bool isEmpty();	       /* ������ ������? */
	void push_back(int);		//�������� ������� � ����� ������
	int remove_tail();		// ��������� ������� �� ����� ������
	void print();		//������ ����������� ������
	int size;
};
