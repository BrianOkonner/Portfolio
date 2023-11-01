#pragma once

#include <fstream>
#include <Windows.h>
#include <iomanip>
#include <cstdlib>
#include <locale>
#include <iostream>
using namespace std;

class List{										/* ������ ����������������						*/

	public:
	struct node	{								/* ������� ������								*/
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
	int front();
	node* search();								/* ����� ������� ������ ������ �������			*/
	void remove(node* adr);						/* ������� ������� c �������  adr				*/
	void print();								/* ������ ����������� ������					*/
	int remove(int pos);						/* ���������  �������� �������					*/
	void delchet();								/* �������� � ������� ��������					*/
	int smin();   								/* ����� ������������ ��������					*/
	void invert();								/* ������������� �������� ������ �������� ������*/
}; 