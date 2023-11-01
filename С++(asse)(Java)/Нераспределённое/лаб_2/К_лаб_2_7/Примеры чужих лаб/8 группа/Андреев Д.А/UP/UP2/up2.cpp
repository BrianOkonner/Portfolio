//s += sin(n*x)*(pow(x, 2 * n + 1)) / (2 * n + 1);
//n = 5, 6, 7... m


#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "funcs.h"

using namespace std;



void main() {

	setlocale(0, "rus");

	ofstream out;
	out.open("output.txt");

	int m;
	double x, h, a, b, s, s1 = 0, s2 = 0;

	cout << "��������� �������� x: "; cin >> a;
	cout << "�������� �������� x: "; cin >> b;
	cout << "��� ��������� x: "; cin >> h;
	cout << "���������� ���������: "; cin >> m;

	out << "��������� �������� x: " << a << endl;
	out << "�������� �������� x: " << b << endl;
	out << "��� ��������� x: " << h << endl;
	out << "���������� ���������: " << m << endl << endl << endl;

	//������ ����� �������...

	//...� �������
	cout.fill('=');
	cout << setw(78) << " " << endl;
	cout.fill(' ');
	cout << "|" << setw(12) << "�������� x |" << setw(17) << "����� ���� |" << setw(25) << "C���������� ����� C |" << setw(17) << "C���������� ����� asm|" << endl;
	cout.fill('=');
	cout << setw(78) << " " << endl;
	cout.fill(' ');
	//...� �����
	out.fill('=');
	out << setw(78) << " " << endl;
	out.fill(' ');
	out << "|" << setw(12) << "�������� x |" << setw(17) << "����� ���� |" << setw(25) << "C���������� ����� C |" << setw(17) << "C���������� ����� asm|" << endl;
	out.fill('=');
	out << setw(78) << " " << endl;
	out.fill(' ');


	//��������� �, �������� �������� ����� � ����� �� �������� � ��������
	if (a < b) {

		for (x = a; x <= b; x += h) {
			s = schet(x, m);
			s1 = schet1(x, m);
			s2 = schet2(x, m);
			//������������ �������
			cout << "|" << setw(10) << x << " |" << setw(15) << s << " |" << setw(23) << s1 << " |"  << setw(20) << s2 << " |" << endl;;
			cout.fill('=');
			cout << setw(78) << " " << endl;
			cout.fill(' ');

			out << "|" << setw(10) << x << " |" << setw(15) << s << " |" << setw(23) << s2 << " |" << setw(20) << s1 << " |" << endl;
			out.fill('=');
			out << setw(78) << " " << endl;
			out.fill(' ');
		}

	}
	//��������� � �������� �������� ����� � ����� �� �������� � ��������
	else if (a >= b) {

		for (x = a; x >= b; x -= h) {
			s = schet(x, m);
			s1 = schet1(x, m);
			s2 = schet2(x, m);
			//������������ �������
			cout << "|" << setw(10) << x << " |" << setw(15) << s << " |" << setw(23) << s1 << " |" << setw(20) << s2 << " |" << endl;;
			cout.fill('=');
			cout << setw(78) << " " << endl;
			cout.fill(' ');

			out << "|" << setw(10) << x << " |" << setw(15) << s << " |" << setw(23) << s2 << " |" << setw(20) << s1 << " |" << endl;
			out.fill('=');
			out << setw(78) << " " << endl;
			out.fill(' ');
		}

	}

	cout << "* ��������� � output.txt" << endl;

	system("pause");

}