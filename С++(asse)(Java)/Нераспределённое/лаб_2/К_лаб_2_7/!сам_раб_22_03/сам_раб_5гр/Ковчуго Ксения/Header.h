#pragma once
#include <fstream>
#include <conio.h>
#include <iostream>
using namespace std;

struct Node {
	int Num;
	Node *Prev;
};

class MyStack {
	Node *Top;
	int Size;
public:
	MyStack() { Size = 0; };
	void push(int data);
	int pop();
	int size() { return Size; };
	int FindMax();
	int FindMin();
};
