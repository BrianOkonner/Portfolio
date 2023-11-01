#include <cstring>

struct list_item
{
	list_item* next;
	char* str;
};

void add(list_item* &pHead, char* str)
{
	list_item* new_item = new list_item;
	new_item->str = new char[128];
	strcpy(new_item->str, str);
	new_item->next = 0;
	if (pHead)
	{
		list_item* pEnd = pHead;
		while (pEnd->next)
			pEnd = pEnd->next;
		pEnd->next = new_item;
	}
	else
	{
		pHead = new_item;
	}
}

list_item* remove(list_item* pHead, char* str)
{
	strcpy(str, pHead->str);
	list_item* next = pHead->next;
	delete pHead;
	return next;
}
