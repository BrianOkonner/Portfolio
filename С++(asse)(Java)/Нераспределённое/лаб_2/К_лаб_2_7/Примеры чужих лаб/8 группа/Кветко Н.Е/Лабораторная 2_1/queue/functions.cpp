#include <iostream>
#include <queue>
using namespace std;

int compare(const void*x1, const void*x2) {
	return (*(int*)x1 - *(int*)x2);
}

bool Prime(int x) {
	bool res = true;
	for (int i = 1; i <= x; ++i)
		if ((x%i == 0) && (i != 1) && (i != x)) res = false;
	return res;
}

void MoveLeft(int *a, int *n, int num)
{
	for (int i = num; i < *n - 1; i++) a[i] = a[i + 1];
	(*n)--;
}

bool is_palindrom(int x) {
	priority_queue <int> q1, q2;
	int b = x, counter = 0, counter2 = 0;
	while (b) {
		b /= 10;
		counter++;
	}
	while (counter2 < counter / 2) {
		q1.push(x % 10);
		x /= 10;
		counter2++;
	}
	if (counter % 2 == 1) x /= 10;
	while (x) {
		q2.push(x % 10);
		x /= 10;
	}
	bool flag = true;
	while(!q1.empty()) {
		if (q1.top() != q2.top()) flag = false;
		q1.pop();
		q2.pop();
	}
	return flag;
}