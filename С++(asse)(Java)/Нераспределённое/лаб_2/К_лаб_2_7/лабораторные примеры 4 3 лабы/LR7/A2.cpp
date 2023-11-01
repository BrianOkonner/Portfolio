/*
�������� �����
1 ���� 8 ������

������� : 
����� ��������� ���� Input.txt, � ������� ���� ��������� �����, ������ ����� � ��������� ������. 
�������  ��� �������,  � ������ � ������� �����, �� ������ - ����������. 
��������� ����� �������, ������� � ��� �� ������  ���� ��������, ������� ������ ���� �� � ���� �� �������� Queue1 ��� Queue2.
��������� �������� � ���������  ����.

������:

����:
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

�����:

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
#include "functions_A2.h"
using namespace std;

int main(void)
{
	queue *simple_numbers = new queue;
	queue *palindrome_numbers = new queue;
	queue *numbers = new queue;
	simple_numbers->head = NULL;
	simple_numbers->tail = NULL;
	palindrome_numbers->head = NULL;
	palindrome_numbers->tail = NULL;
	numbers->head = NULL;
	numbers->tail = NULL;
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
			push(simple_numbers,numb);
		}
		if(is_palindrome(numb))
		{
			push(palindrome_numbers, numb);
		}
	}
	while (simple_numbers->tail)
	{
		temp_number = pop(simple_numbers);
		if (!queue_search(numbers, temp_number))
			push(numbers, temp_number);
	}
	while (palindrome_numbers->tail)
	{
		temp_number = pop(palindrome_numbers);
		if (!queue_search(numbers, temp_number))
			push(numbers, temp_number);
	}
	out << "Final queue : " << endl;
	while (numbers->tail)
	{
		out << pop(numbers) << endl;
	}
	clk = clock();
	out << endl << "Vremya vipolneniya: " << clk / 1000.0 << endl;

	return 0;
}

