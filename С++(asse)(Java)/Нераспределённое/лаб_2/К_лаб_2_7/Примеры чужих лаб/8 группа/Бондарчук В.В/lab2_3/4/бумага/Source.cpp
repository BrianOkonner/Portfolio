#include"Header.h"
int main()
{
	try
	{
			ifstream fin("Input.txt");
			setlocale(0, "rus");
			int N, M, **Lst;
			fin >> N >> M;
			if (N <= 0 || M <= 0)
				throw 5;
			Lst = new int *[N];
			for (int i = 0; i < N; i++)
				Lst[i] = new int[M];
			int i, j, k, x, y, x1, y1;
			for (i = 0; i < N; i++) 
{
				for (j = 0; j < M; j++) 
{
					fin >> Lst[i][j];
					cout << setw(4) << Lst[i][j] << " ";
				}
				cout << endl;
			}
			fin.close();
			ArrayQueue Xqueue(100), Yqueue(100);
			k = 0;
			for (i = 0; i < N; i++) 
{
				for (j = 0; j < M; j++) 
{
					if (Lst[i][j] == 0) 
{
						k++;
						Xqueue.push(i);
						Yqueue.push(j);
						Lst[i][j] = k;

						while (!Xqueue.isEmpty()) 
{
							while (!Xqueue.isEmpty()) 
{
								x = Xqueue.top();
								y = Yqueue.top();
								if (x > 0 && Lst[x - 1][y] == 0) 
{
									x1 = x - 1;
									Xqueue.push(x1);
									Yqueue.push(y);
									Lst[x1][y] = k;
								}
								if (x < N - 1 && Lst[x + 1][y] == 0) 
{
									x1 = x + 1;
									Xqueue.push(x1);
									Yqueue.push(y);
									Lst[x1][y] = k;
								}
								if (y > 0 && Lst[x][y - 1] == 0) 
{
									y1 = y - 1;
									Xqueue.push(x);
									Yqueue.push(y1);
									Lst[x][y1] = k;
								}
								if (y < M - 1 && Lst[x][y + 1] == 0) 
{
									y1 = y + 1;
									Xqueue.push(x);
									Yqueue.push(y1);
									Lst[x][y1] = k;
								}
								Xqueue.del();
								Yqueue.del();
							}
						}
					}
				}
			}
			cout << endl << endl << endl << "Количество кусков равно - " << k << endl;
	}
	catch (int i)
	{
		if (i == 1) cout << "is full" << endl;
		if (i == 2) cout << "is empty" << endl;
	}
	system("pause");
}