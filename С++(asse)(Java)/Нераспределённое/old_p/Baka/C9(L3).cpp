/*	���� ������������������ U=(ai) ,  i=1..n, (n,<=30).�����  �����.�����  ������������ �����
�� ������������ ���������������������(����� �������� ������� n*log(n)).*/
#include <iostream>
#include <iomanip>
#include "fun_h.h"
using namespace std;
void main()
{
	int a[31],**p,n,i,m=25,l=0,j,h,o;
	p = new int*[31];   //�������� �����
	for (int i =0 ;i<31; i++)
	{
		p[i] = new int[31];  //�������� ������� ��� ������ ������
	}
	cout<<"������� n (n<=100): ";
	cin>>n;
	setlocale(LC_ALL,".1251");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)//����� �������� �������� ��� ������ L3(B9)
			cout<<p[i][j]<<" ";
		cout<<endl;
	}
	//h=BinarySearch_L3nomatr (a,n,m);
	system("pause");
}
