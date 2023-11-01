#include "Header.h"


ArrayStack::ArrayStack(const int& _size) {
	if (_size <= 0) {
		throw 1;
	}
	else {
		p = new int[_size];
		size = _size;
		top = 0;
	}
}

ArrayStack::ArrayStack(const ArrayStack& s) {
	p = new int[s.size];
	for (int i = 0; i < s.size; i++)
		p[i] = s.p[i];
	size = s.size;
	top = s.top;
	//cout<<"Сработал конструктор копирования"<<endl;
}

ArrayStack::~ArrayStack() {
	delete[]p;
}

void ArrayStack::Push(const int& n) {
	if (isFull()) {
		throw 2;
	}
	else {
		p[top] = n;
		++top;
	}
}

int ArrayStack::Pop() {
	if (isEmpty()) {
		throw 3;
	}
	else {
		--top;
		int temp = p[top];
		return temp;
	}
}

int ArrayStack::Peek() {
	if (isEmpty()) {
		throw 3;
	}
	return p[top - 1];
}

bool ArrayStack::isEmpty() {
	return (top == NULL);
}

bool ArrayStack::isFull() {
	return (top == size);
}
