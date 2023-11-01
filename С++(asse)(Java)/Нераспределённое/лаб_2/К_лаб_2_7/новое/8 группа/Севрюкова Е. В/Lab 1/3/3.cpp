/*
8 группа, 1 курс
Севрюкова Л.

3. Задача Иосифа. Вокруг считающего стоит N человек, из которых выделен первый,
а  остальные  занумерованы  по  часовой стрелке числами от 2 до N. 
Считающий,  начиная с кого-то, ведет счет до M. Человек, на котором остановился счет, выходит из круга.
Счет продолжается со следующего человека и так до тех пор, пока не останется один человек. 
Определить номер оставшегося человека, если известно M и то, что счет начинался с первого человека. 
Результат записать в текстовый  файл.

тесты:


*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <list>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream out;
	out.open("Output.txt");
	int N, M;
	cout << "Кол-во человек = "; cin >> N;
	cout << "Число до которого ведется счет = "; cin >> M;

	//создание списка
	list <int> s;
	for (int i = N; i>0; i--)
		s.push_front(i);

	int L = N;
	int k, x;
	if (M > N) k = M - N;
	else k = M;
	while (!s.empty())
	{
		if (k == 1) { x = s.front(); s.pop_front(); }
		else
			if (k == N) { x = s.back(); s.pop_back(); }
			else
			{
				int a;
				list <int> s1 = s;
				for (int j = 0; j < k; j++)
				{
					a = s1.front();s1.pop_front();
				}
				s.remove(a);
			}

		k += M - 1;
		N--;
		while (k > N && N>0) k = k - N;
	}

	cout << "\nНомер оставшегося человека = " << x << "\n\n";
	out << "Номер оставшегося человека = " << x << "\n\n";
	out.close();
	system("pause");
	return 0;
}

