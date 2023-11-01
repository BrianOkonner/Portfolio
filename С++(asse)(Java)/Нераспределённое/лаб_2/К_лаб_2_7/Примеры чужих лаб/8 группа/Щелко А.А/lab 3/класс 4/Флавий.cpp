#include "Header.h"


void main(void) {
	setlocale(LC_ALL, "rus");
	int N;
	cout << "������� ���������� ���������� " << endl;
	cin >> N;
	while (N < 1) {
		cout << "������������ ���� N, ���������� ��� ���..." << endl;
		cin >> N;
	}
	ArrayQueue Q1(N);

	cout << "������� ��� �������� " << endl;
	int M;
	cin >> M;
	cout << endl;

	while (M < 1) {
		cout << "������������ ���� M, ���������� ��� ���..." << endl;
		cin >> M;
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
		N--;
	}

	cout << "��������� ��������  " << Q1.Pop() << endl;
	system("pause");
}
