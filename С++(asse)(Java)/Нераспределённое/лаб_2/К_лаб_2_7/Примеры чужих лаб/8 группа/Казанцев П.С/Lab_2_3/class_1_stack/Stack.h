#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;

class Stack_on_Array {
	int size;
	int *p;
	int top;
public:
	Stack_on_Array(const int& _size);
	Stack_on_Array(const Stack_on_Array& s);
	~Stack_on_Array();
	void Push(const int& n);
	int Pop();
	int Peek();
	bool isEmpty();
	bool isFull();
};

void Neighbors();
void Paper();
void Road();