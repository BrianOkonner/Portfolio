#include <iostream>
#include <cmath>
#include <fstream>
#include "stak.h"
// конструктор Стека
Stack::Stack(int maxSize) :
	size(maxSize)
{
	stackPtr = new int[size];
	top = 0;
}
// функция деструктора Стека

Stack::~Stack()
{
	delete[] stackPtr;
}

// функция добавления элемента в стек

void Stack::push(const int &value)
{
	if (top < size)
		stackPtr[top++] = value;
}
// вернуть элемент стека стека

int Stack::Top()
{
	return stackPtr[top - 1];
}
void Stack::pop()
{
	top--;
}
bool Stack::Empty()
{
	return top == 0;
}