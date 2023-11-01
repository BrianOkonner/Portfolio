#ifndef _list_h
#define _list_h

const int MAX = 100;

struct list
{
	char s[MAX];
	list *next;
};

void push(list *&root, list *nver);
void pop(list *&root);

#endif