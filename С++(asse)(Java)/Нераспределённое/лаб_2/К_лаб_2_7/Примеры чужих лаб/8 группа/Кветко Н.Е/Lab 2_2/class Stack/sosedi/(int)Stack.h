#pragma once
struct link {
	int data;
	link*next;
};
class Stack {
private: 
	link * head;
public: 
	Stack(void);
	~Stack();
	void push(int dat);
	int pop();
	int peek();
	bool empty();
};