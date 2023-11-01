#pragma once

#include <iostream>

using namespace std;

class List
{
private:
	int *p;
	int size;
	int top;
	int tail;
public:
	List(int n);

	void Push_Front(int n);

	void Push_Back(int n);

	int Top();

	int Tail();

	void Pop_Front();

	int Size();

	void Push_pos(int n, int pos);

	void Insert();

	void Print();
};
