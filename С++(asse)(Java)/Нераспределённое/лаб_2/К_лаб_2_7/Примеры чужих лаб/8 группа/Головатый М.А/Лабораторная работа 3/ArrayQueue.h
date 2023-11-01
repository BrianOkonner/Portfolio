#pragma once
#include "Header.h"
class ArrayQueue		/* ��������� ������� �� ������� */
{
	int	size;		/* ����������� ������� */
	int*	p;		/* ��������� �� ������ */
	int	head;		/* ������ ������� �������� �������� */
	int	n;		/* ���������� ��������� � ������� */
public:
	ArrayQueue(int size);	/* ������������� ������� */
	ArrayQueue(const ArrayQueue& q);  // ����������� �����������
	~ArrayQueue();	/* ��������� ������� */
	void push(int n);/* ��������� ������� � ������� */
	int del();		/* ������� ������� �� ������� */
	bool isEmpty();	/* ������ �������? */
	bool isFool();	/* ������ �������? */
	void printQueue(ostream&);
};
