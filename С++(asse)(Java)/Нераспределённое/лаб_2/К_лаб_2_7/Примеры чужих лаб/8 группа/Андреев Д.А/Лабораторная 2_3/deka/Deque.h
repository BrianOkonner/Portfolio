#pragma once
#include <iostream>
using namespace std;

class Deque						/* ��� � ����������� ������� */
{
	struct node					/* ������� ���� */
	{
		int  item;				/* ������ */
		struct  node*  next;	/* ��������� �� ��������� ������� */
		struct  node*  prev;	/* ��������� �� ���������� ������� */
	};
	struct node *head, *tail;	/* ��������� �� ������ � ��������� �������� � ������ */

public:
	Deque();					// �����������
	Deque(const Deque& d);		// ����������� �����������
	~Deque();					/* ���������� */
	void ins�ead(int n);		/* �������� ������� � ������ ���� */
	void insTail(int n);		/* �������� ������� � ����� ���� */
	int delHead();				/* ��������� ������� �� ������ ���� */
	int delTail();				/* ��������� ������� �� ������ ���� */
	bool isEmpty();				/* ������ ���? */
};