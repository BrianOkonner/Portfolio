#include <iostream>
#include <fstream>
#include <list>
/*
������� ������� 8 ������

������ ������:  ������ ���������� ����� N �������, �� ������� ������� ������, �  ���������  ������������  ��  ������� �������
������� �� 2 �� N. ���������, ������� � ����-��, ����� ���� �� M. �������, �� ������� ����������� ����, ������� �� �����. ����
������������ �� ���������� �������� � ��� �� ��� ���, ���� �� ��������� ���� �������.  ���������� ����� ����������� ��������,
���� �������� M � ��, ��� ���� ��������� � ������� ��������. ��������� �������� � ���������  ����.
*/

using namespace std;

void main(){

	setlocale(0, "rus");

	ofstream out;
	out.open("output.txt");

	int n, m, i, j, el;

	cout << "K���������: ";
	cin >> n;
	out << "K���������: " << n << endl;
	cout << "���: ";
	cin	>> m;
	out << "���: " << m << endl;

	if (m == 1){	//����� ��������� ��� m=1;
		cout << "��������� ������� "<< n << endl;
		out << "��������� ������� " << n;
	}

	else {

		list <int> lists;
		for (i = 1; i <= n; i++) lists.push_front(i);


		for (i = 1; i < n; i++) {

			for (j = 1; j < m; j++) {
				el = lists.back();
				lists.pop_back();
				lists.push_front(el);
			}
			lists.pop_back();
		}

		cout << "��������� ����� " << lists.front() << endl << "*��������� � output.txt"<< endl;
		out << "��������� ����� " << lists.front();
	}
	out.close();
	system("pause");
}