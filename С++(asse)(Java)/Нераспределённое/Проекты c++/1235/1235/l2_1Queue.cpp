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
5+
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
#include "MineQueue.h"
#include "fun_h.h"
using namespace std;
void main()
{
	ifstream inq("Input.txt");
	ofstream outq("Queue.txt");
	Mqueue pr,pal;
//	queue <int> pr,pal;
	setlocale(LC_ALL,".1251");
	int buf,i=0;
	while(inq>>buf&&!inq.eof())		i+=2;
	int *j=new int (i);
	inq.clear();
	inq.seekg(inq.beg);
	i=0;
	while(inq>>buf&&!inq.eof())
	{
		if(Prime(buf))
		{
			j[i]=buf;
			pr.push(&j[i]);
			i++;
		}
		if(palindrom(buf))
		{
			j[i]=buf;
			pal.push(&j[i]);
			i++;
		}
	}
//	queue <int> res(pr);
	i=*(int*)pr.back();
	outq<<"	������� � �������� �������:"<<endl;
	while(i!=*(int*)pr.front())
	{
		outq<<*(int*)pr.front()<<" ";
		int *m=new int;
		*m=*(int*)pr.front();
		pr.pop();
		pr.push(m);
	}
	outq<<*(int*)pr.front()<<" ";
	outq<<endl;
	outq<<"	������� � �������-������������:"<<endl;
	i=*(int*)pal.back();
	while(i!=*(int*)pal.front())
	{
		outq<<*(int*)pal.front()<<" ";
		int *m=new int;
		*m=*(int*)pal.front();
		pal.pop();
		pal.push(m);
	}
	outq<<*(int*)pal.front()<<" ";
	outq<<endl;
	i=*(int*)pal.back();//���� ���� ��������� ������� �������� ����� ����:queue <int> res(pr);
	Mqueue res(pr);
	while(i!=*(int*)pal.front())
	{
		int bf=0;
		for(buf=res.size();buf!=0;buf--)
		{
			if((*(int*)res.front())!=(*(int*)pal.front()))
			{
				int *m=new int;
				*m=*(int*)res.front();
				res.pop();
				res.push(m);
			}
			else
			{
				int *m=new int;
				*m=*(int*)pal.front();
				pal.pop();
				pal.push(m);
				bf=-1;
				break;
			}
		}
		if(bf!=-1)
			res.push(pal.front());
		int *m=new int;
		*m=*(int*)pal.front();
		pal.pop();
		pal.push(m);
	}
	outq<<"	3-� ������� � ������� �������� � ������������:"<<endl;
	i=*(int*)res.back();
	while(i!=*(int*)res.front())
	{
		int *m=new int;
		outq<<*(int*)res.front()<<" ";
		*m=*(int*)res.front();
		res.pop();
		res.push(m);
	}
}
//push  front pop back size
