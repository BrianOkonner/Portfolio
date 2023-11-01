/*
    Spisok.h
	  Работа со списками
	                     */

typedef struct _node
{
	long value;
	struct _node *next, *prev;
} node;

typedef struct
{
	node *head, *tail;
	node *cur;
} list;

void create_list(list *s);
void destroy_list(list *s);
void insert(list *s, long val); /* Вставка в начало */

void start_traverse(list *s);
bool go_next(list *s, long *val);
