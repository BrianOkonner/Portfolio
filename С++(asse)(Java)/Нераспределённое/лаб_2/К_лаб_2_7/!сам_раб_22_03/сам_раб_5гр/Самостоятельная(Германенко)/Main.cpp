/*���������� ���� 
�������: 4. � ����� input.txt ����� ����� ����� �����.
            �������� �� � ������ ��������� ���� ����_������.  
            ������������ �� �����, ������� ���� �� ���, ���� ��� ����������.
			P�������� �������� � ����������� ������ � ������� � ���� Output.txt*/

#include<iostream>
#include"Header.h"
#include<List>
#include<fstream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	list <int> C;
	my_stack A,B;
	ofstream out;
	ifstream in;
	int max, tmp, a, b;

	in.open("Input.txt");
	out.open("Output.txt");
	cout << "���� �� ���������: ";
	while (!in.eof())
	{
	    in >> tmp;
		A.push(tmp);
		cout << tmp << " ";
	}
	
	a = A.top();
	A.pop();
	b = A.top();
	A.pop();
	B.push(a);

	cout << endl << "���� ����� ���������: ";

    while (!A.empty())
	{
		if (a != b)
			B.push(b);
		a = b;
		b = A.top();
		A.pop();
	}
	while (!B.empty())
	{
		tmp=B.top();
		B.pop();
		C.push_front(tmp);
		cout << tmp << " ";
	}
	out << "�������� � ����������� ������: ";
	cout << endl << "�������� � ����������� ������: ";
	while (!C.empty())
	{
		tmp = C.back();
		C.pop_back();
		out << tmp << " ";
		cout << tmp << " ";
    }
	cout << endl;
	in.close();
	out.close();
	system("pause");
}