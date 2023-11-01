/*
������� ������� 8 ������

������ 3_2
������ ������

MS Visual Studio 2017
*/

#include <iostream>
#include <fstream>
#include "ArrayList.h"
using namespace std;

int main()
{
	setlocale(0, "rus");

	ofstream out;
	out.open("Output.txt");

	int n, m, el;
	cout << "K���������: "; cin >> n;
	cout << "���: "; cin >> m;

	if (m == 1) {	//����� ��������� ��� m=1;
		cout << "��������� ������� " << n << endl;
		out << "��������� ������� " << n;
		system("pause");
		return 0;
	}

	List  s;
	for (int i = 1; i <= n; i++) s.push_back(i); //���������

	while (!s.isEmpty())
	{
		for (int i = 1; i<m; i++)
		{
			el = s.front();
			s.push_back(el);
			s.remove_head();
		}
		s.remove_head();
	}

	cout << endl;
	cout << "��������� ����� " << el << endl << "*��������� � output.txt" << endl;
	out << endl;
	out << "��������� ����� " << el << endl;

	system("pause");
	return 0;
}