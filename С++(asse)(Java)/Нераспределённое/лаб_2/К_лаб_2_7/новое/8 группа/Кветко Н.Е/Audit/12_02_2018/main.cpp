// ������ ������
#include <iostream>
#include "Stack.h"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	Stack test;
	int N, *number, dat; 
	cout << "������� ���������� �����: "; cin >> N;
	cout << "�����: ";
	for (int i = 0; i < N; i++) {
		dat = rand() % 100;
		cout << dat << ' ';
		number = &dat;
		test.push(new int(dat)); // ���������� ����������� �����������
	}
	cout << endl;
	int *x;
	cout << "���������� �����: ";
	while (!test.empty()) {
		x = (int*)test.pop();
		cout << *x << ' ';
	}
	cout << endl;
	system("pause");
}