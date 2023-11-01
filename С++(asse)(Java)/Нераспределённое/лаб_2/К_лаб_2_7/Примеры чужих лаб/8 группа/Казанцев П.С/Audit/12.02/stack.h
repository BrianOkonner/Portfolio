#pragma once
#ifndef my_stack_1
#define my_stack_1
class MyStack
{
	struct Link
	{
		void* data;
		Link* next;
		Link(void*, Link*);
		~Link();
	} *head;
public:
	MyStack();
	~MyStack();
	void Push(void*);
	void* Top();//Peek
	bool isEmpty();
	void Pop();
};

#endif
