/*												������ �B6
	��������� ������� ��������� ������������ ������������.( �������������: ���������� ������������. ������ 8).
	������� :�a���� ������� A=(aij) ,  i=1..n, j=1..m, (n,m<=100). ����������� �������� �������� ������ ������������ 
������� ������� ���������,  �� �����������
	������� �������� :
	����� :*/
#include <iostream>
using namespace std;
void main()
{
	int **a=0,n,m;
	setlocale(LC_ALL,".1251");
	cout<<"������� ���-�� ����� ������� :";
	cin>>n;
	cout<<"������� ���-�� �������� ������� :";
	cin>>m;
	a=matr2_dclr(a,n,m);
	input_matr2_rand2N(a,n,m);
	cout<<endl<<"��������������� ������� :"<<endl;
	bubble_srt_A4L4(a,n,m);
	vivodmatr2(a,n,m);
	system("pause");
}