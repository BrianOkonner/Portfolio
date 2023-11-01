// Кветко Никита
#include <iostream>
#include "Stack.h"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	Stack test;
	int N, *number, dat; 
	cout << "Введите количество чисел: "; cin >> N;
	cout << "Числа: ";
	for (int i = 0; i < N; i++) {
		dat = rand() % 100;
		cout << dat << ' ';
		number = &dat;
		test.push(new int(dat)); // используем конструктор копирования
	}
	cout << endl;
	int *x;
	cout << "Содержимое стека: ";
	while (!test.empty()) {
		x = (int*)test.pop();
		cout << *x << ' ';
	}
	cout << endl;
	system("pause");
}