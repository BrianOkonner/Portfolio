#pragma once
class List		/* ������ ����������������*/
{
	//public:
	struct node	/* ������� ������ */
	{
		int item;		     /* ������ */
		struct node*  next;	 /* ��������� �� ��������� ������� */
		node(int, node *);
		~node();
	};
	struct node *head;

public:
	List();	                 /* �����������*/
	List(const List& lst);   /* ����������� �����������*/
	~List();	             /* ���������� */
	bool isEmpty();	         /* ������ ������? */

	void push_head(int n);
	void push_back(int n);   //�������� ������� � ����� ������
	node* remove_head();	 // ��������� ������� �� ������ ������
	node* remove_tail();	 // ��������� ������� �� ����� ������
	int front();
	node* search();          // ����� ������� ������ ������
	void remove(node* adr);	 // ������� ������� c �������  adr
	void print();            //������ ����������� ������
	int remove(int pos);
	void delchet();		     //�������� � ������� ��������
	int smin();		    	 //����� min

};