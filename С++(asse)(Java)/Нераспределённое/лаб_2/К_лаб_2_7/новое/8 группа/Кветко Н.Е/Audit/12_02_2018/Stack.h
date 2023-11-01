#pragma once
struct link {
	void*data;
	link*next;
};
class Stack {
private: 
	link * head;
public: 
	Stack(void);
	~Stack();
	void push(void*dat);
	void*pop();
	void*peek();
	bool empty();
};