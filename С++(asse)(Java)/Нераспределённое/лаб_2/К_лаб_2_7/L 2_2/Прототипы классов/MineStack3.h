#pragma once
#ifndef STACK10
#define STACK10
class Mstack
{
	void *data;
	Mstack *next;
public:
	Mstack();
	~Mstack(void);
	void *pop();
	void push(void *dat);
	void *top();
	bool empty();
//	int size();
};
#endif