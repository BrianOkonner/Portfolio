#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <time.h>
using namespace std;

int main ()
{
	srand(time(0));
	vector <int> v1 (5);
	for (int i = 0; i < v1.size (); i++)
		v1[i] = rand () % 20;
	vector <int> v2 (5);
	for (int i = 0; i < v2.size (); i++)
		v2[i] = rand () % 20;
	sort(v1.begin(),v1.end());  
	sort(v2.begin(),v2.end());
	ostream_iterator <int> iter (cout, " ");
	cout << "v1: ";
	copy (v1.begin (), v1.end (), iter);
	cout << "\nv2: ";
	copy (v2.begin (), v2.end (), iter);
	cout <<"\nset_union"<< endl;
	set_union (v1.begin (), v1.end (), v2.begin (), v2.end (), iter);
//�������� ������� ����������� ���� ��������������� ���������� � ��������� 
//result � ���������� �������� �������� ����������� ���������. ���� 
//��������� �������� ����������� ����������� � ����� �������� ����������,
//�� � ����������� ����� �������������� ���������� �� ���� ���� ���������.
	cout <<"\nset_intersection"<< endl;
	set_intersection (v1.begin (), v1.end (), v2.begin (), v2.end (), iter);
//�������� ������ � ��������� result ����������� ���� �������� ���������� �
//���������� �������� �������� ����������� ���������. ���� ���������
//�������� ����������� ����������� � ����� �������� ����������, �� � ����������� 
//����� �������������� ���������� �� ���� ���� ���������.
	cout <<"\nset_difference"<< endl;
	set_difference (v1.begin (), v1.end (), v2.begin (), v2.end (), iter);
//� �������� �������� ���������� ������ ��������, �������������� � ������ ���������,
//�� ������������� �� ������.  ������, ��� ������� ������������� ���������, �� 
//���������� � �������� ��������� ����� �������� ����� ����������� � ������ � ������ 
//��� ����, ���� ��� �������� �������������
	cout <<"\nset_symmetric_difference"<< endl;
	set_symmetric_difference (v1.begin (), v1.end (), v2.begin (), v2.end (), iter);
//�������� �������� �������� ��� ��������, �������������� ����  � ������, ���� ��
//������ ����������, �� �� � ����� ����������. ������, ��� ������� ������������� 
//��������, �� ���������� � �������� ��������� ����� �������� ����� ����������� � ������ � ������.
	cout << endl;
	return 0;
}