/*
������� 14
� ����� ����� ����� �����.
�������� �� � ���� ��������� ���� ��������������� ������������ ������.
������������ ���� ��� �������� � ������ ������ ������� �������� �������.
�������� � ����������� ������ � ������� � ����.*/

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