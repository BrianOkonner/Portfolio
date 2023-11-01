#pragma once

#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <iomanip>
using namespace std;

class Queue_on_Array {
	int size;
	int *p;
	int head;
	int tail;
	int n;
public:
	Queue_on_Array(int size1);
	Queue_on_Array(const Queue_on_Array& q);
	~Queue_on_Array();
	void push_back(int val);
	int front();
	int pop_front();
	bool isEmpty();
	bool isFull();
};


void Iosif();
void Paper();
void Road();