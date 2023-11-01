#pragma once
class STACK_C
{
private:
	struct Link
	{
		char data;
		Link* prev;
	}*head;
public:
	STACK_C(void);
	~STACK_C(void);
	void push(char dat);
	void pop();
	char top();
	bool empty();
};


