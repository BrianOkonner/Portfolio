#pragma once
class list {
	struct node
	{
		int  item;
		node*  next;
		node*  prev;
		node();

	}*head, *tail;
public:
	list();
	~list();
	void push_front(int n);
	void push_back(int n);
	int pop_front();
	int pop_back();
	int front();
	int back();
	int size();

	void insert(int data, int pos);
	int remove(int pos);
	bool isEmpty();
	void print();
};