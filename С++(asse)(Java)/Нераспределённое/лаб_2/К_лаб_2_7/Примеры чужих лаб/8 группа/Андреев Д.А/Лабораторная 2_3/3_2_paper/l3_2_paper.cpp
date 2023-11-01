/*
Андреев Дмитрий 8 группа

Задание 3_2:
Бумага:

Из листа клетчатой бумаги размером N x M удалили некоторые клетки.
Определить, на сколько связных кусков распадается оставшаяся часть листа.
К - количество удалённых клеток.

Среда разработки MS Visual Studio 2017
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

	int **paper;
	in >> n >> m;

	paper = new int *[n];

	cout << "Данный лист:" << endl << endl;

	for (i = 0; i<n; i++)
	{
		paper[i] = new int[m];
		for (j = 0; j<m; j++)
		{
			in >> paper[i][j];
			cout << setw(3) << paper[i][j] << " ";
		}
		cout << endl << endl;
	}

	List osx;
	List osy;

	int k = 0, x, y, x1, y1;

	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			if (paper[i][j] == 0)
			{
				k++;
				osx.push_head(i);
				osy.push_head(j);
				paper[i][j] = k;

				while (!osx.isEmpty())
				{
					while (!osy.isEmpty())
					{
						x = osx.front();
						y = osy.front();
						if (x>0 && paper[x - 1][y] == 0)
						{
							x1 = x - 1;
							osx.push_head(x1);
							osy.push_head(y);
							paper[x1][y] = k;
						}

						if (x<n - 1 && paper[x + 1][y] == 0)
						{
							x1 = x + 1;
							osx.push_head(x1);
							osy.push_head(y);
							paper[x1][y] = k;
						}
						if (y>0 && paper[x][y - 1] == 0)
						{
							y1 = y - 1;
							osx.push_head(x);
							osy.push_head(y1);
							paper[x][y1] = k;
						}
						if (y<m - 1 && paper[x][y + 1] == 0)
						{
							y1 = y + 1;
							osx.push_head(x);
							osy.push_head(y1);
							paper[x][y1] = k;
						}
						osx.remove_head();
						osy.remove_head();
					}
				}
			}
		}
	}

	cout << "Лист разделится на " << k << " кусков:" << endl << endl;

	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			in >> paper[i][j];
			cout << setw(3) << paper[i][j] << " ";
		}
		cout << endl << endl;
	}

	system("pause");
	return 0;
}
