#include "queue.h"
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

	ArrayQueue X(n*m);
	ArrayQueue Y(n*m);

	k = 0;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			if (Lst[i][j] == 0)
			{
				k++;
				X.push(i);
				Y.push(j);
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
							X.push(x1);
							Y.push(y);
							Lst[x1][y] = k;
						}

						if (x<n - 1 && Lst[x + 1][y] == 0)
						{
							x1 = x + 1;
							X.push(x1);
							Y.push(y);
							Lst[x1][y] = k;
						}
						if (y>0 && Lst[x][y - 1] == 0)
						{
							y1 = y - 1;
							X.push(x);
							Y.push(y1);
							Lst[x][y1] = k;
						}
						if (y<m - 1 && Lst[x][y + 1] == 0)
						{
							y1 = y + 1;
							X.push(x);
							Y.push(y1);
							Lst[x][y1] = k;
						}
						X.del();
						Y.del();
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
