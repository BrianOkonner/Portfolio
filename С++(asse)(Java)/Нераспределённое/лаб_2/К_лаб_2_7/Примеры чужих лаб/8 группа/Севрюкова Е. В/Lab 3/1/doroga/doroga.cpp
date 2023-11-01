/*������� ���� ���������, �������� �� ��������, �������� �������� �������� M x N. 
������ ������� ����� ���� �� ����������� :  0, ���� � �������� ������ �����, � -1, ���� � �������� ������.
���������� ����������, ������� �� � ������� ������ �� ������� (��, ��)	� ������� (��, ��),
���� ����� ����� ��������� ������ �� ������ ��������� � ������ � �������������� � ������������ ������������.   
��� ���� ����� ������ ��������� ��������� ������.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "stack_paper.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	ifstream in; in.open("input2.txt");
	if (!in.is_open()) {cout << "File is not found"; return 0;}
	int i, j, n, m, k, x, y, x1, y1;
	int **Lst;  //������� ��� �������� ����� ������
	in >> n >> m;

	cout << "���� ������ �����: -1 \n\n";
	Lst = new int *[n];
	for (i = 0; i<n; i++)
	{
		Lst[i] = new int[m];
		for (j = 0; j<m; j++)
		{
			in >> Lst[i][j];
			cout << setw(3) << Lst[i][j] << " ";
		}
		cout << endl << endl;
	}

	int a1, b1, a2, b2;
	cout << "������� ���������� ������: x = "; cin >> a1; cout << "\t\t\t   y = "; cin >> b1;
	cout << "������� ���������� ������: x = "; cin >> a2; cout << "\t\t\t   y = "; cin >> b2;

	if (a1 <= 0 || a2 <= 0 || b1 <= 0 || b2 <= 0 || a1 > n || a2 > n || b1 > m || b2 > m)
	{cout << "������� ������� ����������\n"; system("pause"); return 0;}

	if (a1 == a2 && b1 == b2)
	{cout << "���������� ������ ��������� � ������������ ������\n"; system("pause"); return 0;}

	if (Lst[a1-1][b1-1] == -1 || Lst[a2-1][b2-1] == -1)
	{ cout << "������ ���\n"; system("pause"); return 0; }

	ArrayStack a(n*m);
	k = 0;

			if (Lst[a1-1][b1-1] == 0)
			{
				a.push(a1-1, b1-1);
				Lst[a1-1][b1-1] = ++k;

				while (!a.isEmpty())
				{
					a.peek(&x, &y);
					if (x+1 == a2 && y+1 == b2) goto A;
					if (x > 0 && Lst[x - 1][y] == 0)
					{
						x1 = x - 1;
						a.push(x1, y);
						Lst[x1][y] = ++k;
						continue;
					}

					else
					if (x < n - 1 && Lst[x + 1][y] == 0)
					{
						x1 = x + 1;
						a.push(x1, y);
						Lst[x1][y] = ++k;
						continue;
					}
					else
					if (y > 0 && Lst[x][y - 1] == 0)
					{
						y1 = y - 1;
						a.push(x, y1);
						Lst[x][y1] = ++k;
						continue;
					}
					else
					if (y < m - 1 && Lst[x][y + 1] == 0)
					{
						y1 = y + 1;
						a.push(x, y1);
						Lst[x][y1] = ++k;
						continue;
					}
					else k--;

					a.pop();

				}
			}

	system("cls");

	cout << "\n\t������ ��� \n\n"; system("pause");
	return 0;

A:
	system("cls");

	cout << "������ ���� \n\n\n"<< "\t�������:\n\n";

	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			cout << setw(3) << Lst[i][j] << " ";
		}
		cout << endl << endl;
	}
	
	system("pause");
	return 0;
}
