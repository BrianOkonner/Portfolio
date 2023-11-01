/*
8 ������, 1 ����
��������� �.

3. ������ ������. ������ ���������� ����� N �������, �� ������� ������� ������,
�  ���������  ������������  ��  ������� ������� ������� �� 2 �� N. 
���������,  ������� � ����-��, ����� ���� �� M. �������, �� ������� ����������� ����, ������� �� �����.
���� ������������ �� ���������� �������� � ��� �� ��� ���, ���� �� ��������� ���� �������. 
���������� ����� ����������� ��������, ���� �������� M � ��, ��� ���� ��������� � ������� ��������. 
��������� �������� � ���������  ����.

�����:


*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include "List.h"
using namespace std;

void main()
{
setlocale(LC_ALL,"rus");
ofstream out;
out.open("Output.txt");
int N,M;
cout<<"���-�� ������� = "; cin>>N;
cout<<"����� �� �������� ������� ���� = "; cin>>M;

//�������� ������
List  s;
for(int i=1; i<=N; i++)
s.push_back(i);

int x;
while(!s.empty())
{ 
	for(int i=1; i<M; i++)
	{
		x = s.front();
		s.push_back(x);
		s.pop_front();
	}
	s.pop_front();
}
if( M==1 ) x = N;

cout<<"\n����� ����������� �������� = "<< x <<"\n\n";
out<<"����� ����������� �������� = "<< x <<"\n\n";
out.close();
system ("pause");
}

