#include "MineList.h"
Mlist::Mlist()
{
	head=0;
	tail=0;
}
Mlist::Link::Link(void *dat,Link *nxt)
{
	prev=0;
	next=nxt;
	data=dat;
}
Mlist::Link::Link(Link *prv,void *dat)
{
	prev=prv;
	next=0;
	data=dat;
}
void Mlist::push_front(void *dat)
{
	if(head==0)
	{
		head=new Link(dat,head);
		tail=head;
	}
	else
	{
		head=new Link(dat,head);
		head->next->prev=head;
	}
}
void Mlist::push_back(void *dat)
{
	if(tail==0)
	{
		tail=new Link(tail,dat);
		head=tail;
	}
	else
	{
		tail=new Link(tail,dat);
		tail->prev->next=tail;
	}
}
void *Mlist::pop_front()
{
	if(head==0)
		return 0;
	void *res=head->data;
	Link *old=head;
	head=head->next;
	delete old;
	if(head!=0)
		head->prev=0;
	else
		tail=0;
	return res;
}
void *Mlist::pop_back()
{
	if(tail==0)
		return 0;
	void *res=tail->data;
	Link *old=tail;
	tail=tail->prev;
	delete old;
	if(tail!=0)
		tail->next=0;
	else
		head=0;
	return res;
}
void *Mlist::back()
{
	if(tail==0)
		return 0;
	return tail->data;
}
void *Mlist::front()
{
	if(head==0)
		return 0;
	return head->data;
}
Mlist::~Mlist(void)
{
	while(head!=0)
		pop_front();
}
bool Mlist::empty()
{
	if(head==0)
		return true;
	else
	return false;
}
int Mlist::size()
{
	Link *s;
	int i;
	s=head;
	for(i=0;s!=0;i++)
		s=s->next;
	return i;
}
/*Mlist* rec()
{

}*/

