/* 1 курс, 8 группа, Книтор
19. В файле Input.txt задан набор целых чисел. Записать их в память используя свой дек-массив. 
Просматривая дек по тройкам, к среднему добавить крайние и переставить в конец.
Результат из дека записать в стандартный список и вывести в файл Output.txt.
*/

#include <fstream>
#include <iostream>
#include <list>
#include "H19.h"
using namespace std;

void main()
{
	ifstream fin("Input.txt");
	ofstream fout("Output.txt");
	MyDeque D1;
	list <int> L;
	int n, a, b, c, s = 0;

	while (fin >> n)
	{
		D1.push_front(n);
		s++;
	}
	s /= 3;
	MyDeque D2;
	while (!D1.isEmpty())
	{
		a = D1.front();
		D1.pop_front();
		b = D1.front();
		D1.pop_front();
		c = D1.front();
		D1.pop_front();
		b += a;
		b += c;
		D2.push_front(b);
	}

	while(!D2.isEmpty())
	{
		n = D2.front();
		L.push_front(n);
		D2.pop_front();
	}

	while (!L.empty())
	{
		n = L.back();
		L.pop_back();
		fout << n << "   ";
	}

	fin.close();
	fout.close();
	system("pause");
}