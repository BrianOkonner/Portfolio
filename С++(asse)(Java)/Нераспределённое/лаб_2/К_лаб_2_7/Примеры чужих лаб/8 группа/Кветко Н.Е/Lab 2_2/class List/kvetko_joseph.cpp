/*
������ ������, 8-� ������. ������������ ������ 2. 
������ ������ ������.
� ������� ������������� ������ ������ "������" ������ ������ ������ ������
����:
������� ���������� ����������: 10
������� ���: 20
�������� ����� ����� 10
�������� ����� ����� 2
�������� ����� ����� 6
�������� ����� ����� 4
�������� ����� ����� 7
�������� ����� ����� 5
�������� ����� ����� 3
�������� ����� ����� 9
�������� ����� ����� 8

����������: 1
*/
#include <iostream>
#include "List.h"
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	list joseph;
	int N, kill, step = 0;
	cout << "������� ���������� ����������: "; cin >> N;
	cout << "������� ���: "; cin >> kill;
	for (int i = 0; i < N; ++i, joseph.push_back(i));
	while (joseph.size() > 1) {
		step++;
		if (step == kill) {
			cout << "�������� ����� ����� " << joseph.front() << endl;
			joseph.pop_front();
			step = 0;
			continue;
		}
		joseph.push_back(joseph.front());
		joseph.pop_front();
	}
	cout << "\n����������: " << joseph.front() << endl;
	
	system("pause");

}