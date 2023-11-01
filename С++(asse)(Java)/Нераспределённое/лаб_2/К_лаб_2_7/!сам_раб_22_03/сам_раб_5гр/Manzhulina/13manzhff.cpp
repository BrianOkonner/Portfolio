#include<iostream>
#include"13manzhf.h"
using namespace std;
List::List()            /* конструктор */
{
head=0;
tail=0;
}
List::~List()	             /* деструктор */
{
	node*t=head;
	node*d=head;
while(t)
{
d=t;
t=t->p;
delete d;
}
}

void List::ins(const int& n)  /* включить элемент в список */
{

	if(tail==0)
	{
	node*t=new node;
	t->item=n;
	t->p=0;
	t->n=0;
	head=t;
	tail=t;
	}
	else
	{
		
		node*temp=new node;
temp->item=n;
temp->p=0;
temp->n=tail;
tail->p=temp;
tail=temp;
if(head->p==temp)
head->p=tail;
	}
}


void List::change()
{
	if(head&&head->p)
	{
		node*a=head;
		node*b=head->p;
		node*c;
		node*d;
		head=b;
	while(a&&a->p)
	{
	  b=a->p;
		a->p=b->p;
		b->n=a->n;
		a->n=b;
		b->p=a;
		if(b->n) b->n->p=b;
		if(a->p) a->p->n=a;
		a=a->p;
	}
	}
}

int List:: del()	       /* исключить элемент из списка */
{
	if(isEmpty())
		return -1;
	else 
	{node*temp=head;
	if(head->p==0)
	{
		int aa=head->item;
	head=0;
	return aa;
	}
	else
	{while(temp->p->p)
temp=temp->p;

	tail=temp;
	int a=tail->p->item;
	delete tail->p;
	tail->p=0;
	return a;}}

}


bool List::isEmpty()   /* пустой список? */
{if(head==0) return 1;
else return 0;}//Дополнительно
void List::push_head(int n)		//включить элемент в начало списка
{
node*t=new node;
t->item=n;
t->p=head;
head=t;
}

void List:: print ()			//Печать содержимого списка
{
	if(isEmpty())
		cout<<"Empty";
	else
	{
		node*temp=head;
while(temp)
{
cout<<temp->item<<endl;
temp=temp->p;
}
	}
}

