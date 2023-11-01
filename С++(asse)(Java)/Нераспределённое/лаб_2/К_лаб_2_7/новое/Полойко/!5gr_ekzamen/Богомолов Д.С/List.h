///////////////////////////////////////////список:
struct list
{
	list *prev;
	char word[80]; 
	char symbol[1];
	int position;
	int length;
};
list *head,*tail;
void init_list ()
{
	head=NULL;
	tail=NULL;
}

void push_in_list (char *slovo, char *s,int pos,int leng)
{
	list* tmp = new list;
	strcpy(tmp->word,slovo);
	strcpy(tmp->symbol,s);
	tmp->position=pos;
	tmp->length=leng;
	if (head==NULL)
	{
		tmp->prev=NULL;
		head=tmp;
		tail=tmp;
	}
	tail->prev=tmp;
	tail=tmp;
}
///////////////////////////////////////////