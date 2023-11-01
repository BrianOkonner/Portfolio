#include "Queue.h"
Queue::Queue()
{
	head=0;
	tail=0;
}
void Queue::Push(int x)
{
    Node *temp=new Node; //��������� ������ ��� ������ ����� ������
    temp->value=x; //��������� ����������� ��������� ��������� x
    temp->next=0; //��������, ��� ��������� ����� ������������� ��������� ���� ������

    if (!isEmpty()) //���� ������ �� ���� 
    {
        tail->next=temp; //��������, ��� ��������� ����� ������ ��� ������������� ���������
        tail=temp;      
    }     else head=tail=temp; //���� ������ �� ����, ���������� ������� ��������
} 

char Queue::Pop()
{
    char a;
	Node* temp=head;
	if(isEmpty())
		return 0;
	else
        a=temp->value;
        head=head->next;
	    delete temp;
	    return a;
}
char Queue::Front()
{
	if(!isEmpty())
		return head->value;
	else 
		return 0;
}
char Queue::Back()
{
	if(!isEmpty())
		return tail->value;
	else 
		return 0;
}

bool Queue::isEmpty()
{
    if(head==0)
		return true;
	else 
		return false;
}

bool Queue::Find(int  a)
{
	Node* temp=head;
	if(isEmpty())  return 0;

    while (temp->next  && temp->value!= a   ) 
		temp=temp->next;

	if (temp->value==a) return 1;
	else return 0;
}

void Queue::Print(ostream  & out)		//������ ����������� 
{Node* temp=head;
	while (temp->next)
	{
		out <<temp->value<<' ';
		temp=temp->next;		
	}
	out<<temp->value;
}

Queue::~Queue()
{
    Node*temp;
	while(head)
	{
		temp=head;
		head=head->next;
		delete temp;
	}



}