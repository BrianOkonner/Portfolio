#include "Header.h"



ArrayQueue::ArrayQueue(int size1) {
	if (size1 <= 0) {
		throw 1;
	}
	else {
		p = new int[size1];
		size = size1;
		n = 0;
		head = 0;
		tail = 0;
	}
}

ArrayQueue::ArrayQueue(const ArrayQueue& q) {
	p = new int[q.size];
	for (int i = 0; i < q.size; i++)
		p[i] = q.p[i];
	size = q.size;
	n = q.n;
	tail = q.tail;
	head = q.head;
	//cout << "Сработал конструктор копирования\n";
}

ArrayQueue::~ArrayQueue() {
	delete[]p;
}

void ArrayQueue::Push(int val) {
	if (IsFull()) {
		throw 2;
	}
	else {
		p[tail] = val;
		++tail;
		++n;
		tail %= (size);
	}
}

int ArrayQueue::Peek() {
	return p[(tail + size - 1) % size];
}

int ArrayQueue::Pop() {
	if (IsEmpty()) {
		throw 3;
	}
	else {
		int temp = p[head];
		head++;
		--n;
		head %= (size);
		return temp;
	}
}

bool ArrayQueue::IsEmpty() {
	return (n == 0);
}

bool ArrayQueue::IsFull() {
	return (n == size);
}

