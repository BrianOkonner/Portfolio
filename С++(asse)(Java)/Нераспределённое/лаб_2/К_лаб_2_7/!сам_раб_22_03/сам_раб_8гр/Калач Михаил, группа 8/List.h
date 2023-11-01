#pragma once

class List
{
	struct item					//������� ������ 
	{
		int value;				//������
		item*  next;			//��������� �� ��������� �������
	};
	item *first, *last;			//��������� �� ������ ������� � ������
	int N;
public:
	List();						//�����������
	List(const List& Obj);		//����������� �����������
	~List();					//����������
	bool isEmpty();				//�������� �� �������
	int size();					//���������� ��������� � ������
	int remove_head();			//��������� ������� �� ������ ������
	int remove_tail();			//��������� ������� �� ����� ������
	int search();				//����� ������ ������ �������
	int remove(int POS);		//������� �� �������
	int search_min();	    	//����� min
	void push_head(int X);		//�������� ������� � ������ ������
	void push_back(int X);		//�������� ������� � ����� ������
	void print();				//������ ����������� ������
	void del_even();			//�������� � ������� ��������
	void invert();				//������������� �������� ������ �������� ������
};
