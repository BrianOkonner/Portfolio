#include <iostream>
#include <functionsnames.h>
using namespace std;
void push(queue *a,int n)    //свой "пуш"
{
	node*p=new node;
	p->next=a->tail;
	p->number=n;
	if(a->tail!=NULL)	
		a->tail->prev=p; 
	else a->head=p;
	p->prev=NULL;
	a->tail=p;
}
int pop(queue*a)      //свой "поп"
{
	int c=a->head->number;
	node *p=a->head;
	a->head=a->head->prev;
	if(a->head!=NULL) a->head->next=NULL;
	else a->tail=NULL;
	delete p;
	return c;
}