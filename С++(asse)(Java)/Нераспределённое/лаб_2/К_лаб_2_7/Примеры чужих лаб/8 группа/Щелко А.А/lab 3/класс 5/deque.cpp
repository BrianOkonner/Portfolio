/*
Класс 5
1 - Очередь пустая
*/
//Реализацию всех функций для работы с деком поместить в один файл deque.cpp, а определение класса в заголовочный файл deque.h.
#include "Header.h"



void main(void) {
	try {
		setlocale(LC_ALL, "rus");
		Deque deq;
		int d5 = 5, d6 = 6, d7 = 7;
		deq.insTail(d5);
		deq.insTail(d6);
		deq.insTail(d7);
		deq.show();
		Deque Q(deq);
		cout << "Копия очереди " << endl;
		Q.show();
		system("pause");
	}
	catch (int i) {
		cout << "Error - 1" << endl;
	}
}

