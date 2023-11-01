#include <iostream>
using namespace std;
struct list
{
	char* word;
	list* next;
};
extern list* head;
extern list* tail;
extern void init_list();
extern bool is_empty();
extern void push_front(char*);
extern void insert(char*, int);
extern void view();