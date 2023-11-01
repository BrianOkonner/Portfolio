#include "MineStack.h"
Mstack::Mstack()
{
	head=0;
}
Mstack::Mstack(void *dat,Mstack *nxt)
{
	data=dat;
	next=nxt;
}
void Mstack::push(void *dat)
{
	head=new Mstack(dat,head);
}
void *Mstack::pop()
{
	if(head==0)
		return 0;
	void *res=head->data;
	Mstack *old=head;
	head=head->next;
	delete old;
	return res;
}
void *Mstack::top()
{
	if(head==0)
		return 0;
	return head->data;
}
Mstack::~Mstack()
{
	while(head!=0)
		pop();
}
bool Mstack::empty()
{
	if(head==0)
		return true;
	else
	return false;
}
int Mstack::size()
{
	Mstack *s;
	int i;
	s=head;
	for(i=0;s!=0;i++)
		s=s->next;
	return i;
}

