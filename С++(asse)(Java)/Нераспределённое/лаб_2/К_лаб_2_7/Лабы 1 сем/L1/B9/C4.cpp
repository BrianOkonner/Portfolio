	/*													������ ��4
		��������� ������� ��������� ������������ ������������.( �������������: ���������� ������������. ������ 8)
		������� :������  ����������� �����  n. �����  ������ ������ ��������� ����� � ����� n!.. 
		������� ��������: ������ ����� n.����������� ���������� �������� �����.����� ��������� ��������� �� ����� ��������� ����(
	�������� �� 1 ����� 2 ...n-1).����� ����� ���� ���� �� ����� ����������� ���� ����� �� ���� ������� � ����� ��������� ����� ����
	�� 10 ����� ������� ���� ��������� ������� � �������.
		����� :
		�������        �����
		8              40320   2
		5			   120     2
		7              5040    4
		20             2432902008176640000   4*/
		
#include <iostream>
using namespace std;
void main()
{
	_int64 n,p,l;
	setlocale(LC_ALL,".1251");
	cout<<"������� ����� n: ";
	cin>>n;
	l=n;
	for(p=1;p!=n;p++)
	l=l*p;
	cout<<"����� n! ="<<l<<"\n";
	while(l%10==0)
	l=l/10;
	l%=10;
	cout<<"������ ��������� ����� � ����� n! =";
	cout<<l<<"\n";
	system("pause");
}