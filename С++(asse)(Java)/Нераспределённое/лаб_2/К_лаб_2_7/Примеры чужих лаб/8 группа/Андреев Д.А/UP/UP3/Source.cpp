/*
��� A=(ai) ,  i=1..n,  (n<=10), ������  � ����� b. �����������  �����  � ������� 
�����  �������, ����� ������� ���  ��������,  ������� ��� ������ b, � ���� ����� ������� b.
*/

#include <iostream>
using namespace std;
extern "C" int* MAS_FUNC(int *, int *, int, int);

int main()
{
	setlocale(0, "rus");

	int *a, b, i, n, *k;
	cout << "������� ������ �������: ";
	cin >> n;
	cout << "������� b: ";
	cin >> b;
	
	a = new int[n];
	cout << "������� �������� �������: ";

	for (i = 0; i<n; i++) cin >> a[i];
	
	for (i = 0; i<n; i++) cout << a[i];
	k = new int[n];
	//����� � �����������
	k = MAS_FUNC(a, k, n, b);



	for (i = 0; i<n; i++) cout << *(k + i) << ' ';

	system("pause");
	return 0;
}



