#include <iostream>
#include <iomanip>
#include "functions_A3.h"
using namespace std;

 MyList::MyList(int N)
{
	for (int i = 1; i <= N; i++)
	{
		Note *temp = new Note;
		temp->number = N + 1 - i;
		temp->next = head;
		head = temp;
	}
	Note *temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = head;
}

void MyList::show_list_n(int n)
{
	Note *temp = head;
	for (int i = 0; i < n; i++)
	{
		cout << temp->number << " ";
		temp = temp->next;
	}
}

void MyList::delete_from_list()
{
	Note *tmp = head->next;
	head->number = head->next->number;
	head->next = head->next->next;
	delete tmp;
}

int MyList::iosif_task(int N, int M)
{
	while (head->next != head)
	{
		for (int i = 1; i < M; i++)
		{
			head = head->next;
		}
		delete_from_list();
	}

	return head->number;
}
