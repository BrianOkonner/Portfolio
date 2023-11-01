/* Берёзкин Глеб
1 курс 8 группа
11. В файле input.txt задан набор целых чисел.
Записать их в память используя свой динамический стек.
Просматривая стек найти наибольший, затем удалить из стек все наибольшие.
Pезультат из стека  записать в стандартный список  и вывести в файл Output.txt
*/
#include <iostream>
#include "Header.h"
#include <fstream>
#include <queue>

using namespace std;

void main()
{
	setlocale(LC_ALL, ".1251");

	Stack Int;
	Stack BUFF;
	queue<int> Queue;

	char buff1[30];
	int buff;
	int keeper=0;

	Int.InitIntStack();
	BUFF.InitIntStack();

	ifstream fin;
	fin.open("input.txt");
	if (fin.is_open())
		while (!fin.eof())//Цикл заполняет стек элементами из файла
		{
			fin >> buff1;
			buff = atoi(buff1);
			Int.push_int(buff);
		}
	fin.close();

	while (!Int.isEmptyInt())//НАХОЖДЕНІЕ НАІБОЛЬШЕГО ЭЛЕМЕНТА
	{
		BUFF.push_int(Int.TopInt());
		if (keeper < Int.TopInt())
			keeper = Int.TopInt();
		Int.PopInt();
	}

	cout << "НАИБОЛЬШИЙ ЭЛЕМЕНТ " << keeper << endl;

	while (!BUFF.isEmptyInt())//УДАЛЕНІЕ РАВНЫХ ЕМУ ЭЛЕМЕНТОВ
	{
		if (keeper == BUFF.TopInt())
			BUFF.PopInt();
		else
		{
			Int.push_int(BUFF.TopInt());
			BUFF.PopInt();
		}
	}

	while (!Int.isEmptyInt())//МЕНЯЕМ ПОРЯДОК НА ПЕРВОНАЧАЛЬНЫЙ
	{
		BUFF.push_int(Int.TopInt());
		Int.PopInt();
	}
	
	while (!BUFF.isEmptyInt())//ПОМЕЩАЕМ ЭЛЕМЕНТЫ В СТАНДАРТНУЮ ОЧЕРЕДЬ
	{
		buff = BUFF.TopInt();
		Queue.push(buff);
		BUFF.PopInt();
	}

	ofstream fout;
	fout.open("Output.txt");
	do
	{
		fout << Queue.front() << " ";
		Queue.pop();
	} while (!Queue.empty());
	fout.close();
	cout << "ОБРАБОТКА ЗАВЕРШЕНА. ОБРАТИТЕСЬ К ФАЙЛУ OUTPUT.TXT " << endl;
	system("pause");
}