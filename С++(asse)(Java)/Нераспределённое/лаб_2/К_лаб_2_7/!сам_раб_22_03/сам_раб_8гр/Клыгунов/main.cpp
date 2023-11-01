/*
Клыгунов Эдуарр, 21 вариант."
*/#include <iostream>
#include "Queue.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	Queue q;
	q.push(5);
	q.push(6);

	int n = q.pop();
	cout << n << endl;
}