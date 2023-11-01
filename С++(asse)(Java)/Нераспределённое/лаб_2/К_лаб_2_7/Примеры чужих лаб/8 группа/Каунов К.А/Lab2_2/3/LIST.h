#pragma once
class List
{
	struct Link
	{
		int data;
		Link *next;
		Link *prev;
	}*tail, *head;
	int i;
public:
	List(void);
	~List(void);
	void push_back(int dat);
	void push_front(int dat);
	void pop_front();
	void pop_back();
	bool empty();
	int front();
	int back();
	int size();
};