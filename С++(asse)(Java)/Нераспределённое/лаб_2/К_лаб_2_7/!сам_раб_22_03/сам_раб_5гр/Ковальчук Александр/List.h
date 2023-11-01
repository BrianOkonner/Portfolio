#pragma once
#include <iostream>
class List
{
	struct item	/* ������� ������ */
	{
		int value;		 /* ������ */
		item*  next;	 /* ��������� �� ��������� ������� */
	};
	item *first, *last;	 /* ��������� �� ������ ������� � ������ */
	int size;
public:

	List();             /* ����������� */
	List(const List&);   // ����������� �����������
	~List();	/* ���������� */

	bool isEmpty();	       /* ������ ������? */
	void push_head(int);		//�������� ������� � ������ ������
	void push_back(int);		//�������� ������� � ����� ������
	int remove_head();		// ��������� ������� �� ������ ������
	int remove_tail();		// ��������� ������� �� ����� ������
	int search();		// ����� ������� ������ ������
	void print();		//������ ����������� ������
	int remove(int); //������� �� �������
	void delchet();		//�������� � ������� ��������
	int smin();	    	//����� min
	void invert();		//������������� �������� ������ �������� ������
	int s() { return size; }
};
