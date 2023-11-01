/*
������ ������, 8-� ������.
������� ���������, ������� ������������ ���������� ��������� �����, � ������� ���������� ������.
������������ ���� ����� Stack
����:
���������� �����
������� ���������� ��������� �����: 6
������� �������� �����: 1 2 1 2 1 2
���������� ��������� ����� � ����������� �������� �����: 4
*/

#include <iostream>
#include "(int)Stack.h"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	Stack s1,s2,s3;
	int amount, elem, counter = 0;
	cout << "\t���������� �����\n������� ���������� ��������� �����: "; cin >> amount;
	cout << "������� �������� �����: ";
	for (int i = 0; i < amount; i++) {
		cin >> elem;
		s1.push(elem);
	}
	int tmp;
	while (1) {
		s2.push(s1.pop());
		s3.push(s1.pop());
		if (!s1.empty()) {
			s2.push(s1.pop());

			tmp = s2.pop();
			if (s2.peek() == tmp) counter++;
			s1.push(s2.pop());
			s1.push(s3.pop());
		}
		else break;
	}
	cout << "���������� ��������� ����� � ����������� �������� �����: " << counter << endl;
	system("pause");
}