#include "stdafx.h"
#include "Spisok.h"

	void InitList() /* конструктор */
	{
		head = 0;
		tail = 0;
	}

	void RemoveList() /* деструктор */
	{
		while(head != 0)
		{
			elem* tmp = head;
			head = head->next;
			delete tmp;
		}
		head = 0;
		tail = 0;
	}

	void add_front(int newst) /* включить элемент в начало списка */
	{
		elem* tmp = new elem;
		tmp->value = newst;
		tmp->prev = 0;
		tmp->next = head;
		if(head)
			head->prev = tmp;
		else
			tail = tmp;
			head = tmp;
	}

	void add_back(int newst) /* включить элемент в конец списка */
	{
		elem* tmp = new elem;
		tmp->value = newst;
		tmp->next = 0;
		tmp->prev = tail;
		if(tail)
			tail->next = tmp;
		else
			head = tmp;
		tail = tmp;
	}

	void del_front() /* исключить элемент из начала списка */
	{
		if(head)
		{
			elem *tmp = head;
			if(head->next)
				head->next->prev = 0;
			else
				tail = 0;
			head = head->next;
			delete tmp;
		}
	}
	int get_front()
	{
		return head->value;
	}
	void del_back() /* исключить элемент из конца списка */
	{
		if(tail)
		{
			elem *tmp = tail;
			if(tail->prev)
				tail->prev->next = 0;
			else
				head = 0;
			tail = tail->prev;
			delete tmp;
		}
	}
	int get_back()
	{
		return tail->value;
	}

	void insert(int data, int pos) /* вставить в позицию pos+1 */
	{
		elem* tmp = new elem;
		tmp->value = data;
		elem* ptmp = head;
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
		if (ptmp->next == 0)
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
	}

	void del_poz(int pos) /* удалить элемент c позиции pos*/
	{
		elem* ptmp = head;
		for(int i = 1; i<pos; i++)
		{			
			ptmp = ptmp->next;
			if(ptmp == 0)
				return;
		}
		if (ptmp->next!=0)
			ptmp->next->prev = ptmp->prev;
		else
			tail=ptmp->prev;
		if(ptmp->prev != 0)
			ptmp->prev->next = ptmp->next;
		else
			head=ptmp->next;
		delete ptmp;
	}
	int get_pos(int pos)
	{
		elem* ptmp = head;
		for(int i = 1; i<pos; i++)
		{
			if(ptmp == 0)
				return 0;
			ptmp = ptmp->next;
		}
		return ptmp->value;
	}

	bool isEmpty() /* пустой список? */
	{
		return head == 0;
	}


