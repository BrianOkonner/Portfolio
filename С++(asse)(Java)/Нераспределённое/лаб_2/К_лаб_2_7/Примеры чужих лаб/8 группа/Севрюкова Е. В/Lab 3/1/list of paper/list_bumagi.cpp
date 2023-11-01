/*Из листа клетчатой бумаги размером N x M удалили некоторые клетки.
Определить, на сколько связных кусков распадается оставшаяся часть листа. 
К - количество удалённых клеток.*/

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

	ArrayStack a(n*m);
	k = 0;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			if (Lst[i][j] == 0)
			{
				k++;
				a.push(i, j);
				Lst[i][j] = k;
		
				while (!a.isEmpty())
				{
					while (!a.isEmpty())
					{
						a.peek(&x, &y);
						if (x>0 && Lst[x - 1][y] == 0)
						{
							x1 = x - 1;
							a.push(x1, y);
							Lst[x1][y] = k;
						}

						if (x<n - 1 && Lst[x + 1][y] == 0)
						{
							x1 = x + 1;
							a.push(x1, y);
							Lst[x1][y] = k;
						}
						if (y>0 && Lst[x][y - 1] == 0)
						{
							y1 = y - 1;
							a.push(x, y1);
							Lst[x][y1] = k;
						}
						if (y<m - 1 && Lst[x][y + 1] == 0)
						{
							y1 = y + 1;
							a.push(x, y1);
							Lst[x][y1] = k;
						}
						a.pop();
					}
				}
			}
		} 
	}  

	cout << "Количество кусков k=" << k << endl<< endl;

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
