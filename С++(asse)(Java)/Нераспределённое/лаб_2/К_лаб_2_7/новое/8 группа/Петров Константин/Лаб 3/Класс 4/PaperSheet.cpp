#include "Header.h"

void PaperSheet() {
	ifstream fin("Input.txt");
	int N, M, **Lst;
	fin >> N >> M;
	if (N <= 0 || M <= 0)
		throw 5;

	Lst = new int *[N];
	for (int i = 0; i < N; i++)
		Lst[i] = new int[M];

	int i, j, k, x, y, x1, y1;
	cout << "-1 - обозначение дырки в листе" << endl << endl;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			fin >> Lst[i][j];
			cout << setw(4) << Lst[i][j] << " ";
		}
		cout << endl;
	}
	fin.close();

	ArrayQueue Xqueue(100), Yqueue(100);
	k = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (Lst[i][j] == 0) {
				k++;
				Xqueue.Push(i);
				Yqueue.Push(j);
				Lst[i][j] = k;

				while (!Xqueue.IsEmpty()) {
					while (!Xqueue.IsEmpty()) {
						x = Xqueue.Peek();
						y = Yqueue.Peek();
						if (x > 0 && Lst[x - 1][y] == 0) {
							x1 = x - 1;
							Xqueue.Push(x1);
							Yqueue.Push(y);
							Lst[x1][y] = k;
						}
						if (x < N - 1 && Lst[x + 1][y] == 0) {
							x1 = x + 1;
							Xqueue.Push(x1);
							Yqueue.Push(y);
							Lst[x1][y] = k;
						}
						if (y > 0 && Lst[x][y - 1] == 0) {
							y1 = y - 1;
							Xqueue.Push(x);
							Yqueue.Push(y1);
							Lst[x][y1] = k;
						}
						if (y < M - 1 && Lst[x][y + 1] == 0) {
							y1 = y + 1;
							Xqueue.Push(x);
							Yqueue.Push(y1);
							Lst[x][y1] = k;
						}
						Xqueue.Pop();
						Yqueue.Pop();
					}
				}
			}
		}
	}

	cout << endl << endl << endl << "Количество кусков равно - " << k << endl;
	Sleep(5000);
	system("cls");
}

