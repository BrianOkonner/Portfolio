#include "Minequeue.h"
Mqueue::Mqueue()
{
	data = 0;
	next = 0;
}
Mqueue::Mqueue(void *dat,Mqueue *nxt)
{
	data=dat;
	next=nxt;
}
Mqueue::Mqueue(Mqueue *nxt)
{
	next=nxt;
}
void Mqueue::push(void *dat)
{
	next=new Mqueue(dat,next);
}
void *Mqueue::pop()
{
	if(next==0)
		return 0;
	Mqueue **s;
	s=&next;
	while((*s)->next!=0)
		s=&((*s)->next);
	void *res=(*s)->data;
	delete (*s)
>next;
	*s=0;
	//найти ссылку на последний и пред некст
//	Mqueue *old=s;
//	next=next->next;
//	delete old;
	return res;
}
void *Mqueue::back()
{
	if(next==0)
		return 0;//(void*)
	return next->data;
}
void *Mqueue::front()
{
	if(next==0)
		return 0;
	Mqueue *s;
	int i;
	s=next;
	for(i=0;s->next!=0;i++)
		s=s->next;
	return (s->data);
}
Mqueue::~Mqueue()
{
	while(next!=0)
		pop();
	delete this->next;
}
bool Mqueue::empty()
{
	if(next==0)
		return true;
	else
	return false;
}
int Mqueue::size()
{
	Mqueue *s;
	int i;
	s=next;
	for(i=0;s!=0;i++)
		s=s->next;
	return i;
}
/*Mqueue* rec()
{

}*/

