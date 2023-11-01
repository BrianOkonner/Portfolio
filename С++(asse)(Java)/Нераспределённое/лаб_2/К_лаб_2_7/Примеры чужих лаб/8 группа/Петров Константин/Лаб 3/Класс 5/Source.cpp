/*
Петров Константин
8 группа
Класс 5

1 - Очередь пустая

*/
//Реализацию всех функций для работы с деком поместить в один файл deque.cpp, а определение класса в заголовочный файл deque.h.

#include "Deque.h"



int main() {
	try {
		setlocale(LC_ALL, "rus");
		Deque deq;
		int a = 5, b = 6, c = 7;
		deq.insTail(a);
		deq.insTail(b);
		deq.insTail(c);
		deq.show();
		Deque Q(deq);
		cout << "Копия очереди - " << endl;
		Q.show();
		system("pause");
	}
	catch (int i) {
		cout << "Error - 1" << endl;
	}
	return 0;
}

