/*17 ������� ����
�������� � ������ ��������� ���� ������������ ����
������������� ���� � ����� ������ ������ � ��������� ��� �������� �� ����� �� ��� ��������
��������� �� ����� �������� � ����������� ������� � �������*/
#include "List.h" /*��� ����*/
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	Stack a,b;
	queue <int> ans;
	int t,f=0; bool re = 0;
	while (!fin.eof())
	{
		fin >> t;
		a.push_back(t);
	}
	while (a.size)
	{
		t = a.remove_tail();
		if (!re && t % 2 == 0)
		{
			re = 1;
			f = t;
		}
		b.push_back(t);
	}
	while (b.size)
	{
		t = b.remove_tail() + f;
		a.push_back(t);
	}
	while (a.size)
	{
		ans.push(a.remove_tail());
	}
	while (ans.size())
	{
		fout << ans.front() << ' ';
		ans.pop();
	}
	system("pause");
}