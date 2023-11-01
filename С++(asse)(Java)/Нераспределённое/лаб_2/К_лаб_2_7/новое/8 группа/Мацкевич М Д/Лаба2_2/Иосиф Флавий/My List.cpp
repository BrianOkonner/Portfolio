#include "List.h"
List::List()
{
	head=0;
	tail=0;
}
void List::Push_back(int x)
{
    Node *temp=new Node; //¬ыделение пам€ти дл€ нового звена списка
    temp->value=x; //¬ременное запоминание прин€того параметра x
    temp->next=0; //”казание, что следующее звено новосозданной структуры пока пустое
    temp->prev=tail;
    if (!isEmpty()) //≈сли список не пуст 
    {
        tail->next=temp; //”казание, что следующее звено списка это новосозданна€ структура
        tail=temp;      
    }     else head=tail=temp; //≈сли список не пуст, добавление первого элемента
} 


void List::Push_front(int x)
{
    Node *temp=new Node; //¬ыделение пам€ти дл€ нового звена списка
    temp->value=x; //¬ременное запоминание прин€того параметра x
    temp->next=head; //”казание, что следующее звено новосозданной структуры пока пустое
    temp->prev=0;
    if (!isEmpty()) //≈сли список не пуст 
    {
        head->next=temp; //”казание, что следующее звено списка это новосозданна€ структура
        head=temp;      
    }     else head=tail=temp; //≈сли список не пуст, добавление первого элемента
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