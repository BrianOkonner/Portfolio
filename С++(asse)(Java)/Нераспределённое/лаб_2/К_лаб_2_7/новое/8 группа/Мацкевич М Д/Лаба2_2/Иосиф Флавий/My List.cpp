#include "List.h"
List::List()
{
	head=0;
	tail=0;
}
void List::Push_back(int x)
{
    Node *temp=new Node; //��������� ������ ��� ������ ����� ������
    temp->value=x; //��������� ����������� ��������� ��������� x
    temp->next=0; //��������, ��� ��������� ����� ������������� ��������� ���� ������
    temp->prev=tail;
    if (!isEmpty()) //���� ������ �� ���� 
    {
        tail->next=temp; //��������, ��� ��������� ����� ������ ��� ������������� ���������
        tail=temp;      
    }     else head=tail=temp; //���� ������ �� ����, ���������� ������� ��������
} 


void List::Push_front(int x)
{
    Node *temp=new Node; //��������� ������ ��� ������ ����� ������
    temp->value=x; //��������� ����������� ��������� ��������� x
    temp->next=head; //��������, ��� ��������� ����� ������������� ��������� ���� ������
    temp->prev=0;
    if (!isEmpty()) //���� ������ �� ���� 
    {
        head->next=temp; //��������, ��� ��������� ����� ������ ��� ������������� ���������
        head=temp;      
    }     else head=tail=temp; //���� ������ �� ����, ���������� ������� ��������
} 


int List::Pop_front()
{
    int a;
	Node* temp=head;
	if(isEmpty())
		return 0;
	else
        a=temp->value;
        head=head->next;
	    delete temp;
	    return a;
}

int List::Pop_back()
{
    int a;
	Node* temp=tail;
	if(isEmpty())
		return 0;
	else
        a=temp->value;
        tail=tail->next;
	    delete temp;
	    return a;
}


int List::Front()
{
	if(!isEmpty())
		return head->value;
	else 
		return 0;
}
int List::Back()
{
	if(!isEmpty())
		return tail->value;
	else 
		return 0;
}

bool List::isEmpty()
{
    if(head==0)
		return true;
	else 
		return false;
}

List::~List()
{
    Node*temp;
	while(head)
	{
		temp=head;
		head=head->prev;
		delete temp;
	}



}