/*
�������� �����
1 ���� 8 ������

������� :	������ ������. ������ ���������� ����� N �������, �� ������� ������� ������,
�  ���������  ������������  ��  ������� ������� ������� �� 2 �� N. ���������,  ������� � ����-��,
����� ���� �� M. �������, �� ������� ����������� ����, ������� �� �����. ���� ������������ �� ���������� ��������
� ��� �� ��� ���, ���� �� ��������� ���� �������.  ���������� ����� ����������� ��������, ���� �������� M � ��,
��� ���� ��������� � ������� ��������.
��������� �������� � ���������  ����.

������:

����:
15 3
�����
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

