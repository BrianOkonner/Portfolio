// 2.cpp: ���������� ����� ����� ��� ����������� ����������.
// ����� ���������� ����� � ������� ����������
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
	//char strtmp[MaxSizeStr]; //��������� ������ 
	char* pstr; //��������� �� ������
	char **ARRStr = new char *[n]; // ������ ���������� �� ������

	setlocale(LC_ALL, "RUS");

	for (int i = 0; i < n; ++i)
		ARRStr[i] = new char[MaxSizeStr];


	ofstream out("output.txt", ios::out | ios_base::trunc);   //  ��� ������	

	cin.clear();

	for (int i = 0; i < n; ++i)
	{
		cout << "������� ������ ����� " << i + 1 << ": ";
		cin.getline(ARRStr[i], MaxSizeStr);
	}

	// ����������
	for (int i = 0; i < n - 1; i++)
	for (int j = 0; j < n - 1; ++j)
	{
		if (strlen(ARRStr[j]) > strlen(ARRStr[j + 1]))
		{  //memset(strtmp, 0, sizeof(strtmp));
			// ������ ����������
			pstr = ARRStr[j];
			ARRStr[j] = ARRStr[j + 1];
			ARRStr[j + 1] = pstr;
		}
	}

	// ����� �����
	cout << "��������������� ������: " << endl;
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



