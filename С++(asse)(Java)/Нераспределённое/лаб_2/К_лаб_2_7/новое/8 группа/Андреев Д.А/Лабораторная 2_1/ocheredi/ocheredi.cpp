/*
Андреев Дмитрий 8 группа 

Лабораторная 2_1

Задан текстовый файл Input.txt, в котором есть некоторые числа,
каждое число в отдельной строке. Создать  две очереди,
в первой – простые числа, во второй _ палиндромы.
Построить новую очередь, включив в нее по одному  разу элементы,
которые входят хотя бы в одну из очередей Queue1 или Queue2.
Результат записать в текстовый  файл.
Использовать стандартную очередь.

Читаем из файла числа, записываем в очереди 1 и (или) 2, если они подходят\
в очередь 3 записываем палиндромы и протые числа
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
ofstream out;

//вывод в консоль с сохранением очередей
queue <int> cprint(queue <int> q){
	queue <int> check;
	int a;
	while (!q.empty())	{

		cout << q.front() << ' ';
		a = q.front();
		check.push(a);
		q.pop();
	}
	return check;
}

//вывод в файл. очереди теряем
void print(queue <int> q){

	while (!q.empty())
	{
		out << q.front() << ' ';
		q.pop();
	}
}

// проверка на простое
int prost(int a){

	for (int i = 2; i <= (a / i); i++)
		if (!(a%i)) return 0;
	return 1;
}

//проверка на палиндром
int palindrom(char *s){

	for (int i = 0; i<strlen(s) / 2; i++)
		if (s[i] != s[strlen(s) - i - 1]) return 0;
	return 1;
}

int main(){

	queue <int> q3, q1, q2;
	priority_queue <int> q;

	setlocale(0, "rus");

	ifstream in; in.open("input.txt");
	out.open("output.txt");

	int a;
	char s[1000];

	while (!in.eof()){

		in >> a;
		_itoa(a, s, 10);
		if (prost(a))  q1.push(a);
		if (palindrom(s)) q2.push(a);

		if (prost(a) || palindrom(s)) q.push(a);
	}
	if (!q.empty()){

		a = q.top();
		q.pop();
	}

	while (!q.empty())	{

		if (a != q.top()) q3.push(a);
		a = q.top();
		q.pop();
	}

	q3.push(a);

	cout << "Очередь 1 (Простые): ";
	q1 = cprint(q1);
	cout << '\n' << "Очередь 2 (Палиндромы): ";
	q2 = cprint(q2);
	cout << '\n' << "Очередь 3 (Вхождения): ";
	q3 = cprint(q3);
	cout << endl;
	
	out << "Очередь 1 (Простые): ";
	print(q1);
	out << '\n' << "Очередь 2 (Палиндромы): ";
	print(q2);
	out << '\n' << "Очередь 3 (Вхождения): ";
	print(q3);

	system("pause");
	return 0;
}

