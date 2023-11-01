#include "MineStack.h"
Mstack::Mstack()
{
	data = 0;
	next = 0;
}
void *Mstack::pop()
{
	return (data);
	next = next->next;
}
void Mstack::push(void *dat)
{
	data = dat;
	next =this;
}
void *Mstack::top()
{
	return (data);
}
/*int Mstack::size()
{
	int i = 0;
	for(i=0;head!=0;i++)
		*this.
}*/
Mstack::~Mstack(void)
{
	while (next != 0)
		this->pop();
}
bool Mstack::empty()
{
	if (this == 0)
		return true;
	else return false;
}