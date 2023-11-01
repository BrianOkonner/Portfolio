#pragma once

#include <iostream>

using namespace std;

class Stack
{
	struct IntStack
	{
		int item;
		IntStack*prev;
	};
	IntStack* top_int;

public:
	void InitIntStack();
	void push_int(int a);
	bool isEmptyInt();
	int TopInt();
	void PopInt();
};
