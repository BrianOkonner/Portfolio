#include "Header.h"

void Neighbors() {
	system("cls");

	cout << "Введите количество элементов стека" << endl;
	int Size;
	cin >> Size;
	if (Size <= 2) {
		cout << "Элементов с одинаковыми соседями нет" << endl;
		Sleep(5000);
		system("cls");
		return;
	}

	ArrayStack S(Size);

	cout << "Введите элементы стека" << endl;
	for (int i = 1; i <= Size; i++) {
		int val;
		cin >> val;
		S.Push(val);
	}

	int a1 = S.Pop(), a2 = S.Pop(), a3 = S.Pop();
	if (S.isEmpty()) {
		if (a3 == a1) {
			cout << "Количество элементов стека с одинаковыми соседями равно - 1" << endl;
			Sleep(5000);
			system("cls");
			return;
		}
		else {
			cout << "Количество элементов стека с одинаковыми соседями равно - 0" << endl;
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

	cout << "Количество элементов стека с одинаковыми соседями равно - " << num << endl;
	Sleep(5000);
	system("cls");
}