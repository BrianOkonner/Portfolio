/*
Кветко Никита 8-я группа. Лабораторная работа 2.1
Выполнение лабораторной работы 7 с использованием собственного класса "очередь".

Тест:
input.txt:
313
17
313
91
2
4
19
919
101
2
output.txt:
Простые числа: 313 17 313 2 19 919 101 2
Палиндромы: 313 313 2 4 919 101 2
Результат: 17 19 313 4 919 101 2
*/
#include <iostream>
#include <fstream>
#include "queue.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	Queue q1, q2, q3; int tmp;
	ifstream in("input.txt");
	ofstream out("output.txt");
	while (!in.eof()) {
		in >> tmp;
		if (Prime(tmp)) q1.push(tmp);
		if (is_palindrom(tmp)) q2.push(tmp);
	}
	out << "Простые числа: ";
	while (q1.size()>0) {
		out << q1.front() << ' ';
		q3.push(q1.front());
		q1.pop();
	}
	out << "\nПалиндромы: ";
	while (q2.size()>0) {
		out << q2.front() << ' ';
		q3.push(q2.front());
		q2.pop();
	}
	
	// Удаление дубликатов
	Queue res, checker, temp;
	while (q3.size()>0)
	{
		checker.push(q3.front());
		q3.pop();
		temp = q3;
		bool flag = false;
		while (temp.size()>0) 
		{
			if (checker.front() == temp.front()) {
				flag = true;
				break;
			}
			temp.pop();
		}
		if (flag == false) 
			res.push(checker.front());
		checker.pop();
	}
	out << "\nРезультат: ";
	while (res.size()>0) {
		out << res.front() << ' ';
		res.pop();
	}
	cout << "Данные записаны в файл.\n";*/
	system("pause");
}