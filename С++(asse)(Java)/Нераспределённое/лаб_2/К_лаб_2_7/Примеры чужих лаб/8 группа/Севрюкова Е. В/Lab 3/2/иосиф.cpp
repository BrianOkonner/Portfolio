/*
8 ������, 1 ����
��������� �.

3. ������ ������. ������ ���������� ����� N �������, �� ������� ������� ������,
�  ���������  ������������  ��  ������� ������� ������� �� 2 �� N.
���������,  ������� � ����-��, ����� ���� �� M. �������, �� ������� ����������� ����, ������� �� �����.
���� ������������ �� ���������� �������� � ��� �� ��� ���, ���� �� ��������� ���� �������.
���������� ����� ����������� ��������, ���� �������� M � ��, ��� ���� ��������� � ������� ��������.
��������� �������� � ���������  ����.

�����:


*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include "list.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream out;
	out.open("Output.txt");
	int N, M;
	cout << "���-�� ������� = "; cin >> N;
	cout << "����� �� �������� ������� ���� = "; cin >> M;

	//�������� ������
	List  s;
	for (int i = 1; i <= N; i++)
		s.push_back(i);

	int x;
	while (!s.isEmpty())
	{
		for (int i = 1; i<M; i++)
		{
			x = s.front();
			s.push_back(x);
			s.remove_head();
		}
		s.remove_head();
	}
	if (M == 1) x = N;

	cout << "\n����� ����������� �������� = " << x << "\n\n";
	out << "����� ����������� �������� = " << x << "\n\n";
	out.close();
	system("pause");
	return 0;
}
