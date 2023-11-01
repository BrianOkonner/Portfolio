#pragma once
class Queue
{
	struct Link
	{
		
		int data;
		Link *next;
		Link *prev;
	}*tail, *head;
	int i ;
public:
	Queue(void);
	~Queue(void);
	void push(int dat);
	void pop();
	bool empty();
	int front();
	int back();
	int size();
};