#pragma once
#ifndef p123
#define p123
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
