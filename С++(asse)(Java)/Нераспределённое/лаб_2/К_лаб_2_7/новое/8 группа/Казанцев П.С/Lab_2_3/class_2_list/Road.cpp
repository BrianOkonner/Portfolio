#include "list.h"
#include <Windows.h>

void Road() {
	ifstream in("Road.txt");

	int N, M;
	in >> N >> M;

	int **Road;
	Road = new int *[N];
	for (int i = 0; i < N; i++)
		Road[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			in >> Road[i][j];
			cout << setw(3) << Road[i][j] << " ";
		}
		cout << endl;
	}

	int Xs, Ys, Xf, Yf;
	cout << "Введите стартовые координаты робота(x, y)\n";
	cin >> Xs >> Ys;
	cout << "Введите конечные координаты робота(x, y) \n";
	cin >> Xf >> Yf;
	cout << endl  << "Ответ:" << endl;

	if (N <= 0 || M <= 0 || Xs < 0 || Ys < 0 || Xf < 0 || Yf < 0 || Xs >= N || Ys >= M || Xf >= N || Yf >= M) {
		system("cls");
		throw 2;
	}

	if (Road[Xs][Ys] == -1 || Road[Xf][Yf] == -1) {
		cout << endl << endl;
		cout << "Дороги нет.\n Начальная или конечная точка - болото " << endl;
		Sleep(1000);
		system("cls");
		return;
	}

	if ((Xs == Xf) && (Ys == Yf)) {
		cout << endl << endl ;
		cout << "Начальная и конечная точки совпадают" << endl;
		Sleep(1000);
		system("cls");
		return;
	}

	List X_list, Y_list;

	X_list.push_back(Xs);
	Y_list.push_back(Ys);

	int x, y;
	bool flag = true;
	while (true) {
		while (!X_list.isEmpty()) {
			x = X_list.front();
			X_list.remove_head();
			y = Y_list.front();
			Y_list.remove_head();
			Road[x][y] = -1;
			if (x > 0 && Road[x - 1][y] == 0) {
				if (x - 1 == Xf && y == Yf) {
					cout << "Дорога существует" << endl;
					Sleep(1000);
					system("cls");
					return;
				}
				X_list.push_back(x - 1);
				Y_list.push_back(y);
			}
			if (y < M - 1 && Road[x][y + 1] == 0) {
				if (x == Xf && y + 1 == Yf) {
					cout << "Дорога существует" << endl;
					Sleep(1000);
					system("cls");
					return;
				}
				X_list.push_back(x);
				Y_list.push_back(y + 1);
			}
			if (x < N - 1 && Road[x + 1][y] == 0) {
				if (x + 1 == Xf && y == Yf) {
					cout << "Дорога существует" << endl;
					Sleep(1000);
					system("cls");
					return;
				}
				X_list.push_back(x + 1);
				Y_list.push_back(y);
			}
			if (y > 0 && Road[x][y - 1] == 0) {
				if (x == Xf && y - 1 == Yf) {
					cout << "Дорога существует" << endl;
					Sleep(1000);
					system("cls");
					return;
				}
				X_list.push_back(x);
				Y_list.push_back(y - 1);
			}
		}
		cout << "Дороги нет" << endl;
		break;
	}

	in.close();
	Sleep(1000);
	system("cls");
}
