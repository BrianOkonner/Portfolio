/*
�������� ����� ���������
1 ����
������ ��-8

�������: ���������, �������� �� �������� ����� � � � ��������������.

�������     �����
220 284     ����� �������� ��������������
1184 1210   ����� �������� ��������������
2620 2924   ����� �������� ��������������
6 123       ����� �� �������� ��������������
9 7         ����� �� �������� ��������������
81 28       ����� �� �������� ��������������
*/

#include <iostream>
using namespace std;

int main()
{
	int a, b, s1 = 0, s2 = 0, flag = 0, d2 = 2;
	setlocale(LC_ALL, ".1251");
	cout << "������� ����������� ����� a u b" << endl;
	cin >> a >> b;
	_asm
	{
		mov eax, a
		mov edx, 0
		idiv d2
		mov ecx, eax
	l1:	mov eax,a
		mov edx,0
		idiv ecx
		cmp edx,0
		jne m1
		add s1, ecx
	m1: loop l1

		mov eax, b
		mov edx, 0
		idiv d2
		mov ecx, eax
	l2 : mov eax, b
		 mov edx, 0
		 idiv ecx
		 cmp edx, 0
		 jne m2
		 add s2, ecx
	m2: loop l2

		mov eax, s1
		cmp eax, b
		jnz end1
		mov eax, s2
		cmp eax, a
		jnz end1
		mov flag, 1
	end1:
	}

	if (flag)//�������� �� ���������������
		cout << "����� �������� ��������������" << endl;
	else
		cout << "����� �� �������� ��������������" << endl;
	return 0;
}
