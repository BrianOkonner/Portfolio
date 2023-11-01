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


#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <locale>
#include "Header.h"
using namespace std;

int main(void)
{
	MyQueue simple_numbers;
	MyQueue palindrome_numbers;
	MyQueue numbers;
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
	//cout << "Simple numbers:" << endl;
	while (!simple_numbers.isEmpty())
	{
		temp_number = simple_numbers.front(); 
		simple_numbers.pop();
		//cout << temp_number << " ";
		if (!numbers.queue_search(temp_number))
			numbers.push(temp_number);
	}
	//cout << "Simple numbers:" << endl;
	while (!palindrome_numbers.isEmpty())
	{
		temp_number = palindrome_numbers.front();
			palindrome_numbers.pop();
		if (!numbers.queue_search(temp_number))
			numbers.push(temp_number);
	}
	out << "Final queue : " << endl;
	while (!numbers.isEmpty())
	{
		out << numbers.front() << endl;
		numbers.pop();
	}
	clk = clock();
	out << endl << "Vremya vipolneniya: " << clk / 1000.0 << endl;

	return 0;
}

