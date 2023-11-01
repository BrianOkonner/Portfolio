#include <iostream>
#include "Stack.h"


Stack::Stack()
{
	head=NULL;
}
void Stack::Push(int a)
{
	Node* temp=new Node;
	temp->prev=head;
	temp->value=a;
	head=temp;
}
char Stack::Pop()
{
    char a;
	Node* temp=head;
	if(isEmpty())
		return 0;
	else
        a=temp->value;
        head=head->prev;
	    delete temp;
	    return a;
}
char Stack::Top()
{
	if(!isEmpty())
		return head->value;
	else 
		return 0;
}
bool Stack::isEmpty()
{
    if(head==0)
		return true;
	else 
		return false;
}
Stack::~Stack()
{
    Node*temp;
	while(head)
	{
		temp=head;
		head=head->prev;
		delete temp;
	}



}
