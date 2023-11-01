/*
Кветко Никита 8-я группа. 
Решение задачи Иосифа Флавия с использованием STL списка
*/
#include <iostream>
#include <list>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	list <int> joseph;
	int n, kill, count = 0;
	cout << "Введите количество участников: "; cin >> n;
	cout << "Введите номер: "; cin >> kill;
	for (int i = 0; i < n; joseph.push_back(++i));
	while (joseph.size() > 1)
	{
		count++;
		if (count == kill) {
			cout << "Выбывает участник " << joseph.front() << endl;
			joseph.pop_front();
			count = 0;
		}
		else {
			joseph.push_back(joseph.front());
			joseph.pop_front();
		}
	}
	cout << "Участник под номером " << joseph.front() << " побеждает.\n";
	system("pause");
}