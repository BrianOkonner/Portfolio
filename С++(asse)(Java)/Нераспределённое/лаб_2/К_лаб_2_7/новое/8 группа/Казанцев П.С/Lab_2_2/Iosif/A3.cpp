/*
�������� �����
1 ���� 8 ������

������� :	������ ������. ������ ���������� ����� N �������, �� ������� ������� ������, 
�  ���������  ������������  ��  ������� ������� ������� �� 2 �� N. ���������,  ������� � ����-��, 
����� ���� �� M. �������, �� ������� ����������� ����, ������� �� �����. ���� ������������ �� ���������� ��������
� ��� �� ��� ���, ���� �� ��������� ���� �������.  ���������� ����� ����������� ��������, ���� �������� M � ��, 
��� ���� ��������� � ������� ��������. 
��������� �������� � ���������  ����.

������:

����:
10 4
�����
Last Man Standing : 5

Vremya vipolneniya: 0.041
*/


#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <locale>
#include "functions_A3.h"
#include <Windows.h>
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "ru");
	unsigned int clk;
	
	ifstream in;
	ofstream out;
	int N=0, M=0;
	in.open("input_a3.txt");
	out.open("output_a3.txt");
	in >> N >> M;
	
	if (N < 2 || M < 1)
	{
		cout << "Incorrect input !" << endl;
		return 0;
	}
	MyList start(N);
	cout << "Last Man Standing : " << start.iosif_task(N, M) << endl;
	clk = clock();
	cout << endl << "Vremya vipolneniya: " << clk / 1000.0 << endl;
	system("pause");
	return 0;
}

