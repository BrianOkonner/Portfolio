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
#include <list>
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
	list <int> s;
	for (int i = N; i>0; i--)
		s.push_front(i);

	int L = N;
	int k, x;
	if (M > N) k = M - N;
	else k = M;
	while (!s.empty())
	{
		if (k == 1) { x = s.front(); s.pop_front(); }
		else
			if (k == N) { x = s.back(); s.pop_back(); }
			else
			{
				int a;
				list <int> s1 = s;
				for (int j = 0; j < k; j++)
				{
					a = s1.front();s1.pop_front();
				}
				s.remove(a);
			}

		k += M - 1;
		N--;
		while (k > N && N>0) k = k - N;
	}

	cout << "\n����� ����������� �������� = " << x << "\n\n";
	out << "����� ����������� �������� = " << x << "\n\n";
	out.close();
	system("pause");
	return 0;
}

