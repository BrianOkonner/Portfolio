/*
Казанцев Павел
1 курс 8 группа

Условие :		Описать процедуру, которая подсчитывает количество элементов стека, у которых равные "соседи".  

*/

#include <stack>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <locale>
using namespace std;

stack <int> s;

int main(void)
{
	setlocale(LC_ALL, "ru");
	int n, i, x;
	cout << "Input the number of stack elements" << endl;
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		x = rand() % 10;
		s.push(x);
		cout << x << " ";
	}
	cout << endl;

	int s1, s2, temp, c = 0;
	for (i = 1; i < n - 1; i++)
	{
		s1 = s.top();
		s.pop();
		temp = s.top();
		s.pop();
		s2 = s.top();
		s.push(temp);
		if (s1 == s2)
			c++;
	}
	cout <<"Amount of elements with equal neighbours : " << c << endl;
	system("pause");
	return 0;
}