//Реализацию всех функций для работы с деком поместить в один файл deque.cpp, а определение класса в заголовочный файл deque.h.
#include "deque.h"

Deque::Deque() {
	head = NULL;
	tail = NULL;
	size = 0;
}

Deque::Deque(const Deque& d) {
	head = NULL;
	tail = NULL;
	size = NULL;
	node *temp = d.head;
	while (temp) {
		insTail(temp->item);
		temp = temp->next;
	}
}

Deque::~Deque() {
	while (!isEmpty())
		delTail();
}

void Deque::insНead(int n) {
	head = new node(n, head, 0);
	++size;
	if (head->next)
		head->next->prev = head;
	else
		tail = head;
}

void Deque::insTail(int n) {
	tail = new node(n, 0, tail);
	++size;
	if (tail->prev) 
		tail->prev->next = tail;
	else
		head = tail;
}

int Deque::delHead() {
	if (!isEmpty()) {
		--size;
		node *temp = head;
		int value = head->item;
		if (head->next) {
			head->next->prev = NULL;
			head = head->next;
		}
		else {
			head = tail = 0;
		}
		delete temp;
		return value;
	}
	else {
		throw 1;
	}
}

int Deque::delTail() {
	if (!isEmpty()) {
		--size;
		node *temp = tail;
		int value = tail->item;
		if (tail->prev) {
			tail->prev->next = NULL;
			tail = tail->prev;
		}
		else {
			tail = head = 0;
		}
		delete temp;
		return value;
	}
	else {
		throw 1;
	}
}

void Deque::show() {
	node *temp = head;
	while (temp) {
		cout << temp->item<<" ";
		temp = temp->next;
	}
	cout << endl;
}

bool Deque::isEmpty() {
	return (size == 0);
}

