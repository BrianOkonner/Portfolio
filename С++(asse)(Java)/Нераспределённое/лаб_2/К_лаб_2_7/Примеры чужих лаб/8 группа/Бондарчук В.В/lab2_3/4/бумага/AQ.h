#pragma once
class ArrayQueue		/* ��������� ������� �� ������� */
{
	int	size;		/* ����������� ������� */
	int*	p;		/* ��������� �� ������ */
	int	head;		/* ������ ������� �������� �������� */
	int	n;		/* ���������� ��������� � ������� */
	int tail;
public:
	ArrayQueue(int size);	/* ������������� ������� */
	ArrayQueue(const ArrayQueue& q);  // ����������� �����������
	~ArrayQueue();	/* ��������� ������� */
	void push(int n);/* ��������� ������� � ������� */
	int del();		/* ������� ������� �� ������� */
	bool isEmpty();	/* ������ �������? */
	bool isFull();	/* ������ �������? */
	int Size();
	int top();
};


