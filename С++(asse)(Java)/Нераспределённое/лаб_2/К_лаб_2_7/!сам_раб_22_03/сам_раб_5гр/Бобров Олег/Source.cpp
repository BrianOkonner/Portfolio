/*
Вариант 14
В файле набор целых чисел.
Записать их в файл используя свой двунаправленный динамический список.
Просматривая один раз поменять у каждой тройки крайние элементы местами.
Записать в стандартный список и вывести в файл.*/

#include "List.h"
#include <fstream>

void main()
{
	ifstream fin;
	fin.open("Input.txt");
	ofstream fout;
	fout.open("Output.txt");

	LIST list_;
	int a;

	while (fin >> a)
	{
		list_.push_back(a);
	}
	list_.print(cout);
	list_.change();
	list_.print(fout);
	list<int> b;
	list_.copy_to_list(b);
}