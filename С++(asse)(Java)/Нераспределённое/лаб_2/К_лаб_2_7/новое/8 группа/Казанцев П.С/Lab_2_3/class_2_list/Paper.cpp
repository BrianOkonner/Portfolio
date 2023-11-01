#include "list.h"

void Paper()
{
	ifstream fin("Paper.txt");
	int N, M, **Lst;
	fin >> N >> M;
	if (N <= 0 || M <= 0)
		throw 2;

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

	List X_list, Y_list;
	k = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (Lst[i][j] == 0) {
				k++;
				X_list.push_head(i);
				Y_list.push_head(j);
				Lst[i][j] = k;

				while (!X_list.isEmpty()) {
					while (!X_list.isEmpty()) {
						x = X_list.front();
						y = Y_list.front();
						if (x > 0 && Lst[x - 1][y] == 0) {
							x1 = x - 1;
							X_list.push_back(x1);
							Y_list.push_back(y);
							Lst[x1][y] = k;
						}
						if (x < N - 1 && Lst[x + 1][y] == 0) {
							x1 = x + 1;
							X_list.push_back(x1);
							Y_list.push_back(y);
							Lst[x1][y] = k;
						}
						if (y > 0 && Lst[x][y - 1] == 0) {
							y1 = y - 1;
							X_list.push_back(x);
							Y_list.push_back(y1);
							Lst[x][y1] = k;
						}
						if (y < M - 1 && Lst[x][y + 1] == 0) {
							y1 = y + 1;
							X_list.push_back(x);
							Y_list.push_back(y1);
							Lst[x][y1] = k;
						}
						X_list.remove_head();
						Y_list.remove_head();
					}
				}
			}
		}
	}

	cout << endl << endl << "Number of pieces: " << k << endl;
	system("pause");
	system("cls");
}