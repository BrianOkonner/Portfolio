#pragma once
#include <iostream>
class List
{
	struct item	/* ������� ������ */
	{
		int value;		 /* ������ */
		item*  next;	 /* ��������� �� ��������� ������� */
	}*first, *last;
public:
	//item *first, *last;	 /* ��������� �� ������ ������� � ������ */

	List();             /* ����������� */
	List(const List&);   // ����������� �����������
	~List();	/* ���������� */

	bool isEmpty();	       /* ������ ������? */
	void push_head(int);		//�������� ������� � ������ ������
	void push_back(int);		//�������� ������� � ����� ������
	int remove_head();		// ��������� ������� �� ������ ������
	int remove_tail();		// ��������� ������� �� ����� ������
	void print();		//������ ����������� ������
	int size;
	int front() { return first->value; }
	int back() { return last->value; }
};