/*Мацкевич Максим ПМ 8
2.1	Задан текстовый файл Input.txt, в котором есть некоторые числа, 
каждое число в отдельной строке. Создать  две очереди, 
в первой – простые числа, во второй _ палиндромы. 
Построить новую очередь, включив в нее по одному  разу элементы, 
которые входят хотя бы в одну из очередей Queue1 или Queue2. 
Результат записать в текстовый  файл.

Решение
1)Создадим 3 очереди
2)считывая из файла числа, будем записывать их в очереди 1 и (или) 2
если они удолетворяют требованиям задачи  (простые и палиндромы)
3)т.к в третья очередь это по сути объединение 2-х други очередей
то мы просто объединяем 2 условия ,при этом проверяя не содержится
ли уже данный элемент в очереди.
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
#include "Queue.h"
using namespace std;
ofstream out;

bool prost(int x);
bool palindrom(char *s);
int main()
{
	Queue  q3, q1, q2;
	setlocale(LC_ALL, "rus");
	ifstream in; in.open("input.txt");	
	 out.open("output.txt");
	int a;
	char s[20];
	while (!in.eof())
	{
		in >> a;
		itoa(a, s, 10);
		if (prost(a))  q1.Push(a);
		if (palindrom(s)) q2.Push(a);

      if (   ( prost(a) || palindrom(s) )   &&  !q3.Find(a)) q3.Push(a);
	}

	out << "Очередь 1\n"; q1.Print(out);
	out <<'\n'<< "Очередь 2\n"; q2.Print( out);
	out <<'\n'<< "Очередь 3\n"; q3.Print( out);
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

