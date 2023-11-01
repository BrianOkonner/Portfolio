/*
������ ����������
8 ������
����� 5

1 - ������� ������

*/
//���������� ���� ������� ��� ������ � ����� ��������� � ���� ���� deque.cpp, � ����������� ������ � ������������ ���� deque.h.

#include <iostream>
using namespace std;

class Deque {
	struct node {									/* ������� ���� */
		int  item;									/* ������ */
		struct  node*  next;						/* ��������� �� ��������� ������� */
		struct  node*  prev;						/* ��������� �� ���������� ������� */
		node(int Item, node *Next, node *Prev) {
			item = Item;
			next = Next;
			prev = Prev;
		}
	} *head, *tail;					/* ��������� �� ������ � ��������� �������� � ������ */
	int size;						/* ������ ������� */
public:
	Deque();						/* ����������� */
	Deque(const Deque& d);			/* ����������� ����������� */
	~Deque();						/* ���������� */
	void ins�ead(int n);			/* �������� ������� � ������ ���� */
	void insTail(int n);			/* �������� ������� � ����� ���� */
	int delHead();					/* ��������� ������� �� ������ ���� */
	int delTail();					/* ��������� ������� �� ������ ���� */
	void show();
	bool isEmpty();					/* ������ ���? */
};

Deque::Deque() {
	head = 0;
	tail = 0;
	size = 0;
}
Deque::Deque(const Deque& d) {
	head = 0;
	tail = 0;
	size = 0;
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
void Deque::ins�ead(int n) {
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

int main() {
	try {
		Deque deq;
		int d5 = 5, d6 = 6, d7 = 7;
		deq.insTail(d5);
		deq.insTail(d6);
		deq.insTail(d7);
		deq.show();
		Deque Q(deq);
		cout << "����� ������� - " << endl;
		Q.show();
		system("pause");
	}
	catch (int i) {
		cout << "Error - 1" << endl;
	}
	return 0;
}

