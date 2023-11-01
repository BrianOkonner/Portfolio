#pragma once
class STACK_I
{
private:
	struct Link
	{
		int data;
		Link* prev;
	}*head;
public:
	STACK_I(void);
	~STACK_I(void);
	void push(int dat);
	void pop();
	char top();
	bool empty();
};


