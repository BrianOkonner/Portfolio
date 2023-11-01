#define _CRT_SECURE_NO_WARNINGS
class MyQueue
{
	class item
	{
	public:
		int number;
		item *next;
		item(int, item *);//+
		~item();//+
	}*head, *tail;
public:
	MyQueue();//+
	~MyQueue();
	bool isEmpty();//+
	void push(int);//+
	void pop();//+
	int front();//+
	int back();//+
	bool queue_search(int);//+
};
int is_simple(int x);
int is_palindrome(int x);
/*
extern queue *simple_numbers_head = NULL;
extern queue *simple_numbers_tail = NULL;
extern queue *palindrome_numbers_head = NULL;
extern queue *palindrome_numbers_tail = NULL;
extern queue *numbers_head = NULL;
extern queue *numbers_tail = NULL;
*/
//void push(MyQueue *q, int numb);
//int pop(MyQueue *q);

//bool queue_search(MyQueue *q, int numb);