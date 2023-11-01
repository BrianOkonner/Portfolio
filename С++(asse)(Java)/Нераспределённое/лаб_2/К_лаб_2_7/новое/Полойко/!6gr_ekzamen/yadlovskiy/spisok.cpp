//yadlovskiy
struct STUDENT
{
	int yess;
	STUDENT *next;
	STUDENT *prev;
	void CREATE();
} *first=NULL, *last=NULL, *st=NULL;
void add(STUDENT *st)
{
	STUDENT *st2=NULL;
	st2=new STUDENT;
	st2->CREATE();
	if(st==last)
	{
		st2->prev=st;
		st->next=st2;
		last=st2;
	}
	else
	{
		st2->next=st->next;
		st2->prev=st;
		st->next->prev=st2;
		st->next=st2;
	}
}
int dell(STUDENT *st)
{	
//	first=last=st=new STUDENT;

	st=last->prev;
	while(st!=first)
	{
		delete(st->next);
		st=st->prev;
	}
	if (st->next!=NULL)
		delete(st->next);
	delete(st);
	st=first=last=NULL;
	return 0;
}

void STUDENT::CREATE()
{
	yess=0;
	next=NULL;
	prev=NULL;
}
//yadlovskiy