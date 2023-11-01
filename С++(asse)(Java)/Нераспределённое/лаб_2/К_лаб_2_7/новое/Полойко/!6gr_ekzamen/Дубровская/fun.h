bool poisk_ch (char *s);
int kuby (int a);
int *sort_m(int *a, int n);
struct element
{
	int item;
	element *next;
	element *prev;
};
struct spisok
{
	element *head;
	element *tail;

	void init()
	{
		head = NULL;
		tail = NULL;
	}

	void push_b(int data)//vstavka v nachalo
	{
		element *tmp = new element;
		tmp->item = data;
		tmp->prev=head;
		tmp->next=NULL;
		if (head == NULL)
		{
			head = tmp;
			head->prev = NULL;
			head->next = NULL;
			head = tail;
		}
		else
		{
			head->next=tmp;
		}
		head = tmp;
	}

	void push_e(int data)//vstavka v konec
	{
		element *tmp = new element;
		tmp->item= data;
		tmp->prev=NULL;
		tmp->next=tail;
		if (tail == NULL)
		{
			head = tmp;
		}
		else
			tail->prev=tmp;
		tail = tmp;
	}

	int pop_b()//udalenie is nachala
	{
		int data = head->item;
		element *tmp = head;
		if (head->prev)
			head->prev->next = NULL;
		else
			tail = NULL;
		head = head->prev;
		delete tmp;
		return data;
	}

	int pop_e()//udalenie is konca
	{
		int data = tail->item;
		element *tmp = tail;
		if(tail->next)
			tail->next->prev = NULL;
		else
			head = NULL;
		tail = tail->next;
		delete tmp;
		return data;
	}

	void push_pos(int data, int pos)
	{
		element *tmp = new element;
		tmp->item = data;
		element *t = head;
		if(t == NULL)
		{
			tmp->next = NULL;
			tmp->prev = NULL;
			head = tmp;
			tail = tmp;
			return ;
		}
		else
		{
			for ( int i = 0; i < pos; i++)
			{
				if( t->prev == NULL)
				{
					t->prev = tmp;
					tmp->prev = NULL;
					tmp->next = t;
					tail = tmp;
					return;
				}
				t = t->prev;
			}
			t->next->prev = tmp;
			tmp->next = t->next;
			t->next = tmp;
			tmp->prev = t;
		}

	}

	int pop_pos(int pos)
	{
		element *tmp = head;
		for(int i = 0; i<pos; i++)
		{
			if (tmp == NULL)
				return 0;
			tmp = tmp->prev;
		}
		tmp->next->prev = tmp->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = tmp->next;
		int data = tmp->item;
		delete tmp;
		return data;
	}
		
	bool isEmpty()					
	{
		return head == 0;
	}
};