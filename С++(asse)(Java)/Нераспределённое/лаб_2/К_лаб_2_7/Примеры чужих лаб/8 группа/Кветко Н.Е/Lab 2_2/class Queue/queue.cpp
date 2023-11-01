#include <iostream>
#include "queue.h"
using namespace std;
//�����������
Queue::Queue() {
	queue = new int[SIZE];
	frnt = rear = 0;
}
//����� ��������� �������
void Queue::out() {
	for (int i = frnt + 1; i<rear + 1; i++)
		cout << " " << queue[i];
}
//��������� �������� � �������
void Queue::push(int num) {
	if (rear + 1 == frnt || (rear + 1 == SIZE && !frnt)) {
		cout << "������� �����" << endl;
		return;
	}
	rear++;
	if (rear == SIZE) rear = 0;
	queue[rear] = num;
}
// ���������� �������� �� �������
void Queue::pop() {
	if (frnt == rear) {
		cout << "������� �����" << endl;
		return;
	}
	frnt++;
	if (frnt == SIZE) frnt = 0;
}
//����������� ������� �������
int Queue::size() {
	int s = 0;
	for (int i = frnt; i<rear; i++)
		s++;
	return s;
}
// ��������� ������� �������
int Queue::back() {
	return queue[rear];
}
// ������ ������� �������
int Queue::front() {
	return queue[frnt + 1];
}