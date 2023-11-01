#pragma once
#include <iostream>
using namespace std;

/*template <class T>
class queue 
{
	struct node 
	{
		T d;
		node* next;
	} *ptr;
public:
	queue()
	{
		ptr = NULL;
	}
	~queue() {
		while (!empty()) pop();
	}
	void  push(T d) {
		node* e = new node();
		e->d = d;
		if (!ptr) {
			ptr = e;
			ptr->next = ptr;
		}
		else {
			e->next = ptr->next;
			ptr = ptr->next = e;
		}
	}
	T& front(void) {
		return ptr->next->d;
	}
	void  pop() {
		if (ptr == ptr->next) {
			delete ptr;
			ptr = NULL;
			return;
		}
		else {
			node* tmp = ptr->next;
			ptr->next = tmp->next;
			delete tmp;
			tmp = NULL;
		}
	}
	int  size()
	{
		int counter = 0;
		node* iter = ptr->next;
		do {
			counter++;
			iter = iter->next;
		} while (iter != ptr->next);
		return counter;
	}
	bool empty() {
		return (ptr == 0);
	}
};*/

class Queue {
	static const int SIZE = 100;
	int *queue;
	int frnt, rear;
public:
	Queue();
	void push(int num);
	void out();
	int size();
	void pop();
	int front();
	int back();
};


bool Prime(int x);
bool is_palindrom(int x);


