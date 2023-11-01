#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class ArrayQueue		/* ��������� ������� �� ������� */
{
	int	size;			/* ����������� ������� */
	int*	p;			/* ��������� �� ������ */
	int	head;			/* ������ ������� �������� �������� */
	int tail;			/* ������ ���������� �������� �������� */
	int	n;				/* ���������� ��������� � ������� */
public:
	ArrayQueue(int size);				/* ������������� ������� */
	ArrayQueue(const ArrayQueue& q);	// ����������� �����������
	~ArrayQueue();						/* ��������� ������� */
	void push(int _n);					/* ��������� ������� � ������� */
	void push_head(int _n);
	int del();							/* ������� ������� �� ������� */
	bool isEmpty();						/* ������ �������? */
	bool isFull();						/* ������ �������? */
	int front();
};
