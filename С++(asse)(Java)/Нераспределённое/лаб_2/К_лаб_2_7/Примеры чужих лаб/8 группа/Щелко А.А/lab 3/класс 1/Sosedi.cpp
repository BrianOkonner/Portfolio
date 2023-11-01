#include "Header.h"

void main(void) {
	setlocale(LC_ALL, "rus");
	cout << "������� ���������� ��������� �����" << endl;
	int Size;
	cin >> Size;
	if (Size <= 2) {
		cout << "��������� � ����������� �������� ���" << endl;
		system("pause");
		exit(0);
	}

	ArrayStack S(Size);

	cout << "������� �������� �����" << endl;
	for (int i = 1; i <= Size; i++) {
		int val;
		cin >> val;
		S.Push(val);
	}

	int a1 = S.Pop(), a2 = S.Pop(), a3 = S.Pop();
	if (S.isEmpty()) {
		if (a3 == a1) {
			cout << "���������� ��������� ����� � ����������� �������� ����� 1" << endl;
			system("pause");
			exit(0);
		}
		else {
			cout << "���������� ��������� ����� � ����������� �������� ����� 0" << endl;
			system("pause");
			exit(0);
		}
	}

	int num = 0;
	do {
		if (a1 == a3) ++num;
		a1 = a2;
		a2 = a3;
		a3 = S.Pop();
	} while (!S.isEmpty());

	if (a1 == a3) ++num;

	cout << "���������� ��������� ����� � ����������� �������� ����� " << num << endl;
	system("pause");
}