#include "Header.h"

void Neighbors() {
	system("cls");

	cout << "������� ���������� ��������� �����" << endl;
	int Size;
	cin >> Size;
	if (Size <= 2) {
		cout << "��������� � ����������� �������� ���" << endl;
		Sleep(5000);
		system("cls");
		return;
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
			cout << "���������� ��������� ����� � ����������� �������� ����� - 1" << endl;
			Sleep(5000);
			system("cls");
			return;
		}
		else {
			cout << "���������� ��������� ����� � ����������� �������� ����� - 0" << endl;
			Sleep(5000);
			system("cls");
			return;
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

	cout << "���������� ��������� ����� � ����������� �������� ����� - " << num << endl;
	Sleep(5000);
	system("cls");
}