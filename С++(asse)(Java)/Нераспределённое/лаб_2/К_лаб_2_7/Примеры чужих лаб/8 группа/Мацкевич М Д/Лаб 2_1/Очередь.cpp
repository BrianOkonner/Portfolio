/*�������� ������ �� 8
2.1	����� ��������� ���� Input.txt, � ������� ���� ��������� �����,
������ ����� � ��������� ������. �������  ��� �������,
� ������ � ������� �����, �� ������ _ ����������.
��������� ����� �������, ������� � ��� �� ������  ���� ��������,
������� ������ ���� �� � ���� �� �������� Queue1 ��� Queue2.
��������� �������� � ���������  ����.

�������
1)�������� 4 ������� (��������������� �������(q3) ����� ������������� ������������� �� �����������)
2)�������� �� ����� �����, ����� ���������� �� � ������� 1 � (���) 2
���� ��� ������������ ����������� ������  (������� � ����������)
3) ��������������� ������� ���- ����������� 2-� ����� ��������.
4)��� ��������� ������� ������� ��������� �� ����������� ���� �������� ��������� 
�� ��������������� �������(�.�. �����. ������� ������������� ��  �����������) 

���� � ����� ����� �����

                      �����
����:
3 45 123321 56 11 10 41 100 53 11
�����:
������� 1
3 11 41 53 11
������� 2
3 123321 11 11
������� 3
123321 53 41 11 3
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
ofstream out;

void print(queue <int> q);	
bool prost(int x);
bool palindrom(char *s);
int main()
{
	queue <int> q3, q1, q2;
    priority_queue <int> q;
	setlocale(LC_ALL, "rus");
	ifstream in; in.open("input.txt");	
	 out.open("output.txt");
	int a;
	char s[20];
	while (!in.eof())
	{
		in >> a;
		itoa(a, s, 10);
		if (prost(a))  q1.push(a);
		if (palindrom(s)) q2.push(a);

      if (prost(a) || palindrom(s)) q.push(a);
	}
if (!q.empty()) 
	{a=q.top();
     q.pop(); }

while (!q.empty())
 {
	if (a!=q.top()) q3.push(a);
    a=q.top();
    q.pop();
 }
q3.push(a);

	out << "������� 1\n"; print(q1);
	out <<'\n'<< "������� 2\n"; print(q2);
	out <<'\n'<< "������� 3\n"; print(q3);
	out.close();
	in.close();
	system("pause");
	return 0;
}

bool prost(int a)
{for (int i=2; i<=(a/i); i++)
if (!(a%i)) return 0;
return 1;
}

bool palindrom(char *s)
{
	for (int i = 0; i<strlen(s) / 2; i++)
		if (s[i] != s[strlen(s) - i - 1]) return 0;
	return 1;
}

void print(queue <int> q)		//������ ����������� 
{
	while (!q.empty())
	{
		out <<q.front()<<' ';
		q.pop();		
	}
}