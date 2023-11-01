#include "list.h"
//#include <iostream>
using namespace std;
List::List()
{
	head = NULL;
}

int List::size()
{
	List::node* temp;
	if (!head)
		throw 3;
	int t = 1;
	temp = head;
	while (temp->next != NULL)
	{
		t++;
		temp = temp->next;
	}
	return t;
}

List::List(const List& lst)
{
	if (lst.head)
	{
		List::node * new_head = new List::node[1];
		new_head->item = lst.head->item;
		new_head->next = NULL;
		List::node * temp = lst.head;
		List::node * list_copy = new_head;
		while (temp->next)
		{
			temp = temp->next;
			List::node * temp2 = new List::node[1];
			temp2->item = temp->item;
			temp2->next = NULL;
			list_copy->next = temp2;
			list_copy = list_copy->next;
		}
		this->head = new_head;
	}
	else
		this->head = NULL;
}

bool List::isEmpty()
{
	if (!head)
		return true;
	else
		return false;
}

void List::push_head(int n)
{
	List::node * new_head = new List::node[1];
	new_head->item = n;
	new_head->next = head;
	head = new_head;
}

void List::push_back(int n)
{
	List::node *temp = head;
	List::node * new_elem = new List::node[1];
		new_elem->item = n;
		new_elem->next = NULL;
	if (head)
	{
		while (temp->next)
			temp = temp->next; // temp - указатель на последний элемент
		temp->next = new_elem;
	}
	else
	{
		head = new_elem;
	}
}

List::node* List::remove_head()
{
	if (head)
	{
		List::node *temp = head;
		head = head->next;
		delete temp;
	}
	return head;
}

List::node* List::remove_tail()
{
	if (head)
	{
		List::node *temp = head;
		
		if (!head->next)
		{
			head = NULL;
			delete temp;
		}
		else
		{
			List::node *temp2 = head->next;
			while (temp2->next)
			{
				temp2 = temp2->next;
				temp = temp->next;
			}
			temp->next = NULL;
			delete temp2;
		}
	}
	return head;
}
int List::front()
{
	return head->item;
}
List::node* List::search()
{
	if (head)
	{
		List::node *temp = head;
		while (temp->next && (temp->item % 2 != 0))
		{
			temp = temp->next;
		}
		if (temp->item % 2 == 0)
			return temp;
		else
			return NULL;
	}
	else
		return NULL;
}

void List::remove(node* adr)
{
	if (head)
	{
		List::node *temp = head;
		if (temp == adr)
		{
			head = head->next;
			delete temp;
		}
		else
		{
			while (temp->next && temp->next != adr)
				temp = temp->next;
			if (temp->next)
			{
				temp->next = adr->next;
				delete adr;
			}
			else
			{
				throw 4;
				cout << "No element with this address" << endl;
			}
		}
	}
}

void List::print()
{
	List::node *temp = head;
	while (temp)
	{
		cout << temp->item << " ";
		temp = temp->next;
	}
	cout << endl;
}

int List::remove(int pos)
{
	int t = 0;
	List::node *temp = head;
	if (head)
	{
		for (int i = 0; i < pos - 2 && temp->next; i++)
		{
			temp = temp->next;
		}
		if (temp->next)
		{
			t = temp->next->item;
			List::node *temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
		}
	}
	else
		throw 3;
	return t;
}

void List::delchet()
{
	if (head)
	{
		List::node *temp = head;
		while (temp && temp->next)
		{
			List::node *temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
			temp = temp->next;
		}
	}
	else
		throw 3;
}

int List::smin()
{
	if (head)
	{
		List::node *temp = head;
		int min = temp->item;
		while (temp->next)
		{
			temp = temp->next;
			if (temp->item < min)
				min = temp->item;
		}
		return min;
	}
	else
		throw 3;
}

void List::invert()
{
	if (head)
	{
		List::node *temp = head;
		int razm = this->size();
		razm = (int)(razm / 2. + 0.5);
		for (int i = 0; i < razm; i++)
		{
			temp->item = temp->item * (-1);
			temp = temp->next;
		}
	}
	else
		throw 3;
}

List::~List()
{
	while (head)
		remove_head();
}