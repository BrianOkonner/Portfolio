#include "Stack.h"


Stack_on_Array::Stack_on_Array(const int& _size) {
	if (_size <= 0) {
		throw 1;
	}
	else {
		p = new int[_size];
		size = _size;
		top = 0;
	}
}

Stack_on_Array::Stack_on_Array(const Stack_on_Array& s) {
	p = new int[s.size];
	for (int i = 0; i < s.size; i++)
		p[i] = s.p[i];
	size = s.size;
	top = s.top;
}

Stack_on_Array::~Stack_on_Array() {
	delete[]p;
}

void Stack_on_Array::Push(const int& n) {
	if (isFull()) {
		throw 2;
	}
	else {
		p[top] = n;
		++top;
	}
}

int Stack_on_Array::Pop() {
	if (isEmpty()) {
		throw 3;
	}
	else {
		--top;
		int temp = p[top];
		return temp;
	}
}

int Stack_on_Array::Peek() {
	if (isEmpty()) {
		throw 3;
	}
	return p[top - 1];
}

bool Stack_on_Array::isEmpty() {
	return (top == NULL);
}

bool Stack_on_Array::isFull() {
	return (top == size);
}
