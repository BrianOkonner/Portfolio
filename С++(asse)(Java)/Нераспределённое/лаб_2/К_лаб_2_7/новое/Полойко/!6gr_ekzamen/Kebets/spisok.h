#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <iostream>
using namespace std;

struct node						/* ������� ������ */
	{
		int  item;					/* ������ */
		node*  next;				/* ��������� �� ��������� ������� */
		node*  prev;				/* ��������� �� ���������� ������� */
	};
	/* ��������� �� ������ � ��������� �������� � ������ */
	node *head, *tail;
void InitList()							/* ����������� */
{
	head = 0;
	tail = 0;
}

void RemoveList()							/* ���������� */
{
	while(head != 0)
	{
		node* tmp = head;
		head = head->next;
		delete tmp;
	}
	head = 0;
	tail = 0;
}

void push_front(int n)			/* �������� ������� � ������ ������ */
{
	node* tmp = new node;
	tmp->item = n;
	tmp->prev = 0;
	tmp->next = head;
	if(head)
		head->prev = tmp;
	else
		tail = tmp;
	head = tmp;
}

void push_back(int n)				/* �������� ������� � ����� ������ */
{
	node* tmp = new node;
	tmp->item = n;
	tmp->next = 0;
	tmp->prev = tail;
	if(tail)
		tail->next = tmp;
	else
		head = tmp;
	tail = tmp;
}

int pop_front()					/* ��������� ������� �� ������ ������ */
{
	if(head)
	{
		int res = head->item;
		node *tmp = head;
		if(head->next)
			head->next->prev = 0;
		else
			tail = 0;
		head = head->next;
		delete tmp;
		return res;
	}
	return 0;
}

int pop_back()					/* ��������� ������� �� ����� ������ */
{
	if(tail)
	{
		int res = tail->item;
		node *tmp = tail;
		if(tail->prev)
			tail->prev->next = 0;
		else
			head = 0;
		tail = tail->prev;
		delete tmp;
		return res;
	}
	return 0;
}

void insert(int data, int pos)	/* �������� � ������� pos+1 */
{
	node* tmp = new node;
	tmp->item = data;
	node* ptmp = head;
	if(ptmp == 0)
	{
		tmp->next = 0;
		tmp->prev = 0;
		head = tmp;
		tail = tmp;
		return;
	}
    int i = 0;
	while ((i<pos)&&(ptmp->next))
	{
		ptmp = ptmp->next;
		i++;
	}
    if  (ptmp->next == 0)
		{
			ptmp->next = tmp;
			tmp->prev = ptmp;
			tmp->next = 0;
			tail = tmp;
			return;
		}
	
	ptmp->next->prev = tmp;
	tmp->next = ptmp->next;
	ptmp->next = tmp;
	tmp->prev = ptmp;
}

int remove(int pos)			/* ������� ������� c ������� pos*/
{
	node* ptmp = head;
	for(int i = 0; i<pos; i++)
	{
		if(ptmp == 0)
		{
			return 0;
		}
		ptmp = ptmp->next;
	}
	ptmp->next->prev = ptmp->prev;
	if(ptmp->prev != 0)
		ptmp->prev->next = ptmp->next;
	int res = ptmp->item;
	delete ptmp;
	return res;
}

bool isEmpty()					/* ������ ������? */
{
	return head == 0;
}
void print ()			//������ ����������� �����
{
	node* temp = head;
	
	while (temp)
	{
		cout<<temp->item<<endl;
		temp = temp->next;
	}
}