/*
������ ������
1 ����
8 ������

�������: ������ ���������� ����� N �������, �� ������� ������� ������, � ��������� ������������ �� ������� �������
������� �� 2 �� N. ���������, ������� � ���� - ��, ����� ���� �� M. �������, �� ������� ����������� ����, �������.
���� ������������ �� ���������� ��������, � ��� �� ��� ���, ���� �� ��������� 1 �������. ���������� ����� ����������� ��������,
���� �������� M �  ��, ��� ���� ���������� � ������� ��������. ��������� �������� � ��������� ����

�����: 4-5-2
10-9-7

*/

#include<iostream>
#include<fstream>
#include<list>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".1251");
    ofstream fout;
    fout.open("rez.txt");
int n,m;
list <int> l;
 cin >> n >> m;
for(int i=1; i<=n; i++)
    l.push_back(i);
while(n!=1)
{
    for(int i=1; i<m; i++)
    {
        l.push_back(l.front());
        l.pop_front();
    }
    l.pop_front();
    n--;
}
fout << "vyzil " << l.front();
}
