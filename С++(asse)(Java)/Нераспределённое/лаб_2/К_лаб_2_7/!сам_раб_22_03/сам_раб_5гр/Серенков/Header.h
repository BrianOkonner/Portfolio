#pragma once
//Serenkov Boris; 5 gruppa; Zadacha 6;

#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

class Queue
{
public:
	Queue();
	~Queue();
	void push(const int& data);
	void pop();
	int front() const;
	bool empty() const;
	int size() const;
private:
	struct Item
	{
		int data;
		Item *prev, *next;
	};
	Item* m_head;
	Item* m_tail;
	int m_size;
};