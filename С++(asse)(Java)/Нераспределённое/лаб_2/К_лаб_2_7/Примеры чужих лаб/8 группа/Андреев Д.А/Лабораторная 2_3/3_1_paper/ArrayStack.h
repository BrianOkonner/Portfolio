#pragma once
class ArrayStack		/* ���� �� ������� */
{
	int  size;	/* ����������� ������� */
	int** p;  	/* ��������� �� ������ */
	int  top;	/* �������� ����� */
public:
	ArrayStack(const int& _size);     /* ����������� */
	ArrayStack(const ArrayStack& s);  // ����������� �����������
	~ArrayStack();	          /* ���������� */
	void push(const int& n1, const int& n2);  /* ��������� ������� � ���� */
	void pop();/* ���������� ������� �� ����� */
	void topel(int* n1, int* n2);	//������� �������
	bool isEmpty();	          /* ������ ����? */
	bool isFull();	          /* ������ ����? */
};



