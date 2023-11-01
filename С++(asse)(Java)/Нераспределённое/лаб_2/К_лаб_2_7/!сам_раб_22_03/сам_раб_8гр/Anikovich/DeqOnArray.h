#pragma once
class DeqOnArray
{
	int *p;
	int size;
	int top;
public:
	DeqOnArray();
	~DeqOnArray();
	int sizeOfStack();
	int front();
	int back();
	int popFront();
	int popBack();
	void pushFront(int);
	void pushBack(int);
	bool isEmpty();
	void sortAboveCompare();
};

