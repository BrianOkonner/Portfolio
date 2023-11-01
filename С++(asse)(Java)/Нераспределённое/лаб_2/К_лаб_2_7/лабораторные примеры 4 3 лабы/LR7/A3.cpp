/*
Казанцев Павел
1 курс 8 группа

Условие :	Задача Иосифа. Вокруг считающего стоит N человек, из которых выделен первый, 
а  остальные  занумерованы  по  часовой стрелке числами от 2 до N. Считающий,  начиная с кого-то, 
ведет счет до M. Человек, на котором остановился счет, выходит из круга. Счет продолжается со следующего человека
и так до тех пор, пока не останется один человек.  Определить номер оставшегося человека, если известно M и то, 
что счет начинался с первого человека. 
Результат записать в текстовый  файл.

Пример:

Ввод:
15 3
Вывод
Last Man Standing : 5

Vremya vipolneniya: 0.041
*/


#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <locale>
#include "functions_list.h"
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "ru");
	unsigned int clk;
	ifstream in;
	ofstream out;

	int N=0, M=0;
	in.open("input_a3.txt");
	out.open("output_a3.txt");
	in >> N >> M;
	if (N < 2 || M < 1)
	{
		cout << "Incorrect input !" << endl;
		return 0;
	}
	out << "Last Man Standing : " << iosif_task(N, M) << endl;
	clk = clock();
	cout << endl << "Vremya vipolneniya: " << clk / 1000.0 << endl;

	return 0;
}

