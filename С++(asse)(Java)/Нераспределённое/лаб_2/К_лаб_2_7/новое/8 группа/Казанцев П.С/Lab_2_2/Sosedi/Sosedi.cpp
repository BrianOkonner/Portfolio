#include <iostream>
#include "stack.h"
#include <ctime>
using namespace std;

int main(void)
{
	
	setlocale(LC_ALL, "ru");
	MyStack s;
	int n, i, x;
	cout << "Input the number of stack elements" << endl;
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		x = rand() % 10;
		s.Push(new int(x));
		cout << x << " ";
	}
	cout << endl;

	int s1, s2, temp, c = 0;
	for (i = 1; i < n - 1; i++)
	{
		s1 = *(int*)s.Top();
		s.Pop();
		temp = *(int*)s.Top();
		s.Pop();
		s2 = *(int*)s.Top();
		s.Push(new int(temp));
		if (s1 == s2)
			c++;
	}
	cout << "Amount of elements with equal neighbours : " << c << endl;
	system("pause");
	return 0;
}
