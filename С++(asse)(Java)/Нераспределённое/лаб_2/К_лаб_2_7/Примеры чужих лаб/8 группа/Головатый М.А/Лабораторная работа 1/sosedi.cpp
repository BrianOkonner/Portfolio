/*
��������� �������������� �������� ����� � ������� �������� :
�������
1)������� ����� �� ����� � ����.
2)����� ������� �� ����� ,������ ����� ���������� � ���������� �1,�2
�������� 2-� ���������� ��������� �����.
3)����� ���������� � �����  �������� �������� �������� ����� �
��������������  (n � n-2) ,� ��� ���������� �����������  ����� ������� �� 1
�����
input.txt : 12 3 14 87178  3 1221 18 715 19 194 71 5 13 5 91 9 5 7 5
***********������� ���������, ������� ������������ ���������� ��������� �����, � ������� ������ "������"***********
�������� ������������������ ��������� � ����� input.txt. ��������� ��������� � ������� ��������: 2
*/
#include "header.h"
#include <stack>


void sosedi()
{
	int a, a1, a2,i=1,k=0;
	ifstream in; in.open("input.txt");
	stack <int> s;
	while (!in.eof())
	{
		in >> a;
		s.push(a);
	}
	a1 = s.top();
	s.pop();
	a2 = s.top();
	s.pop();

	while (!s.empty())
	{
		if (i % 2)
		{
			if (s.top() == a1) k++;
			a1 = s.top();
		}
		else
		{
			if (s.top() == a2) k++;
			a2 = s.top();
		}
		s.pop();
		i++;
	}



	cout << k << '\n';
}