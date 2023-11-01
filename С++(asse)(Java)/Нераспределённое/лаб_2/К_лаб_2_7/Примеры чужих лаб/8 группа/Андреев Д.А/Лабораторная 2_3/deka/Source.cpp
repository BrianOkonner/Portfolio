/*
Андреев Дмитрий 8 группа

Дека

Демонстрация

Дека работает, но в самом конце что-то идет не так
*/

#include "Deque.h"
#include <iostream>
#include <ctime>

int main() {

	int tmp;
	Deque deka;
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		tmp = rand() % 100;
		cout << tmp << ' ';
		deka.insНead(tmp);
	}
	cout << endl;
	while(!deka.isEmpty()) {
		cout << deka.delHead() << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}