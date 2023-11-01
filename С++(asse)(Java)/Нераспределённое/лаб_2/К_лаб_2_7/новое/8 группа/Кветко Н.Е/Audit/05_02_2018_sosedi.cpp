//Кветко Никита 8 группа
//Задача "Соседи" с использованием стандартного стека

#include <iostream>
#include <stack>
using namespace std;
//Функция подсчёта элементов с одинаковыми соседями
int main() {
	setlocale(LC_ALL, "rus");
	stack <int> s1, s2, s3;
	int amount, elem, counter = 0;
	cout << "\tЗаполнение стека\nВведите количество элементов стека: "; cin >> amount;
	cout << "Введите элементы стека: ";
	for (int i = 0; i < amount; i++) {
		cin >> elem;
		s1.push(elem);
	}
	int tmp;
	while (1) 
	{
		s2.push(s1.top()); // забираем первый
		s1.pop();
		s3.push(s1.top()); // второй
		s1.pop();
		if (!s1.empty()) {
			s2.push(s1.top()); // третий
			s1.pop();

			// проверка
			tmp = s2.top();
			s2.pop();

			if (s2.top() == tmp) counter++;

			s1.push(s2.top());
			s2.pop();
			s1.push(s3.top());
			s3.pop();
		}
		else break;
	}
	cout << "Количество элементов стека с одинаковыми соседями равно: " << counter << endl;
	system("pause");
}