//����� ������� 8 ������
//3.1	������ ������.������ ���������� ����� N �������, �� ������� ������� ������,
//�  ���������  ������������  ��  ������� ������� ������� �� 2 �� N.���������,
//������� � ���� - ��, ����� ���� �� M.�������, �� ������� ����������� ����,
//������� �� �����.���� ������������ �� ���������� �������� � ��� �� ��� ���,
//���� �� ��������� ���� �������.���������� ����� ����������� ��������, 
//���� �������� M � ��, ��� ���� ��������� � ������� ��������.��������� �������� � ���������  ����

//������� m :
//
//���������� �����:
//5
//Nomer ostavshegosya :
//2

#include <fstream>
#include <iostream>
#include <list>
#include <string.h>


using namespace std;

list <int> S;
int main()
{
	ofstream fout;
	fout.open("Output.txt");
	setlocale(LC_ALL, "rus");
	cout << "������� m: " << endl;
	int n;
	cin >> n;
	if (n == 0) { cout << "error"; exit(0); }
	cout << "���������� �����:  " << endl;
	int kol;
	cin >> kol;
	for (int i = 1; i <= kol; S.push_back(i), i++);
	while (kol != 1)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j != n)
			{
				int y = S.front();
				S.pop_front();
				S.push_back(y);
			}
			else
			{
				S.pop_front();
			}
		}
		kol--;
	}
	fout << "����� ����������� ��������:" << endl;
	fout << S.front() << endl;
	system("pause");
	return 0;
}

