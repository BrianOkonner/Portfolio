#include "Stack.h"

void Neighbors() {
	system("cls");

	cout << "Введите количество элементов стека" << endl;
	int Size;
	cin >> Size;
	if (Size <= 2) {
		cout << "Элементов с одинаковыми соседями нет" << endl;
		system("pause");
		system("cls");
		return;
	}

	Stack_on_Array S(Size);

	cout << "Введите элементы стека" << endl;
	for (int i = 1; i <= Size; i++) {
		int value;
		cin >> value;
		S.Push(value);
	}

	int a1 = S.Pop(), a2 = S.Pop(), a3 = S.Pop();
	if (S.isEmpty()) {
		if (a3 == a1) {
			cout << "Количество элементов стека с одинаковыми соседями равно - 1" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "Элементов с одинаковыми соседями нет" << endl;
			system("pause");
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
	system("pause");
	system("cls");
}