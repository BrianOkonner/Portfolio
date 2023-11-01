#include "Header.h"

void Road() {
	system("cls");
	ifstream fin1("Input1.txt");

	int N, M;
	fin1 >> N >> M;

	int **Road;
	Road = new int *[N];
	for (int i = 0; i < N; i++)
		Road[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			fin1 >> Road[i][j];
			cout << setw(3) << Road[i][j] << " ";
		}
		cout << endl;
	}

	int Xs, Ys, Xf, Yf;
	cout << "Введите стартовые координаты робота(x, y)\n";
	cin >> Xs >> Ys;
	cout << "Введите конечные координаты робота(x, y) \n";
	cin >> Xf >> Yf;
	cout << endl << endl;

	if (N <= 0 || M <= 0 || Xs < 0 || Ys < 0 || Xf < 0 || Yf < 0 || Xs >= N || Ys >= M || Xf >= N || Yf >= M) {
		system("cls");
		throw 5;
	}

	if (Road[Xs][Ys] == -1 || Road[Xf][Yf] == -1) {
		cout << endl << endl << endl;
		cout << "Дороги нет.\n Начальная/конечная точка - болото " << endl;
		Sleep(6000);
		system("cls");
		return;
	}

	if ((Xs == Xf) && (Ys == Yf)) {
		cout << endl << endl << endl;
		cout << "Начальная и конечная точки совпадают" << endl;
		Sleep(6000);
		system("cls");
		return;
	}

	ArrayStack Xstack(100), Ystack(100);

	Xstack.Push(Xs);
	Ystack.Push(Ys);

	int x, y;
	bool flag = true;
	while (true) {
		while (!Xstack.isEmpty()) {
			x = Xstack.Pop();
			y = Ystack.Pop();
			Road[x][y] = -1;
			if (x > 0 && Road[x - 1][y] == 0) {
				if (x - 1 == Xf && y == Yf) {
					cout << "Дорога существует" << endl;
					Sleep(6000);
					system("cls");
					return;
				}
				Xstack.Push(x - 1);
				Ystack.Push(y);
			}
			if (y < M - 1 && Road[x][y + 1] == 0) {
				if (x == Xf && y + 1 == Yf) {
					cout << "Дорога существует" << endl;
					Sleep(6000);
					system("cls");
					return;
				}
				Xstack.Push(x);
				Ystack.Push(y + 1);
			}
			if (x < N - 1 && Road[x + 1][y] == 0) {
				if (x + 1 == Xf && y == Yf) {
					cout << "Дорога существует" << endl;
					Sleep(6000);
					system("cls");
					return;
				}
				Xstack.Push(x + 1);
				Ystack.Push(y);
			}
			if (y > 0 && Road[x][y - 1] == 0) {
				if (x == Xf && y - 1 == Yf) {
					cout << "Дорога существует" << endl;
					Sleep(6000);
					system("cls");
					return;
				}
				Xstack.Push(x);
				Ystack.Push(y - 1);
			}
		}
		cout << "Дороги нет" << endl;
		break;
	}

	fin1.close();
	Sleep(6000);
	system("cls");

}