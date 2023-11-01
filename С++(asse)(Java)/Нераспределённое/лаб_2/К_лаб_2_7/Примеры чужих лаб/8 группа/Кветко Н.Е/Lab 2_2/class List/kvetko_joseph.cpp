/*
Кветко Никита, 8-я группа. Лабораторная работа 2. 
Задача Иосифа Флавия.
С помощью использования своего класса "Список" решить задачу Иосифа Флавия
Тест:
Введите количество участников: 10
Введите шаг: 20
Выбывает игрок номер 10
Выбывает игрок номер 2
Выбывает игрок номер 6
Выбывает игрок номер 4
Выбывает игрок номер 7
Выбывает игрок номер 5
Выбывает игрок номер 3
Выбывает игрок номер 9
Выбывает игрок номер 8

Победитель: 1
*/
#include <iostream>
#include "List.h"
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	list joseph;
	int N, kill, step = 0;
	cout << "Введите количество участников: "; cin >> N;
	cout << "Введите шаг: "; cin >> kill;
	for (int i = 0; i < N; ++i, joseph.push_back(i));
	while (joseph.size() > 1) {
		step++;
		if (step == kill) {
			cout << "Выбывает игрок номер " << joseph.front() << endl;
			joseph.pop_front();
			step = 0;
			continue;
		}
		joseph.push_back(joseph.front());
		joseph.pop_front();
	}
	cout << "\nПобедитель: " << joseph.front() << endl;
	
	system("pause");

}