#include "LIST.h"
#include"Header.h"
List::List() 
{
	head = NULL;
}
int List::size()
{
	if (isEmpty()) return 0;
	node* temp = new node;
	temp = head; int i = 0;
	while (true)
	{
		if (temp->next == NULL)
		{
			 break;
		}
		else i++;
		temp = temp->next;
	}
	return i+1;
}
List::List(const List& lst)
{
	node * tmp = lst.head;
	while (tmp)
	{
		push_back(tmp->item);
		tmp = tmp->next;
	}
}
bool List::isEmpty() 
{
	if(head==0)
		return 1;
	return 0;
}
void List::push_head(int n) 
{
	node *temp = new node;
	temp->item = n;
	temp->next = head;
	head = temp;
}
void List::push_back(int n) 
{
	node *temp = new node;
	temp->item = n;
	temp->next = NULL;
	node *temp1 = head;
	if (isEmpty() == 0)
	{
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	else
	{
		head = temp;
	}
}
List::node* List::remove_head()
{
	if (!isEmpty())
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
	return head;
}
List::node* List::remove_tail()
{
	if (!isEmpty())
	{
		node *temp1 = head;
		node *temp2 = head->next;
		if (temp2 == NULL)
		{
			delete temp1;
			head = NULL;
		}
		else
		{
			while (temp2->next != 0)
			{
				temp2 = temp2->next;
				temp1 = temp1->next;
			}
			delete temp2;
			temp1->next = NULL;
		}
	}
	return head;
}
int List::top() 
{
	return head->item;
}
List::~List() 
{
	while (!isEmpty())
		remove_head();
}