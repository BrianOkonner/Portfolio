#include "Queue.h"

Queue_on_Array::Queue_on_Array(int size1) {
	if (size1 <= 0) {
		throw 2;
	}
	else {
		p = new int[size1];
		size = size1;
		n = 0;
		head = 0;
		tail = 0;
	}
}

Queue_on_Array::Queue_on_Array(const Queue_on_Array& q) {
	p = new int[q.size];
	for (int i = 0; i < q.size; i++)
		p[i] = q.p[i];
	size = q.size;
	n = q.n;
	tail = q.tail;
	head = q.head;
	//cout << "Сработал конструктор копирования\n";
}

Queue_on_Array::~Queue_on_Array() {
	delete[]p;
}

void Queue_on_Array::push_back(int val) {
	if (isFull()) {
		throw 3;
	}
	else {
		p[tail] = val;
		++tail;
		++n;
		tail %= (size);
	}
}

int Queue_on_Array::front() {
	return p[(tail + size - 1) % size];
}

int Queue_on_Array::pop_front() {
	if (isEmpty()) {
		throw 4;
	}
	else {
		int temp = p[head];
		head++;
		--n;
		head %= (size);
		return temp;
	}
}

bool Queue_on_Array::isEmpty() {
	return (n == 0);
}

bool Queue_on_Array::isFull() {
	return (n == size);
}

