/*
������ ������ 8-� ������. 
������� ������ ������ ������ � �������������� STL ������
*/
#include <iostream>
#include <list>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	list <int> joseph;
	int n, kill, count = 0;
	cout << "������� ���������� ����������: "; cin >> n;
	cout << "������� �����: "; cin >> kill;
	for (int i = 0; i < n; joseph.push_back(++i));
	while (joseph.size() > 1)
	{
		count++;
		if (count == kill) {
			cout << "�������� �������� " << joseph.front() << endl;
			joseph.pop_front();
			count = 0;
		}
		else {
			joseph.push_back(joseph.front());
			joseph.pop_front();
		}
	}
	cout << "�������� ��� ������� " << joseph.front() << " ���������.\n";
	system("pause");
}