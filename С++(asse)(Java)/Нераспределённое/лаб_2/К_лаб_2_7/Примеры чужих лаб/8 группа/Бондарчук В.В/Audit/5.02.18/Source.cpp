// 1 курс
// Бондарчук Владимир 
// Группа 8
//
//
// 1.2 Описать процедуру, которая подсчитывает количество элементов стека, у которых равные "соседи".  
//
//
//
//
//
//
//
//
//
//
//
//
#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

stack <int> s;

int main() {
	setlocale(LC_ALL, "rus");
	int c, i = 0;
	cout << "Заполните стек" << endl;
	cout << "-1 для выхода" << endl;
	do 
	{
		cin >> c;
		if (c != -1) 
		{ 
			s.push(c); i++; 
		}
	} while (c != -1);

	if (i <= 2) {
		cout << "Элементов 2 или меньше" << endl;
		system("pause");
		return 0;
	}
	int a, b, d;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	d = s.top();
	s.pop();

	int n = 0;

	while (s.empty() != true)
	{
		if (a == d) ++n;
		a = b;
		b = d;
		d = s.top();
		s.pop();
	}

	if (a == d) ++n;

	cout << " элементов с одинаковыми соседями = " << n << endl;
	system("pause");

	return 0;
}
