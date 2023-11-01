#include <iostream>
#include "StackL.h"
StackL::Link::Link(void *dat,Link *nxt)
{
	data=dat;
	next=nxt;
}
StackL::Link::~Link(){}
StackL::StackL(void)
{head=0;}
void StackL::push(void *dat)
{head=new Link(dat,head);}
void *StackL::pop()
{
	if(head==0)
		return 0;
	void *res=head->data;
	Link *old=head;
	head=head->next;
	delete old;
	return res;
}
void *StackL::peek()
{
	if(head==0)
	{
		std::cout<<"Empty"<<std::endl;
		return 0;
	}
	return head->data;
}
StackL::~StackL()
{
	while(head!=0)
		pop();
}