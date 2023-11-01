#include "list.h"

void push(list *&root, list *nver)
{
	if (!root) root = nver;
	else
	{
		nver->next = root;
		root = nver;
	}
}

void pop(list *&root)
{
	if (!root->next) return;
	list *tmp = root->next;
	delete root;
	root = tmp;
}