/*
Казанцев Павел
1 курс 8 группа

Условие :
Задан текстовый файл Input.txt, в котором есть некоторые числа, каждое число в отдельной строке.
Создать  две очереди,  в первой – простые числа, во второй - палиндромы.
Построить новую очередь, включив в нее по одному  разу элементы, которые входят хотя бы в одну из очередей Queue1 или Queue2.
Результат записать в текстовый  файл.

Пример:

Ввод:
123123
1331
1251
424
7
5
121
111
113
13
11
123321
11
123321

Вывод:

Final queue :
7
5
113
13
11
1331
424
121
111
123321

Vremya vipolneniya: 0.044

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <locale>
#include "functions_A2.h"
using namespace std;

int main(void)
{
	queue <int> simple_numbers ;
	queue <int> palindrome_numbers;
	queue <int> numbers ;
	int temp_number;
	setlocale(LC_ALL, "ru");
	unsigned int clk;
	int numb;
	ifstream in;
	ofstream out;
	in.open("input_a2.txt");
	out.open("output_a2.txt");
	while (!in.eof())
	{
		in >> numb;
		if (is_simple(numb))
		{
			simple_numbers.push(numb);
		}
		if (is_palindrome(numb))
		{
			palindrome_numbers.push(numb);
		}
	}
	while (simple_numbers.size()!=1)
	{
		temp_number = simple_numbers.front();
		simple_numbers.pop();
		int f = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers.front() == temp_number)
				f = 1;
			numbers.push(numbers.front());
			numbers.pop();
		}
		if (!f)
			numbers.push(temp_number);
	}
	while (palindrome_numbers.size() != 1)
	{
		temp_number = palindrome_numbers.front();
		palindrome_numbers.pop();
		int f = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers.front() == temp_number)
				f = 1;
			numbers.push(numbers.front());
			numbers.pop();
		}
		if (!f)
			numbers.push(temp_number);
	}
	out << "Final queue : " << endl;
	while (numbers.size()!=0)
	{
		out << numbers.front() << endl;
		numbers.pop();
	}
	clk = clock();
	out << endl << "Vremya vipolneniya: " << clk / 1000.0 << endl;

	return 0;
}
