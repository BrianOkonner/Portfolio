	/*													������ ��9
		��������� ������� ��������� ������������ ������������.( �������������: ���������� ������������. ������ 8)
		������� :����� k-�� ����� � ���� ����, ������������ �� ������ ������ ����������� �����, ������� � 1.123456789 10 11 12 13
		�������� �������� :������ k. ����������� �������� k ����������. ���� ����� ������ ������ �������� ���.���� ��� �������� �� ���� 9
	����� 180 ����� 2700 ���� ��� �������� �� ������ ������ ��� 9 �������� �� i � �� � ��� � ������� 1 ����� 2 � �.�. � i �������
	10 ����� 100 � �.�.����� ����� ���������� ����� �� a .���������� � ����� 9 �������� �� 10 �������� 9 �������� �� 100 �������
	��� ������� ��� �� ��������.�� ����� ���� ������� �� ������� �� � ���� �� ����� 0 �� �� ������� ������� �� ������� �� 10.
	���� ��� ���������� � ����� ������� ��������� ����� ����� � ����� ����� 1 ������� �� � ���������� �������.�������� 10
	� ������� ������ ����� � ����� ����� 1 � ����� ����� �� 10 � ��� �������.����� ����� ����� ������� �� ������� �� 10 ��� ����������� 
	����� � ������� ��.
		����� :
		�������          �����
		9                9        9
		456              188      8
		656565		     127945   5
		888888888888888  6923076923076  0 
		*/
#include <iostream>
#include <cmath>
using namespace std;
void main()
{
	int a=0,q,u,b=1;
	_int64 o,k,m,i,h=0,l;//������ ���������� ��� 64 ��� ���������� � ������� ���������
	setlocale(LC_ALL,".1251");//��������� �������� ������
	cout<<"������� ����� k: ";
	cin>>k;//������ ����� k
	o=k;//����������� � �������� k
	if(o<10)//���� � ������ 10 ������ ����������� l o � ������� l
	l=o;
	{
		q=1;
		a=1;
		for(i=1;o>9*a*i;q++)//���� ��� ���� �� ����� ������� ������ ��� �� � 9*a*i � ���������� a �� 1 i � 10
		{
			o=o-(9*a*i);
			h=h+(i*9);//���������� � ����� h ������� 9 ����� 9+90 � �.�
			i=i*10;
			a++;
		}
		l=h+(o/a);//������� ����� � ������
		u=(o%a);//������� ������� ����� ����� �����
		if (u==0)//���� �� ����� ����
		{
			m=l;	
			l=l%10;//�� ������ ������ ������� �� ������� �� 10
		}	
		else
		{
			l=l+1;//���� ��� ���������� � ����� �������
			m=l;
			a=(a-u);//������� ����� � �����
			for(a=a;a!=0;a--)
			b=10*b;//�������� b � ������� a
			l=(l/b)%10;//������� ����� ���� �� b
		}
	}
		cout<<"����� � ������� "<<k<<" �� ���� 1..."<<m<<" ��� - "<<l<<"\n";//����� �����
	system("pause");
}
