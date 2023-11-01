/*Мацкевич Максим ПМ 8
2.1	Задан текстовый файл Input.txt, в котором есть некоторые числа,
каждое число в отдельной строке. Создать  две очереди,
в первой – простые числа, во второй _ палиндромы.
Построить новую очередь, включив в нее по одному  разу элементы,
которые входят хотя бы в одну из очередей Queue1 или Queue2.
Результат записать в текстовый  файл.

Решение
1)Создадим 4 очереди (вспомогательная очередь(q3) будет автомотически отсортирована по восрастанию)
2)считывая из файла числа, будем записывать их в очереди 1 и (или) 2
если они удолетворяют требованиям задачи  (простые и палиндромы)
3) вспомогательная очередь это- объединение 2-х други очередей.
4)Для получения третьей очереди проверяем на неравенство двух соседних элементов 
из вспомогательной очереди(т.к. вспом. очередь отсортирована по  восрастанию) 

Ввод и вывод через файлы

                      Тесты
Ввод:
3 45 123321 56 11 10 41 100 53 11
Вывод:
Очередь 1
3 11 41 53 11
Очередь 2
3 123321 11 11
Очередь 3
123321 53 41 11 3
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
ofstream out;

void print(queue <int> q);	
bool prost(int x);
bool palindrom(char *s);
int main()
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
		itoa(a, s, 10);
		if (prost(a))  q1.push(a);
		if (palindrom(s)) q2.push(a);

      if (prost(a) || palindrom(s)) q.push(a);
	}
if (!q.empty()) 
	{a=q.top();
     q.pop(); }

while (!q.empty())
 {
	if (a!=q.top()) q3.push(a);
    a=q.top();
    q.pop();
 }
q3.push(a);

	out << "Очередь 1\n"; print(q1);
	out <<'\n'<< "Очередь 2\n"; print(q2);
	out <<'\n'<< "Очередь 3\n"; print(q3);
	out.close();
	in.close();
	system("pause");
	return 0;
}

bool prost(int a)
{for (int i=2; i<=(a/i); i++)
if (!(a%i)) return 0;
return 1;
}

bool palindrom(char *s)
{
	for (int i = 0; i<strlen(s) / 2; i++)
		if (s[i] != s[strlen(s) - i - 1]) return 0;
	return 1;
}

void print(queue <int> q)		//Печать содержимого 
{
	while (!q.empty())
	{
		out <<q.front()<<' ';
		q.pop();		
	}
}