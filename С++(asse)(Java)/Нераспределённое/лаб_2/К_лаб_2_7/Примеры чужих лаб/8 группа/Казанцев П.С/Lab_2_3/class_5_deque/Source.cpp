/*  Казанцев Павел Сергеевич
	1 курс 8 группа
	Class Deque
*/

#include "deque.h"

int main(void) 
{
	setlocale(LC_ALL, "rus");
	try {
		Deque deq;
		int d1 = 17;
		deq.insTail(d1);
		deq.insTail(32);
		deq.insНead(56);
		cout << "Очередь: ";
		deq.show();
		Deque deq_2(deq);
		cout << "Копия очереди: ";
		deq_2.show();
		system("pause");
	}
	catch (int i) {
		cout << "Ошибка (Очередь пустая)" << endl;
	}
	return 0;
}