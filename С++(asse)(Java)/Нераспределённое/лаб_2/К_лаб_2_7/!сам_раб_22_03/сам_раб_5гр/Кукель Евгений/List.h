#pragma once
#include <iostream>
using namespace std;

class List		/* ������ ����������������*/
{
	struct node	/* ������� ������ */
	{
		int item;		 /* ������ */
		struct node*  p;	 /* ��������� �� ��������� ������� */
	};
	node *head;	 /* ��������� �� ������ ������� � ������ */
public:

	List();	             /* ����������� */
	List(const List& lst);   // ����������� �����������
	~List();	             /* ���������� */
	void ins(const int& n);  /* �������� ������� � ������ */
	int del();		       /* ��������� ������� �� ������ */
	bool isEmpty() { return head == NULL; }	       /* ������ ������? */

};

