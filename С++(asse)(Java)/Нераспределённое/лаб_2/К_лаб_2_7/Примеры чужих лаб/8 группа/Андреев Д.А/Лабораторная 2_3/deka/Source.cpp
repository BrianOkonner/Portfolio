/*
������� ������� 8 ������

����

������������

���� ��������, �� � ����� ����� ���-�� ���� �� ���
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
		deka.ins�ead(tmp);
	}
	cout << endl;
	while(!deka.isEmpty()) {
		cout << deka.delHead() << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}