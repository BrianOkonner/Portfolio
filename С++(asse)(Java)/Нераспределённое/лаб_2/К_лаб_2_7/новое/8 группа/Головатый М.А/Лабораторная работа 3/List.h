#pragma once
class List		/* ������ ����������������*/
{
	struct node	/* ������� ������ */
	{
		int item;		 /* ������ */
		struct node*  p;
								/* ��������� �� ��������� ������� */
	};
	struct node *head;			/* ��������� �� ������ ������� � ������ */
public:
	List();						/* ����������� */
	List(const List& lst);		// ����������� �����������
	~List();					/* ���������� */
	//��� ���������� �� push_head?
	void ins(const int& n);		/* �������� ������� � ������ */
	//��� ���������� �� remove_head?
	int del();					/* ��������� ������� �� ������ */
	bool isEmpty();				/* ������ ������? */
 //�������������
	void push_head(int n);		//�������� ������� � ������ ������
	void push_back(int n);		//�������� ������� � ����� ������
	node* remove_head();		// ��������� ������� �� ������ ������
	node* remove_tail();		// ��������� ������� �� ����� ������
	node* search();				// ����� ������� ������ ������
	void remove(node* adr);		// ������� ������� c �������  adr
	void print();				//������ ����������� ������
	int remove(int pos);		//���������  �������� �������
	void delchet();				//�������� � ������� ��������
	int smin();		    		//����� min
	void invert();				//������������� �������� ������ �������� ������
};
