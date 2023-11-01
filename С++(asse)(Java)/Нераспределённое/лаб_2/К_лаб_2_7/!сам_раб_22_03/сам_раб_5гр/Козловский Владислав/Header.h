#pragma once
class Queue {
	int* a;
	int head;
	int tail;
	int capacity;
	int size;
public:
	Queue(int n):head(0), tail(0), capacity(n), size(0){
		a = new int[n];
	}
	Queue(Queue& b) :tail(b.tail), capacity(b.capacity), head(b.head) {
		a = new int[capacity];
		for (int i = 0;i < size;++i) {
			a[(head + i) % capacity] = b.a[(head + i) % capacity];
		}
	}
	void push(int b) {
		if (size == capacity) {
			throw "Full queue.";
		}
		a[tail++] = b;
		if (tail == capacity) tail = 0;
		++size;
	}

	int pop() {
		if (size == 0) throw "Empty queue";
		int c = a[head++];
		if (head==capacity) head==0;
		--size;
		return c;
	}
	~Queue()
	{
		delete[] a;
	}
	bool is_empty() { return size == 0; }
};
