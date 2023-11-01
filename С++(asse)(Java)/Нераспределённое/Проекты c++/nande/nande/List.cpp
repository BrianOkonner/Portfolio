#include"List.h"-++
List::List()							/* конструктор */
{
	head = 0;
}

List::~List()							/* деструктор */
{
	while(head != 0)
	{
		node* tmp = head;
		head = head->p;
		delete tmp;
	}
	head = 0;
}
void List::push_head(int n)		
{
	node* tmp = new node;
	tmp->item = n;
	tmp->p = head;
	head = tmp;
}
void List::push_back(int n)		
{
	node **tmp;
	tmp=&head;
	if(head)
	{
		while((*tmp)->p!=0)
			tmp=&((*tmp)->p);
		node *tmp2 = new node;
		tmp2->item = n;
		tmp2->p=0;
		(*tmp)->p=tmp2;
	}
	else
	{
		node *tmp2 = new node;
		tmp2->item = n;
		tmp2->p=0;
		head=tmp2;
	}
}
List::node* List::remove_tail()		
{
	if(head)
	{
		node **tmp;
		tmp=&head;
		while((*tmp)->p!=0)
			tmp=&((*tmp)->p);
		node *res=new node;
		res=*tmp;
		*tmp=0;
		return (res);
	}
	return 0;
}
List::node* List::remove_head()					
{
	if(head)
	{
		node *tmp = head;
		head = head->p;
		node *res=new node;
		res=tmp;
		tmp=0;
		return (res);
	}
	return 0;
}
bool List::isEmpty()					/* пустой список? */
{
	return head == 0;
}
int List::size()
{
	node **tmp;
	tmp=&head;
	if(head)
	{
		int i;
		for(i=0;(*tmp)!=0;i++)
			tmp=&((*tmp)->p);
		return i;
	}
	return 0;
}
//void insert(int data, int pos)	/* вставить в позицию pos+1 */
/*{
	node* tmp = new node;
	tmp->item = data;
	node* ptmp = head;
	if(ptmp == 0)
	{
		tmp->next = 0;
		tmp->prev = 0;
		head = tmp;
		tail = tmp;
		return;
	}
    int i = 0;
	while ((i<pos)&&(ptmp->next))
	{
		ptmp = ptmp->next;
		i++;
	}
    if  (ptmp->next == 0)
		{
			ptmp->next = tmp;
			tmp->prev = ptmp;
			tmp->next = 0;
			tail = tmp;
			return;
		}
	
	ptmp->next->prev = tmp;
	tmp->next = ptmp->next;
	ptmp->next = tmp;
	tmp->prev = ptmp;
}*/
//int remove(int pos)			/* удалить элемент c позиции pos*/
/*{
	node* ptmp = head;
	for(int i = 0; i<pos; i++)
	{
		if(ptmp == 0)
		{
			return 0;
		}
		ptmp = ptmp->next;
	}
	ptmp->next->prev = ptmp->prev;
	if(ptmp->prev != 0)
		ptmp->prev->next = ptmp->next;
	int res = ptmp->item;
	delete ptmp;
	return res;
}*/
/*void print ()			//Печать содержимого стека
{
	node* temp = head;
	
	while (temp)
	{
		cout<<temp->item<<endl;
		temp = temp->next;
	}
}*/