/*													Lab2_1 Queue
	��������� ������� ��������� ������������ ������������.( �������������: ���������� ������������. ������ 8)
	������� :2.	 ������������� (������������) �������.
2.1	����� ��������� ���� Input.txt, � ������� ���� ��������� �����, ������ ����� � ��������� ������. �������  ��� �������, 
� ������ � ������� �����, �� ������ _ ����������. ��������� ����� �������, ������� � ��� �� ������  ���� ��������, ������� ������ 
���� �� � ���� �� �������� Queue1 ��� Queue2. ��������� �������� � ���������  ����. 
	�������� :���������� �� ����� � ������� ������� ����������� � ������� ���������.�������� � 3-� ������� ���� �� ���. ��������� 3-� 
� ������� �������� �� �������������.
	�����:
 Input.txt :
5
3
623
43645
35
12321
4654
76
67
8
1
11
131
141
152
64
245
66523
2
 ���� Stack�1.txt:
	������� � �������� �������:
5 3 67 1 11 131 66523 
	������� � �������-������������:
5 3 12321 8 1 11 131 141 
	3-� ������� � ������� �������� � ������������:
131 66523 2 5 12321 8 3 67 1 */
#include <iostream>
#include <fstream>
#include <queue>
#include "fun_h.h"
using namespace std;
void main()
{
	ifstream inq("Input.txt");
	ofstream outq("Queue.txt");
	queue <int> pr,pal;
	setlocale(LC_ALL,".1251");
	int buf,i,m;
	while(inq>>buf&&!inq.eof())
	{
		if(Prime(buf))
			pr.push(buf);
		if(palindrom(buf))
			pal.push(buf);
	}
	queue <int> res(pr);
	i=pr.back();
	outq<<"	������� � �������� �������:"<<endl;
	while(i!=pr.front())
	{
		outq<<pr.front()<<" ";
		m=pr.front();
		pr.pop();
		pr.push(m);
	}
	outq<<pr.front()<<" ";
	outq<<endl;
	outq<<"	������� � �������-������������:"<<endl;
	i=pal.back();
	while(i!=pal.front())
	{
		outq<<pal.front()<<" ";
		m=pal.front();
		pal.pop();
		pal.push(m);
	}
	outq<<pal.front()<<" ";
	outq<<endl;
	i=pal.back();//���� ���� ��������� ������� �������� ����� ����:queue <int> res(pr);
	while(i!=pal.front())
	{
		for(buf=res.size();buf!=0;buf--)
		{
			if(res.front()==pal.front())
			{
				m=pal.front();
				pal.pop();
				pal.push(m);
				m=-1;
				break;
			}
			else
			{
				m=res.front();
				res.pop();
				res.push(m);
			}
		}
		if(m!=-1)
			res.push(pal.front());
		m=pal.front();
		pal.pop();
		pal.push(m);
	}
	outq<<"	3-� ������� � ������� �������� � ������������:"<<endl;
	i=res.back();
	while(i!=res.front())
	{
		outq<<res.front()<<" ";
		m=res.front();
		res.pop();
		res.push(m);
	}
}

