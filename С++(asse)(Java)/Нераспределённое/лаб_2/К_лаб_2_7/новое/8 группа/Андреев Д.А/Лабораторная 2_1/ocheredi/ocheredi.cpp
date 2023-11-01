/*
������� ������� 8 ������ 

������������ 2_1

����� ��������� ���� Input.txt, � ������� ���� ��������� �����,
������ ����� � ��������� ������. �������  ��� �������,
� ������ � ������� �����, �� ������ _ ����������.
��������� ����� �������, ������� � ��� �� ������  ���� ��������,
������� ������ ���� �� � ���� �� �������� Queue1 ��� Queue2.
��������� �������� � ���������  ����.
������������ ����������� �������.

������ �� ����� �����, ���������� � ������� 1 � (���) 2, ���� ��� ��������\
� ������� 3 ���������� ���������� � ������ �����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
ofstream out;

//����� � ������� � ����������� ��������
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

//����� � ����. ������� ������
void print(queue <int> q){

	while (!q.empty())
	{
		out << q.front() << ' ';
		q.pop();
	}
}

// �������� �� �������
int prost(int a){

	for (int i = 2; i <= (a / i); i++)
		if (!(a%i)) return 0;
	return 1;
}

//�������� �� ���������
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

	cout << "������� 1 (�������): ";
	q1 = cprint(q1);
	cout << '\n' << "������� 2 (����������): ";
	q2 = cprint(q2);
	cout << '\n' << "������� 3 (���������): ";
	q3 = cprint(q3);
	cout << endl;
	
	out << "������� 1 (�������): ";
	print(q1);
	out << '\n' << "������� 2 (����������): ";
	print(q2);
	out << '\n' << "������� 3 (���������): ";
	print(q3);

	system("pause");
	return 0;
}

