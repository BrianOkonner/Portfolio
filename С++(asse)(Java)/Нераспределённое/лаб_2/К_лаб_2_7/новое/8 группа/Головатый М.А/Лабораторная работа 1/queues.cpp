/*Алгоритм задачи на использование динамической очереди :
Проверяем число на простоту и на палиндром и в зависимости от результата заносим его в очереди.
Если элемент занёсся в одну из очередей заносим его в третью, и только в том случае если пройдя по очереди таких элементов мы не встретили.
Тесты :
input.txt : 12 3 14 87178  3 1221 18 715 19 194 71 5 13 5 91 9 5 7 5
	***********Палиндромы и очереди***********
	Исходная последовательность находится в файле input.txt.
	Очередь 1
	3 3 19 71 5 13 5 5 7 5 
	Очередь 2
	3 87178 3 1221 5 5 9 5 7 5 
	Очередь 3
	87178 1221 71 19 13 9 7 5 3 
	*/
#include "header.h"
ofstream out;

void queue_func()
{
	queue <int> q3, q1, q2;
	priority_queue <int> q;
	setlocale(LC_ALL, "rus");
	ifstream in; in.open("input.txt");
	out.open("output.txt");
	int a;
	char s[20];
	while (!in.eof())
	{
		in >> a;
		_itoa_s(a, s, 10);
		if (prost(a))  q1.push(a);
		if (palindrom(s)) q2.push(a);

		if (prost(a) || palindrom(s)) q.push(a);
	}
	if (!q.empty())
	{
		a = q.top();
		q.pop();
	}

	while (!q.empty())
	{
		if (a != q.top()) q3.push(a);
		a = q.top();
		q.pop();
	}
	q3.push(a);

	out << "Очередь 1\n"; print(q1);
	out << '\n' << "Очередь 2\n"; print(q2);
	out << '\n' << "Очередь 3\n"; print(q3);
	out.close();
	in.close();
}
void print(queue <int> q)		//Печать содержимого 
{
	while (!q.empty())
	{
		out << q.front() << ' ';
		q.pop();
	}
}
bool prost(int a)
{
	for (int i = 2; i <= (a / i); i++)
		if (!(a%i)) return 0;
	return 1;
}

bool palindrom(char *s)
{
	for (int i = 0; i<strlen(s) / 2; i++)
		if (s[i] != s[strlen(s) - i - 1]) return 0;
	return 1;
}