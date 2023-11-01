/* ������� ����
1 ���� 8 ������
11. � ����� input.txt ����� ����� ����� �����.
�������� �� � ������ ��������� ���� ������������ ����.
������������ ���� ����� ����������, ����� ������� �� ���� ��� ����������.
P�������� �� �����  �������� � ����������� ������  � ������� � ���� Output.txt
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
		while (!fin.eof())//���� ��������� ���� ���������� �� �����
		{
			fin >> buff1;
			buff = atoi(buff1);
			Int.push_int(buff);
		}
	fin.close();

	while (!Int.isEmptyInt())//�������Ͳ� ����������� ��������
	{
		BUFF.push_int(Int.TopInt());
		if (keeper < Int.TopInt())
			keeper = Int.TopInt();
		Int.PopInt();
	}

	cout << "���������� ������� " << keeper << endl;

	while (!BUFF.isEmptyInt())//�����Ͳ� ������ ��� ���������
	{
		if (keeper == BUFF.TopInt())
			BUFF.PopInt();
		else
		{
			Int.push_int(BUFF.TopInt());
			BUFF.PopInt();
		}
	}

	while (!Int.isEmptyInt())//������ ������� �� ��������������
	{
		BUFF.push_int(Int.TopInt());
		Int.PopInt();
	}
	
	while (!BUFF.isEmptyInt())//�������� �������� � ����������� �������
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
	cout << "��������� ���������. ���������� � ����� OUTPUT.TXT " << endl;
	system("pause");
}