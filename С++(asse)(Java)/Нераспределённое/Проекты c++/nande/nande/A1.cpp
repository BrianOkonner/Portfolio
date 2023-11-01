/*
1 курс 8 группа

Условие :	Задано выражение (инфиксная форма, например (5+45)*(55-5))  содержащее числа (любого типа), 
знаки операций, круглые скобки. Записать его в виде обратной польской записи (постфиксная форма) и вычислить его значение.

Пример:

Ввод:
500*10/2+3

Вывод
500 10 * 2 / 3 +

Answer : 2503

Vremya vipolneniya: 0.073
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <locale>
#include <cmath>
#include "functions_A1.h"
#include <Windows.h>
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "ru");
	unsigned int clk;
	ifstream in;
	char *str = new char[81];
	in.open("input_a1.txt");
	in >> str;
	char *str_opn = new char[strlen(str)];
	str_opn[0] = '\0';
	if (st_to_str_opn(str, str_opn))
	
		cout << str_opn << endl;
	else
		return 0;
	double value = value_of_opn(str_opn);
	cout << endl << "Answer : " << setprecision(6) << value << endl;
	clk = clock();
	cout << endl << "Vremya vipolneniya: " << clk / 1000.0 << endl;
	system("pause");
	return 0;
}
