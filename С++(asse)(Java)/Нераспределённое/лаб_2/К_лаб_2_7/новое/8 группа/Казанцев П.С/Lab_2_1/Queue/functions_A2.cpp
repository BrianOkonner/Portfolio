#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "functions_A2.h"
using namespace std;

/*void push(queue *q, int numb)
{
	item *tmp = new item;
	tmp->number = numb;
	tmp->next = NULL;
	if (q->tail == NULL)
	{
		q->head = tmp;
	}
	else
	{
		q->tail->next = tmp;
	}
	q->tail = tmp;
}

int pop(queue *q)
{
	int temp_number = q->head->number;
	item *temp = q->head;
	if (q->head->next)
	{
		q->head = q->head->next;
	}
	else
	{
		q->head = NULL;
		q->tail = NULL;
	}
	delete temp;
	return temp_number;
}
*/
int is_simple(int x)    // Проверка числа на простоту
{
	int flag, d;
	if (x == 2 || x == 3)
		flag = 1;
	else
	{
		d = 2; flag = 1;
		while ((d <= x / 2) && (flag))
		{
			if (!(x % d))
				flag = 0;
			else
				d++;
		}
	}
	return flag;
}

int is_palindrome(int x)
{
	int flag = 1;
	char s[33];
	sprintf(s, "%d", x);
	int length = strlen(s);
	for (int i = 0; i < length / 2; i++)
	{
		if (s[i] != s[length - i - 1])
			flag = 0;
	}
	return flag;
}

/*bool queue_search(queue <int> q, int numb)
{
	int f = 0;
	for (int i = 0; i < q.size(); i++)
	{
		if (q.front() == numb)
			f = 1;
		q.push(q.front());
		q.pop();
	}
	if (f)
		return true;
	else
		return false;
}*/