#include "Stack.h"

void Road() {
	system("cls");
	ifstream in1("Input1.txt");

	int N, M;
	in1 >> N >> M;

	int **Road;
	Road = new int *[N];
	for (int i = 0; i < N; i++)
		Road[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			in1 >> Road[i][j];
			cout << setw(3) << Road[i][j] << " ";
		}
		cout << endl;
	}

	int Xs, Ys, Xf, Yf;
	cout << "Введите стартовые координаты робота(x, y)\n";
	cin >> Xs >> Ys;
	cout << "Введите конечные координаты робота(x, y) \n";
	cin >> Xf >> Yf;
	cout << endl;

	if (N <= 0 || M <= 0 || Xs < 0 || Ys < 0 || Xf < 0 || Yf < 0 || Xs >= N || Ys >= M || Xf >= N || Yf >= M) {
		system("cls");
		throw 5;
	}

	if (Road[Xs][Ys] == -1 || Road[Xf][Yf] == -1) {
		cout << endl;
		cout << "Дороги нет.\n Начальная или конечная точка - болото " << endl;
		system("pause");
		system("cls");
		return;
	}

	if ((Xs == Xf) && (Ys == Yf)) {
		cout << endl << endl << endl;
		cout << "Начальная и конечная точки совпадают" << endl;
		system("pause");
		system("cls");
		return;
	}

	Stack_on_Array X_stack(100), Y_stack(100);

	X_stack.Push(Xs);
	Y_stack.Push(Ys);

	int x, y;
	bool flag = true;
	while (true) {
		while (!X_stack.isEmpty()) {
			x = X_stack.Pop();
			y = Y_stack.Pop();
			Road[x][y] = -1;
			if (x > 0 && Road[x - 1][y] == 0) {
				if (x - 1 == Xf && y == Yf) {
					cout << "Дорога существует" << endl;
					system("pause");
					system("cls");
					return;
				}
				X_stack.Push(x - 1);
				Y_stack.Push(y);
			}
			if (y < M - 1 && Road[x][y + 1] == 0) {
				if (x == Xf && y + 1 == Yf) {
					cout << "Дорога существует" << endl;
					system("pause");
					system("cls");
					return;
				}
				X_stack.Push(x);
				Y_stack.Push(y + 1);
			}
			if (x < N - 1 && Road[x + 1][y] == 0) {
				if (x + 1 == Xf && y == Yf) {
					cout << "Дорога существует" << endl;
					system("pause");
					system("cls");
					return;
				}
				X_stack.Push(x + 1);
				Y_stack.Push(y);
			}
			if (y > 0 && Road[x][y - 1] == 0) {
				if (x == Xf && y - 1 == Yf) {
					cout << "Дорога существует" << endl;
					system("pause");
					system("cls");
					return;
				}
				X_stack.Push(x);
				Y_stack.Push(y - 1);
			}
		}
		cout << "Дороги нет" << endl;
		break;
	}

	in1.close();
	system("pause");
	system("cls");

}