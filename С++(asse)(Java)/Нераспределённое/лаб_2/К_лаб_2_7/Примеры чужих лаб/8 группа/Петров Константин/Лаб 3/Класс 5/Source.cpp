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
		int a = 5, b = 6, c = 7;
		deq.insTail(a);
		deq.insTail(b);
		deq.insTail(c);
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

