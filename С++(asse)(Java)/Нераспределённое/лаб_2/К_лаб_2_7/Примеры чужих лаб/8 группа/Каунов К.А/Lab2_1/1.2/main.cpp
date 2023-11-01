/*
1 курс
8 группа

Каунов

Условие: 1.2	Описать процедуру, которая подсчитывает количество элементов стека, у которых равные "соседи".

Алгоритм:
*/

#include <iostream>
#include <fstream>
#include <stack>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
	stack <int> s;

	for (int i = 0; i < 10; i++)
	{
		int a = rand() % 10;
		s.push(a);
	}

	int a, b;

	a = s.top();
	cout << a << " ";
	s.pop();
	b = s.top();
	cout << b << " ";
	int c, count = 0;
	while (!s.empty())
	{
		c = s.top();
		cout << c << " ";
		s.pop();
		if (a == c) count++;
		a = b;
		b = c;
	}

	cout << "\n";
	cout << count;
	system("pause");
}
