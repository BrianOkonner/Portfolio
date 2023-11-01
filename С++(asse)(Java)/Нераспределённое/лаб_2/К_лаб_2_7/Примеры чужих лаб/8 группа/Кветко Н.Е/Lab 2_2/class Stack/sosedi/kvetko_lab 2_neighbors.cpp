/*
Кветко Никита, 8-я группа.
Описать процедуру, которая подсчитывает количество элементов стека, у которых одинаковые соседи.
Использовать свой класс Stack
Тест:
Заполнение стека
Введите количество элементов стека: 6
Введите элементы стека: 1 2 1 2 1 2
Количество элементов стека с одинаковыми соседями равно: 4
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
	cout << "\tЗаполнение стека\nВведите количество элементов стека: "; cin >> amount;
	cout << "Введите элементы стека: ";
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
	cout << "Количество элементов стека с одинаковыми соседями равно: " << counter << endl;
	system("pause");
}