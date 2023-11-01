#include "Queue.h"


void Iosif() {
	int N;
	cout << "Введите количество участников " << endl;
	cin >> N;
	Queue_on_Array Queue(N);

	cout << "Введите шаг удаления " << endl;
	int M;
	cin >> M;
	cout << endl;

	if (M < 2 || N < 1) {
		system("cls");
		throw 5;
	}

	for (int i = 1; i <= N; Queue.push_back(i), ++i);

	while (N != 1) {
		for (int i = 1; i <= M; i++) {
			if (i == M) int q = Queue.pop_front();
			else {
				int u = Queue.pop_front();
				Queue.push_back(u);
			}
		}
		--N;
	}

	cout << "Last Man Standing : " << Queue.pop_front() << endl;
	system("pause");
	system("cls");
}

