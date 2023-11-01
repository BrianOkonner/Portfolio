struct item
{
	int number;
	item *next;
};
struct queue
{
	item *head;
	item *tail;
};
/*
extern queue *simple_numbers_head = NULL;
extern queue *simple_numbers_tail = NULL;
extern queue *palindrome_numbers_head = NULL;
extern queue *palindrome_numbers_tail = NULL;
extern queue *numbers_head = NULL;
extern queue *numbers_tail = NULL;
*/
void push(queue *q, int numb);
int pop(queue *q);
int is_simple(int x);
int is_palindrome(int x);
bool queue_search(queue *q, int numb);