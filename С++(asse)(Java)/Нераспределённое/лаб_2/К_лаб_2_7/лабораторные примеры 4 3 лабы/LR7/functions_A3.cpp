#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <locale>
#include "functions_list.h"
using namespace std;

list *start = NULL;

void create_cycled_list(int N)
{
	for (int i = 1; i <= N; i++)
	{
		list *temp = new list;
		temp->number = N + 1 - i;
		temp->next = start;
		start = temp;
	}
	list *temp = start;
	while (temp->next)
		temp = temp->next;
	temp->next = start;
}

void show_list_n(int n)
{
	list *temp = start;
	for (int i = 0; i < n; i++)
	{
		cout << temp->number << " ";
		temp = temp->next;
	}
}

void delete_from_list()
{
	list *tmp = start->next;
	start->number = start->next->number;
	start->next = start->next->next;
	delete tmp;
}

int iosif_task(int N, int M)
{
	create_cycled_list(N);
	while (start->next != start)
	{
		for (int i = 1; i < M; i++)
		{
			start = start->next;
		}
		delete_from_list();
	}
	return start->number;
}
