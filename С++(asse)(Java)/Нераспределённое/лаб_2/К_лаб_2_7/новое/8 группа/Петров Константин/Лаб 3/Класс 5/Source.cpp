/*
������ ����������
8 ������
����� 5

1 - ������� ������

*/
//���������� ���� ������� ��� ������ � ����� ��������� � ���� ���� deque.cpp, � ����������� ������ � ������������ ���� deque.h.

#include "Deque.h"



int main() {
	try {
		setlocale(LC_ALL, "rus");
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

