/*
������� ������� 8 ������

������� 3_4
������:

���������� ���������� ��������� �����, � ������� ������ ������

����� ���������� MS Visual Studio 2017
*/

#include <iostream>
#include "ArrayStack.h"

using namespace std;

void main() {

	setlocale(0, "rus");

	cout << "������� ��������. ��� ��������� ����� ������� ctrl+z:" << endl;

	ArrayStack s(100);
	int b = 2;
	while (cin.good()) {
		cin >> b;
		s.push(b);
	}

	s.pop();

	int a1, a2, i = 1, k = 0;

	ArrayStack s2(100);

	a1 = s.pop();

	a2 = s.pop();

	int tmp;
	while (!s.isEmpty()) {


		if (i % 2 != 0) {
			tmp = s.pop();
			if (tmp == a1) k++;
			a1 = a2;
			a2 = tmp;
		}

	}

	cout << "������ ������ � " << k << " ���������." << endl;

	system("pause");
}