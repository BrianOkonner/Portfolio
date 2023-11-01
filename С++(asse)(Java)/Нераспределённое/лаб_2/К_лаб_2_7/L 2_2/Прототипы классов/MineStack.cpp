#include "MineStack.h"
Mstack::Mstack()
{
	data = 0;
	next = 0;
}
Mstack::Mstack(void *dat,Mstack *nxt)
{
	data=dat;
	next=nxt;
}
void Mstack::push(void *dat)
{
	next=new Mstack(dat,next);
}
void *Mstack::pop()
{
	if(next==0)
		return 0;
	void *res=next->data;
	Mstack *old=next;
	next=next->next;
//	delete old;
	return res;
}
void *Mstack::top()
{
	if(next==0)
		return 0;
	return next->data;
}
Mstack::~Mstack()
{
	while(next!=0)
		pop();
}
bool Mstack::empty()
{
	if(next==0)
		return true;
	else
	return false;
}
int Mstack::size()
{
	Mstack *s;
	int i;
	s=next;
	for(i=0;s!=0;i++)
		s=s->next;
	return i;
}

