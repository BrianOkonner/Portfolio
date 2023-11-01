#include "Header.h"


void Flavii() {
	int N;
	cout << "Введите количество участников " << endl;
	cin >> N;
	ArrayQueue Q1(N);

	cout << "Введите шаг удаления " << endl;
	int M;
	cin >> M;
	cout << endl;

	if (M < 1 || N < 1) {
		system("cls");
		throw 5;
	}

	for (int i = 1; i <= N; Q1.Push(i), ++i);

	while (N != 1) {
		for (int i = 1; i <= M; i++) {
			if (i == M) int q = Q1.Pop();
			else {
				int u = Q1.Pop();
				Q1.Push(u);
			}
		}
		--N;
	}

	cout << endl << "Последний участник - " << Q1.Pop() << endl;
	Sleep(5000);
	system("cls");
}
