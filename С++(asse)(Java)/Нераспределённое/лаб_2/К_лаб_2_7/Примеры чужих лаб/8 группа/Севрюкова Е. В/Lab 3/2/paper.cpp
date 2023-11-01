/*Из листа клетчатой бумаги размером N x M удалили некоторые клетки.
Определить, на сколько связных кусков распадается оставшаяся часть листа.
К - количество удалённых клеток.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "list.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream in; in.open("input2.txt");
	if (!in.is_open()) { cout << "File is not found"; return 0; }
	int i, j, n, m, k, x, y, x1, y1;
	int **Lst;  //матрица для хранения листа бумаги
	in >> n >> m;

	cout << "Лист бумаги дырки: -1 \n\n";
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

	List X;
	List Y;

	k = 0;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			if (Lst[i][j] == 0)
			{
				k++;
				X.push_head(i);
				Y.push_head(j);
				Lst[i][j] = k;

				while (!X.isEmpty())
				{
					while (!Y.isEmpty())
					{
						x = X.front();
						y = Y.front();
						if (x>0 && Lst[x - 1][y] == 0)
						{
							x1 = x - 1;
							X.push_head(x1);
							Y.push_head(y);
							Lst[x1][y] = k;
						}

						if (x<n - 1 && Lst[x + 1][y] == 0)
						{
							x1 = x + 1;
							X.push_head(x1);
							Y.push_head(y);
							Lst[x1][y] = k;
						}
						if (y>0 && Lst[x][y - 1] == 0)
						{
							y1 = y - 1;
							X.push_head(x);
							Y.push_head(y1);
							Lst[x][y1] = k;
						}
						if (y<m - 1 && Lst[x][y + 1] == 0)
						{
							y1 = y + 1;
							X.push_head(x);
							Y.push_head(y1);
							Lst[x][y1] = k;
						}
						X.remove_head();
						Y.remove_head();
					}
				}
			}
		}
	}

	cout << "Количество кусков k=" << k << endl << endl;

	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			in >> Lst[i][j];
			cout << setw(3) << Lst[i][j] << " ";
		}
		cout << endl << endl;
	}

	system("pause");
	return 0;
}
