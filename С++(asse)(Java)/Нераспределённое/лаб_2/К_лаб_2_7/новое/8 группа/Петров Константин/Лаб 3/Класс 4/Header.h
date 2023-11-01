#pragma once

#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

class ArrayQueue {
	int size;
	int *p;
	int head;
	int tail;
	int n;
public:
	ArrayQueue(int size1);
	ArrayQueue(const ArrayQueue& q);
	~ArrayQueue();
	void Push(int val);
	int Peek();
	int Pop();
	bool IsEmpty();
	bool IsFull();
};


void Flavii();
void PaperSheet();
void Road();