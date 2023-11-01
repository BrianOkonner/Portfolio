
void InitList()							
{
	head = 0;
}

void vstavka(char* s)			
{
	spis* tmp = new spis;
	tmp->slovo = s;
	tmp->next = head;
	head = tmp;
}

void ud_spis()							
{
	while(head != 0)
	{
		spis* tmp = head;
		head = head->next;
		delete tmp;
	}
	head = NULL;
	
}