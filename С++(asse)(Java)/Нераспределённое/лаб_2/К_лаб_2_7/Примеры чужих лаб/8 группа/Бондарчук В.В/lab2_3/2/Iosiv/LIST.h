#pragma once
using namespace std;

class List 
{										/* ������ ����������������						*/
public:
	struct node 
	{								/* ������� ������								*/
		int item;								/* ������										*/
		struct node*  next;						/* ��������� �� ��������� �������				*/
	};
	struct node *head;							/* ��������� �� ������ ������� � ������			*/

	List();							            /* �����������									*/
	List(const List& lst);						/* ����������� �����������						*/
	~List();									/* ����������									*/
	bool isEmpty();								/* ������ ������?								*/
	int size();
	//������������� 
	void push_head(int n);						/* �������� ������� � ������ ������				*/
	void push_back(int n);						/* �������� ������� � ����� ������				*/
	node* remove_head();						/* ��������� ������� �� ������ ������			*/
	node* remove_tail();						/* ��������� ������� �� ����� ������			*/
	int top();	
};