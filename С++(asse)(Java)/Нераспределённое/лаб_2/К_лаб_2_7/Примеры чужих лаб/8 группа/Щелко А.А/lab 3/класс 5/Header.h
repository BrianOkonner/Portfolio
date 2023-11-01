#pragma once

#include <iostream>
using namespace std;

class Deque {
	struct node {									/* ������� ���� */
		int  item;									/* ������ */
		struct  node*  next;						/* ��������� �� ��������� ������� */
		struct  node*  prev;						/* ��������� �� ���������� ������� */
		node(int Item, node *Next, node *Prev) {
			item = Item;
			next = Next;
			prev = Prev;
		}
	} *head, *tail;					/* ��������� �� ������ � ��������� �������� � ������ */
	int size;						/* ������ ������� */
public:
	Deque();						/* ����������� */
	Deque(const Deque& d);			/* ����������� ����������� */
	~Deque();						/* ���������� */
	void ins�ead(int n);			/* �������� ������� � ������ ���� */
	void insTail(int n);			/* �������� ������� � ����� ���� */
	int delHead();					/* ��������� ������� �� ������ ���� */
	int delTail();					/* ��������� ������� �� ������ ���� */
	void show();
	bool isEmpty();					/* ������ ���? */
};