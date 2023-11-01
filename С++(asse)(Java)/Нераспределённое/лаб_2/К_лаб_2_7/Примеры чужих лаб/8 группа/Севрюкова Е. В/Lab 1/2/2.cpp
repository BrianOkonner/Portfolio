/*
8 ������, 1 ����
��������� �.

2.	������������� (������������) �������.
����� ��������� ���� Input.txt, � ������� ���� ��������� �����, ������ ����� � ��������� ������.
�������  ��� �������,  � ������ � ������� �����, �� ������ _ ����������.
��������� ����� �������, ������� � ��� �� ������  ���� ��������,
������� ������ ���� �� � ���� �� �������� Queue1 ��� Queue2.
��������� �������� � ���������  ����.

�����:

��� �����:
154 13 6149 252 2 88 5499 12321 19 445 6789 15951 86


�������:
13 2 19

����������:
252 2 88 12321 15951

�����, �������� ���� �� � ���� �������:

13 252 2 88 12321 19 15951


*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include "chisla.h"
#include <queue>
using namespace std;

int main()
{
	queue <int> Q1;
	queue <int> Q2;
	queue <int> Q3;

	setlocale(LC_ALL, "rus");
	ofstream out;
	out.open("Output.txt");
	ifstream in;
	in.open("Input.txt");
	if (!in.is_open())cout << "File is not found";
	cout << "��� �����: \n";
	out << "��� �����: \n";

	int a = -1, b = -1, c = -1;
	char str[100];
	while (!in.eof())
	{
		in >> str;
		int ch = atoi(str);

		if (prostoe(ch)) { Q1.push(ch); a++; Q3.push(ch); c++; }
		if (palindrom(ch))
		{
			Q2.push(ch); b++;
			if (!prostoe(ch)) { Q3.push(ch); c++; }
		}
		cout << str << " ";
		out << str << " ";
	}

	cout << "\n\n�������: \n";
	while (!Q1.empty() && a>0)
	{
		cout << Q1.front();	cout << " ";
		out << Q1.front();	out << " ";
		Q1.pop(); a--;
	}
	cout << "\n\n����������: \n";
	while (!Q2.empty() && b>0)
	{
		cout << Q2.front();	cout << " ";
		out << Q2.front();	out << " ";
		Q2.pop(); b--;
	}
	cout << "\n\n�����, �������� ���� �� � ���� �������: \n\n";
	while (!Q3.empty() && c>0)
	{
		cout << Q3.front();	cout << " ";
		out << Q3.front();	out << " ";
		Q3.pop(); c--;
	}
	cout << "\n";
	out << "\n";
	out.close();

	system("pause");
	return 0;
}
