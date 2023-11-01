/*
Андреев Дмитрий 8 группа

Задание 3_1:
Из листа клетчатой бумаги размером N x M удалили некоторые клетки.
Определить, на сколько связных кусков распадается оставшаяся часть листа.
К - количество удалённых клеток.

Среда разработки MS Visual Studio 2017
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "ArrayStack.h"

using namespace std;

void main()
{
	setlocale(0, "rus");
	ifstream in;
	in.open("input.txt");
	
	int i, j, n, m;
	int **s; 
	in >> n >> m;

	cout << "Данный лист:"<< endl << endl;

	s = new int *[n];

	for (i = 0; i<n; i++)
	{
		s[i] = new int[m];

		for (j = 0; j<m; j++)
		{
			in >> s[i][j];
			cout << setw(3) << ' ' << setw(3) << s[i][j] << " ";
		}
		cout << endl << endl;
	}

	int x, y, x1, y1;

	ArrayStack a(n*m);

	int k = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j<m; j++)
		{
			if (s[i][j] == 0)
			{
				k++;
				a.push(i, j);
				s[i][j] = k;

				while (!a.isEmpty())
				{
					while (!a.isEmpty())
					{
						a.topel(&x, &y);
						if (x>0 && s[x - 1][y] == 0)
						{
							x1 = x - 1;
							a.push(x1, y);
							s[x1][y] = k;
						}

						if (x<n - 1 && s[x + 1][y] == 0)
						{
							x1 = x + 1;
							a.push(x1, y);
							s[x1][y] = k;
						}

						if (y>0 && s[x][y - 1] == 0)
						{
							y1 = y - 1;
							a.push(x, y1);
							s[x][y1] = k;
						}

						if (y<m - 1 && s[x][y + 1] == 0)
						{
							y1 = y + 1;
							a.push(x, y1);
							s[x][y1] = k;
						}
						a.pop();
					}
				}
			}
		}
	}

	cout << "Лист разделится на " << k <<" кусков:" <<  endl << endl;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j<m; j++)
		{
			in >> s[i][j];
			cout << setw(3) << ' ' << setw(3) << s[i][j] << " ";
		}
		cout << endl << endl;
	}

	system("pause");
}