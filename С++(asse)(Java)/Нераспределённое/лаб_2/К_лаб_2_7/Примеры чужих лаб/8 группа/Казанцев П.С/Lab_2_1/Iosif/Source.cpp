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

*/

#include <list>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <locale>
using namespace std;

list <int> l;

int main(void)
{
	setlocale(LC_ALL, "ru");
	unsigned int clk;
	ifstream in;
	ofstream out;
	in.open("input.txt");
	int m, p;
	in >> p >> m;
	in.close();
	if (p < 2 || m < 1)
	{
		cout << "Incorrect input !" << endl;
		return 0;
	}
	for (int i = 1; i <= p;  l.push_back(i), i++);
//----------------------------------------------------------------------------
	while (p != 1)
	{
		for (int j = 1; j <=m; j++)
		{
			if (j != m)
			{
				int y = l.front();
				l.pop_front();
				l.push_back(y);
			}
			else 
			{
				l.pop_front();
			}
		}
		p--;
	}
	out.open("Output.txt");
	out << "Last Man Standing : " << l.front() << endl;
//----------------------------------------------------------------------------
	out.close();
	system("pause");
	return 0;
}

