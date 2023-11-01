/*
������ ������ 8-� ������. ������������ ������ 2.1
���������� ������������ ������ 7 � �������������� STL �������.
����:
input.txt:
313
17
313
91
2
4
19
919
101
2
output.txt:
������� �����: 313 17 313 2 19 919 101 2
����������: 313 313 2 4 919 101 2
���������: 919 313 101 19 17 4 2
*/
#include <iostream>
#include <queue>
#include <fstream>
#include "Header.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	queue <int> q1, q2;
	priority_queue <int> buffer, result;
	int tmp;
	ifstream in("input.txt");
	ofstream out("output.txt");
	while (!in.eof()) {
		in >> tmp;
		if (Prime(tmp)) q1.push(tmp);
		if (is_palindrom(tmp)) q2.push(tmp);
	}
	queue <int> prime = q1, palindroms = q2;
	while (!prime.empty())
	{
		buffer.push(prime.front());
		prime.pop();
	}
	while (!palindroms.empty())
	{
		buffer.push(palindroms.front());
		palindroms.pop();
	}
	while (buffer.size() > 1)
	{
		tmp = buffer.top();
		buffer.pop();
		if (tmp != buffer.top()) result.push(tmp);
	}
	result.push(buffer.top());

	//cout << "������� �����: ";
	out << "������� �����: ";
	while (!q1.empty()) {
		//cout << q1.front() << ' ';
		out << q1.front() << ' ';
		q1.pop();
	}
	//cout << "\n����������: ";
	out << "\n����������: ";
	while (!q2.empty()) {
		//cout << q2.front() << ' ';
		out << q2.front() << ' ';
		q2.pop();
	}
	//cout << "\n���������: ";
	out << "\n���������: ";
	while (!result.empty()) {
		//cout << result.top() << ' ';
		out << result.top() << ' ';
		result.pop();
	}
	cout << "������ �������� � ����.\n";
	system("pause");
}