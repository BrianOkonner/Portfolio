#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;

class ArrayStack {
	int size;
	int *p;
	int top;
public:
	ArrayStack(const int& _size);
	ArrayStack(const ArrayStack& s);
	~ArrayStack();
	void Push(const int& n);
	int Pop();
	int Peek();
	bool isEmpty();
	bool isFull();
};