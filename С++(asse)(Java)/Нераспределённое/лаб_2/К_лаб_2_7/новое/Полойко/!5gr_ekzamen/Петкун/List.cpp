#include "List.h"
#include <iostream>
using namespace std;
list* head;
list* tail;
void init_list()
{
	head=NULL; tail=NULL;
}
bool is_empty()
{
	return (head==0 ? true:false);
}
void insert(char* word, int pos)
{
	list* tmp;
	tmp=new list;
	tmp->word=word;
	list* ptmp=head;
	if (ptmp==0)
	{
		tmp->next=NULL;
		head=tmp;
		tail=tmp;
		return;
	}
	int i=0;
	while ((i<pos)&&(ptmp->next))
	{
		ptmp=ptmp->next;
		i++;
	}
	if (ptmp->next==NULL)
	{
		ptmp->next=tmp;
		tmp->next=NULL;
		tail=tmp;
		return;
	}
	//tmp->next=ptmp->next; ptmp->next=tmp;
}

void push_front(char* word)
{
	list* tmp;
	tmp=new list;
	tmp->word=word;
	tmp->next=head;
	if (head==NULL) tail=tmp;
	head=tmp;
}
void view()
{
	list* tmp=head;
	while(tmp!=NULL)
	{
		cout<<tmp->word<<endl;
		tmp=tmp->next;
	}
	cout<<endl;
}