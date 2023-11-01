#pragma once

class Queue
{
private:
	struct queue
	{
		int data;
		queue* next;
	};
	queue* head,*tail;
public:
	Queue();
	~Queue();
	void push(int n);
	int pop();
	bool isEmpty();
};
