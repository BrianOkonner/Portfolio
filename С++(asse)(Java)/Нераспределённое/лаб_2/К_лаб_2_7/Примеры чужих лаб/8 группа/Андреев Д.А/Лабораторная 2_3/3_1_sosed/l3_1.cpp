/*
Андреев Дмитрий 8 группа

Задание 3_4
Соседи:

Определить количество элементов стека, у которых равные соседи

Среда разработки MS Visual Studio 2017
*/

#include <iostream>
#include "ArrayStack.h"

using namespace std;

void main() {

	setlocale(0, "rus");

	cout << "Введите элементы. Для окончания ввода нажмите ctrl+z:" << endl;

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

	cout << "Равные соседи у " << k << " элементов." << endl;

	system("pause");
}