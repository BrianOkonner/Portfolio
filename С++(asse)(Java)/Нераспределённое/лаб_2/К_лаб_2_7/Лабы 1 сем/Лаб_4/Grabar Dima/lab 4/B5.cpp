//5.	������ ������������� ������������������ A=(ai), i=1..n, n<=100.
//������� ������ ������ ������ ������ ���������� ���������, 
//� ������ ����� � ���������� ���� ��������� (����� ����� ����� ���� ����� 1).
//������� ������, ���������� ����� ���� ����� ��������� �������.

//���� ���������:
//1) ������� � ������ ������.
//2) ������ ������ ������� � ���������� ��� �� ���������, ���� �������� �����, ������� ������������� �� 1,
//���� ���, ������� ������������ �� 1.

#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a[30];
	int lenghth, max = 0, count = 0;
	cout << "������� ����� ������" << endl;
	cin >> lenghth;  // ������ ����� ������� A
	cout << "������� �������� ������� ������" << endl;
	for (int i = 0; i<lenghth; i++) // � ������ ��� �������
		cin >> a[i];
	cout << endl;
	cout << "���� ������" << endl;
	for (int i = 0; i<lenghth; i++) // � ������ ��� �������
		cout << a[i] << " ";
	cout << endl;
	cout << "����� �����:" << endl;
	count = 1;
	for (int i = 0; i < lenghth - 1; i++)
	{
		if (a[i] < a[i + 1])
			count++;

		if (count > max)
			max = count;

		if (a[i] >= a[i + 1])
		{
			cout << count << endl;
			count = 1;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}