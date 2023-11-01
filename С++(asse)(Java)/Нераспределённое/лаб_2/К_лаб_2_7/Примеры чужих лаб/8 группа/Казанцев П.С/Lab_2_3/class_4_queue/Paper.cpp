#include "Queue.h"

void Paper() {
	ifstream in("Paper.txt");
	int N, M, **Lst;
	in >> N >> M;
	if (N <= 0 || M <= 0)
		throw 5;

	Lst = new int *[N];
	for (int i = 0; i < N; i++)
		Lst[i] = new int[M];

	int i, j, k, x, y, x1, y1;
	cout << "-1 - обозначение дырки в листе" << endl << endl;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			in >> Lst[i][j];
			cout << setw(4) << Lst[i][j] << " ";
		}
		cout << endl;
	}
	in.close();

	Queue_on_Array X_queue(100), Y_queue(100);
	k = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (Lst[i][j] == 0) {
				k++;
				X_queue.push_back(i);
				Y_queue.push_back(j);
				Lst[i][j] = k;

				while (!X_queue.isEmpty()) {
					while (!X_queue.isEmpty()) {
						x = X_queue.front();
						y = Y_queue.front();
						if (x > 0 && Lst[x - 1][y] == 0) {
							x1 = x - 1;
							X_queue.push_back(x1);
							Y_queue.push_back(y);
							Lst[x1][y] = k;
						}
						if (x < N - 1 && Lst[x + 1][y] == 0) {
							x1 = x + 1;
							X_queue.push_back(x1);
							Y_queue.push_back(y);
							Lst[x1][y] = k;
						}
						if (y > 0 && Lst[x][y - 1] == 0) {
							y1 = y - 1;
							X_queue.push_back(x);
							Y_queue.push_back(y1);
							Lst[x][y1] = k;
						}
						if (y < M - 1 && Lst[x][y + 1] == 0) {
							y1 = y + 1;
							X_queue.push_back(x);
							Y_queue.push_back(y1);
							Lst[x][y1] = k;
						}
						X_queue.pop_front();
						Y_queue.pop_front();
					}
				}
			}
		}
	}

	cout << endl << endl << "Количество кусков равно - " << k << endl;
	system("pause");
	system("cls");
}

