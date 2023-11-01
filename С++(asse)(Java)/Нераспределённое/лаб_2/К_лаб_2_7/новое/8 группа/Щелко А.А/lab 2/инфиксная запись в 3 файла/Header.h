#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Node {
	double val;
	Node *prev;
};

struct stack1 {
	double c;
	stack1 *prev;
};



class Stack228 {
	Node *first;
public:
	void push(char c);
	char pop();
	bool Empty();
	char top();
	Stack228();
	~Stack228();
};

//char Stack228::pop();
//void Stack228::push(char c);
//inline Stack228::Stack228();
//inline Stack228::~Stack228();
//inline char Stack228::top();
//inline bool Stack228::Empty();
int isNumber(char *word);
