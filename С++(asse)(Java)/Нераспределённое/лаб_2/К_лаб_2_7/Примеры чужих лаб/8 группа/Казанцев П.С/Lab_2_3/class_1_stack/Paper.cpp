#include "Stack.h"

void Paper() {
	system("cls");
	ifstream in("Input.txt");
	int N, M, **List;
	in >> N >> M;

	List = new int*[N];

	for (int i = 0; i < N; i++)
		List[i] = new int[M];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			in >> List[i][j];
			cout << setw(3) << List[i][j] << " ";
		}
		cout << endl;
	}

	int x, y, x1, y1, i, j, k = 0;
	Stack_on_Array X(100), Y(100);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (List[i][j] == 0) {
				X.Push(i);
				Y.Push(j);
				k++;
				List[i][j] = -1;
				while (!X.isEmpty()) {
					x = X.Pop();
					y = Y.Pop();
					List[x][y] = -1;
					if (x > 0 && List[x - 1][y] == 0) {
						X.Push(x - 1);
						Y.Push(y);
					}
					if (y < N - 1 && List[x][y + 1] == 0) {
						X.Push(x);
						Y.Push(y + 1);
					}
					if (x < M - 1 && List[x + 1][y] == 0) {
						X.Push(x + 1);
						Y.Push(y);
					}
					if (y > 0 && List[x][y - 1] == 0) {
						X.Push(x);
						Y.Push(y - 1);
					}
				}
			}
		}

	cout << endl << "Количество кусков равно - " << k << endl;

	system("pause");
	system("cls");
}
