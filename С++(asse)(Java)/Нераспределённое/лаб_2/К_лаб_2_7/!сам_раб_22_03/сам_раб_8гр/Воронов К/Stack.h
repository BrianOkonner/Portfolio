#pragma once
#include<iostream>
class Stack
{
	struct List {
		int value;
		List * next;
	}*top;
public:
	Stack() {
		top = NULL;
	}
	~Stack() {
		List *p;
		p = top;
		while (top != NULL) {
			top = top->next;
			delete p;
		}
	}
	void Push(int a) {
		List *p = new List;
		p->value = a;
		if (top == NULL) {
			top = p;
			p->next = NULL;
		}
		else {
			p->next = top;
			top = p;
		}
	}
	bool IsEmpaty() {
		if (top == NULL)
			return 1;
		else return 0;
	}
	double Top() {
		return top->value;
	}
	void Pop() {
		List *p;
		p = top;
		top = top->next;
		delete p;
	}
	int Size() {
		List *p;
		int a = 0;
		p = top;
		while (p != NULL) {
			p = p->next;
			a++;
		}
		return a;
	}
	List * Max() {
		List *p, *a;
		p = top;
		a = top;
		while (p->next != NULL) {
			p = p->next;
			if (p->value > a->value)
				a = p;
		}
		return a;
	}
	List * Min() {
		List *p, *a;
		p = top;
		a = top;
		while (p->next != NULL) {
			p = p->next;
			if (p->value <= a->value)
				a = p;
		}
		return a;
	}
	void del(List *a) {
		List* p=top;
		while (p->next != a) {
			p = p->next;
		}
		p->next = a->next;
		delete a;
	}
};