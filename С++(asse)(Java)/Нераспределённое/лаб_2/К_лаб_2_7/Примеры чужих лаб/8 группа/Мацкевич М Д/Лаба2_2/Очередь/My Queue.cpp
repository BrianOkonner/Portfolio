#include "Queue.h"
Queue::Queue()
{
	head=0;
	tail=0;
}
void Queue::Push(int x)
{
    Node *temp=new Node; //Выделение памяти для нового звена списка
    temp->value=x; //Временное запоминание принятого параметра x
    temp->next=0; //Указание, что следующее звено новосозданной структуры пока пустое

    if (!isEmpty()) //Если список не пуст 
    {
        tail->next=temp; //Указание, что следующее звено списка это новосозданная структура
        tail=temp;      
    }     else head=tail=temp; //Если список не пуст, добавление первого элемента
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

void Queue::Print(ostream  & out)		//Печать содержимого 
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