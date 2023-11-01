#include <iostream>
#include "queue.h"
using namespace std;
//Конструктор
Queue::Queue() {
	queue = new int[SIZE];
	frnt = rear = 0;
}
//Вывод элементов очереди
void Queue::out() {
	for (int i = frnt + 1; i<rear + 1; i++)
		cout << " " << queue[i];
}
//Помещение элемента в очередь
void Queue::push(int num) {
	if (rear + 1 == frnt || (rear + 1 == SIZE && !frnt)) {
		cout << "очередь полна" << endl;
		return;
	}
	rear++;
	if (rear == SIZE) rear = 0;
	queue[rear] = num;
}
// Извлечение элемента из очереди
void Queue::pop() {
	if (frnt == rear) {
		cout << "очередь пуста" << endl;
		return;
	}
	frnt++;
	if (frnt == SIZE) frnt = 0;
}
//Определение размера очереди
int Queue::size() {
	int s = 0;
	for (int i = frnt; i<rear; i++)
		s++;
	return s;
}
// Последний элемент очереди
int Queue::back() {
	return queue[rear];
}
// Первый элемент очереди
int Queue::front() {
	return queue[frnt + 1];
}