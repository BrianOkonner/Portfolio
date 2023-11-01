/*
   Spisok.cpp - организация списков
                                      */
#include "Spisok.h"

#include <stdlib.h>

void create_list(list *s)
{
	s->head = s->tail = NULL;
}

void destroy_list(list *s)
{
	node *c, *t;

	c = s->head;

	while (c)
	{
		t = c->next;
		free(c);
		c = t;
	}
}

void start_traverse(list *s)
{
	s->cur = s->tail;
}

bool go_next(list *s, long *val)
{
	if (s->cur == NULL)
		return false;

	*val = s->cur->value;
	s->cur = s->cur->prev;
	return true;
}

void insert(list *s, long val)
{
	node *cn = (node *) malloc(sizeof(node));

	cn->value = val;
	cn->next = s->head;
	cn->prev = NULL;

	if (s->head) s->head->prev = cn;
	else s->tail = cn;

	s->head = cn;
}
