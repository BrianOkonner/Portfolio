//s += sin(n*x)*(pow(x, 2 * n + 1)) / (2 * n + 1);
//n = 5, 6, 7... m


#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "funcs.h"

using namespace std;



void main() {

	setlocale(0, "rus");

	ofstream out;
	out.open("output.txt");

	int m;
	double x, h, a, b, s, s1 = 0, s2 = 0;

	cout << "Начальное значение x: "; cin >> a;
	cout << "Конечное значение x: "; cin >> b;
	cout << "Шаг изменения x: "; cin >> h;
	cout << "Количество слагаемых: "; cin >> m;

	out << "Начальное значение x: " << a << endl;
	out << "Конечное значение x: " << b << endl;
	out << "Шаг изменения x: " << h << endl;
	out << "Количество слагаемых: " << m << endl << endl << endl;

	//рисуем шапку таблицы...

	//...в консоли
	cout.fill('=');
	cout << setw(78) << " " << endl;
	cout.fill(' ');
	cout << "|" << setw(12) << "Значение x |" << setw(17) << "Сумма ряда |" << setw(25) << "Cтандартный синус C |" << setw(17) << "Cтандартный синус asm|" << endl;
	cout.fill('=');
	cout << setw(78) << " " << endl;
	cout.fill(' ');
	//...в файле
	out.fill('=');
	out << setw(78) << " " << endl;
	out.fill(' ');
	out << "|" << setw(12) << "Значение x |" << setw(17) << "Сумма ряда |" << setw(25) << "Cтандартный синус C |" << setw(17) << "Cтандартный синус asm|" << endl;
	out.fill('=');
	out << setw(78) << " " << endl;
	out.fill(' ');


	//изменение х, передача функциям счета и вывод от меньшего к большему
	if (a < b) {

		for (x = a; x <= b; x += h) {
			s = schet(x, m);
			s1 = schet1(x, m);
			s2 = schet2(x, m);
			//дорисовываем таблицу
			cout << "|" << setw(10) << x << " |" << setw(15) << s << " |" << setw(23) << s1 << " |"  << setw(20) << s2 << " |" << endl;;
			cout.fill('=');
			cout << setw(78) << " " << endl;
			cout.fill(' ');

			out << "|" << setw(10) << x << " |" << setw(15) << s << " |" << setw(23) << s2 << " |" << setw(20) << s1 << " |" << endl;
			out.fill('=');
			out << setw(78) << " " << endl;
			out.fill(' ');
		}

	}
	//изменение х передача функциям счета и вывод от большего к меньшему
	else if (a >= b) {

		for (x = a; x >= b; x -= h) {
			s = schet(x, m);
			s1 = schet1(x, m);
			s2 = schet2(x, m);
			//дорисовываем таблицу
			cout << "|" << setw(10) << x << " |" << setw(15) << s << " |" << setw(23) << s1 << " |" << setw(20) << s2 << " |" << endl;;
			cout.fill('=');
			cout << setw(78) << " " << endl;
			cout.fill(' ');

			out << "|" << setw(10) << x << " |" << setw(15) << s << " |" << setw(23) << s2 << " |" << setw(20) << s1 << " |" << endl;
			out.fill('=');
			out << setw(78) << " " << endl;
			out.fill(' ');
		}

	}

	cout << "* сохранено в output.txt" << endl;

	system("pause");

}