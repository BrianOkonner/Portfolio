/*
������� ������� 8 ������

������� 3_2
������:

������� ���� ���������, �������� �� ��������, �������� �������� �������� M x N.
������ ������� ����� ���� �� ����������� :  0, ���� � �������� ������ �����, � -1, ���� � �������� ������.
���������� ����������, ������� �� � ������� ������ �� ������� (��, ��)	� ������� (��, ��),
���� ����� ����� ��������� ������ �� ������ ��������� � ������ � �������������� � ������������ ������������.
��� ���� ����� ������ ��������� ��������� ������.

����� ���������� MS Visual Studio 2017
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "ArrayList.h"
using namespace std;


int main()
{
	setlocale(0, "rus");

	ifstream in;
	in.open("input.txt");

	int i, j, n, m;

	int **terrain;
	in >> n >> m;

	terrain = new int *[n];
	cout << "\n��� � ����� �������, ��� � ������ ����.\n";

	for (i = 0; i<n; i++)
	{
		terrain[i] = new int[m];
		for (j = 0; j<m; j++)
		{
			in >> terrain[i][j];
			cout << setw(3) << terrain[i][j] << " ";
		}
		cout << endl << endl;
	}

	int y11, x11, y21, x21;
inagain:

	cout << "����� ��: \nx = "; cin >> x11; cout << "y = "; cin >> y11;
	cout << "������ �: \nx = "; cin >> x21; cout << "y = "; cin >> y21;

	if (y11 <= 0 || y21 <= 0 || x11 <= 0 || x21 <= 0 || y11 > n || y21 > n || x11 > m || x21 > m)
	{
		cout << "������. �������� ����������. ���������� ��� ���: \n";
		goto inagain;
	}

	if (y11 == y21 && x11 == x21)
	{
		cout << "����� ��������� �� �����.\n ���������� ��� ���:\n";
		goto inagain;
	}

	if (terrain[y11 - 1][x11 - 1] == -1)
	{
		cout << "����� �� ����� �������� � ������.\n ���������� ��� ���:\n";
		goto inagain;
	}

	if (terrain[y21 - 1][x21 - 1] == -1) {

		cout << "����� �� ����� ������ � ������.\n ���������� ��� ���:\n";
		goto inagain;

	}

	List osx;
	List osy;
	int k = 0, x, y, x1, y1;

	if (terrain[y11 - 1][x11 - 1] == 0)
	{
		osx.push_head(y11 - 1);
		osy.push_head(x11 - 1);
		terrain[y11 - 1][x11 - 1] = ++k;

		while (!osx.isEmpty())
		{
			x = osx.front();
			y = osy.front();
			if (x + 1 == y21 && y + 1 == x21) {
				cout << "����� �������, �������� ���:\n";

				for (i = 0; i<n; i++)
				{
					for (j = 0; j<m; j++)
					{
						cout << setw(3) << terrain[i][j] << " ";
					}
					cout << endl << endl;
				}

				system("pause");
				return 0;
			}
			if (x > 0 && terrain[x - 1][y] == 0)
			{
				x1 = x - 1;
				osx.push_head(x1);
				osy.push_head(y);
				terrain[x1][y] = ++k;
				continue;
			}

			else if (x < n - 1 && terrain[x + 1][y] == 0)
				{
					x1 = x + 1;
					osx.push_head(x1);
					osy.push_head(y);
					terrain[x1][y] = ++k;
					continue;
				}
				
					else if (y < m - 1 && terrain[x][y + 1] == 0)
						{
							y1 = y + 1;
							osx.push_head(x);
							osy.push_head(y1);
							terrain[x][y1] = ++k;
							continue;
						}

						else if (y > 0 && terrain[x][y - 1] == 0)
					{
						y1 = y - 1;
						osx.push_head(x);
						osy.push_head(y1);
						terrain[x][y1] = ++k;
						continue;
					}

						else k--;

						osx.remove_head();
						osy.remove_head();

		}
	}

	cout << "\n����� �� ������ ������ \n\n";
	system("pause");
	return 0;

}
