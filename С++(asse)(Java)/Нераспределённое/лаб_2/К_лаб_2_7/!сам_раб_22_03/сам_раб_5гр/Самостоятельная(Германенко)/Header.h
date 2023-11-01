#pragma once
class my_stack
{
	int last;
	int *data;
	int max_elem;

public:

	int top(void);
	void pop(void);
	void push(int);
	bool empty(void);

	my_stack();
	my_stack(int);
	~my_stack();
};
