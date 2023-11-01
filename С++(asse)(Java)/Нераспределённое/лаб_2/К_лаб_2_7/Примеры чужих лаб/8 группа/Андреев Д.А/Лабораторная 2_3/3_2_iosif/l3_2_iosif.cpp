/*
Андреев Дмитрий 8 группа

Задача 3_2
Задача Иосифа

MS Visual Studio 2017
*/

#include <iostream>
#include <fstream>
#include "ArrayList.h"
using namespace std;

int main()
{
	setlocale(0, "rus");

	ofstream out;
	out.open("Output.txt");

	int n, m, el;
	cout << "Kоличество: "; cin >> n;
	cout << "Шаг: "; cin >> m;

	if (m == 1) {	//иначе сбивается при m=1;
		cout << "Останется элемент " << n << endl;
		out << "Останется элемент " << n;
		system("pause");
		return 0;
	}

	List  s;
	for (int i = 1; i <= n; i++) s.push_back(i); //заполняем

	while (!s.isEmpty())
	{
		for (int i = 1; i<m; i++)
		{
			el = s.front();
			s.push_back(el);
			s.remove_head();
		}
		s.remove_head();
	}

	cout << endl;
	cout << "Останется номер " << el << endl << "*сохранено в output.txt" << endl;
	out << endl;
	out << "Останется номер " << el << endl;

	system("pause");
	return 0;
}