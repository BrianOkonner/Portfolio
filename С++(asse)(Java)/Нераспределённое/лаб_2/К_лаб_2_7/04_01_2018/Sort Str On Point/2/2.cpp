// 2.cpp: определяет точку входа для консольного приложения.
// Пимер сортировки строк с помощью указателей
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <search.h>
#include <string>
#include <cstdio>
#include<cstring>
using namespace std;
using std::cin;
using std::cout;


#define MaxSizeStr 50
#define CTString 10

int main()
{

	int n = CTString;
	//char strtmp[MaxSizeStr]; //временная строка 
	char* pstr; //указатель на строку
	char **ARRStr = new char *[n]; // массив указателей на строки

	setlocale(LC_ALL, "RUS");

	for (int i = 0; i < n; ++i)
		ARRStr[i] = new char[MaxSizeStr];


	ofstream out("output.txt", ios::out | ios_base::trunc);   //  для записи	

	cin.clear();

	for (int i = 0; i < n; ++i)
	{
		cout << "Введите строку номер " << i + 1 << ": ";
		cin.getline(ARRStr[i], MaxSizeStr);
	}

	// сортировка
	for (int i = 0; i < n - 1; i++)
	for (int j = 0; j < n - 1; ++j)
	{
		if (strlen(ARRStr[j]) > strlen(ARRStr[j + 1]))
		{  //memset(strtmp, 0, sizeof(strtmp));
			// замена указателей
			pstr = ARRStr[j];
			ARRStr[j] = ARRStr[j + 1];
			ARRStr[j + 1] = pstr;
		}
	}

	// НУЖЕН ВЫВОД
	cout << "Отсортированные строки: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ARRStr[i] << endl;
		out << ARRStr[i] << endl;

	}
	system("pause >> void");
	out.close();
	for (int i = 0; i < n; i++)  delete[] ARRStr[i];

	delete ARRStr;

	return 0;
}



