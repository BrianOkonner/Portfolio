#pragma once
#include <iostream>
#include <locale>
using namespace std;

class Deque {
	struct node {									/* ������� ���� */
		int  item;									/* ������ */
		struct  node*  next;						/* ��������� �� ��������� ������� */
		struct  node*  prev;						/* ��������� �� ���������� ������� */
		node(int itm, node *nxt, node *prv) {
			item = itm;
			next = nxt;
			prev = prv;
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