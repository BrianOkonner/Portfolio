	/*											������ �B9
		��������� ������� ��������� ������������ ������������.( �������������: ���������� ������������. ������ 8)
		������� :������ �����, ���������� �� ���� �� ������ ����. ����� ������ ����� �������� ����, �������� 9.
		������� �������� :������� ������ ����� ��������� �� 2-9 ���� ������� ����� ��������. ����� ��������� ��� ��
	������������ (������������� �� ��� �������, ���� ��� ������������� ���������).����� ��������� ���� � ������� ������ ��� ���������
	����� �� � ����� �������� ����� ���� ������� �� 10 ����� �� 1000 ��.�.����� ���� ���� ��������� ������� �� ������� ������� �� 10 
	����� �� 1000 ��.�. ����� ������� �� 10 � ��������� 9 � ����� ������� ������� �� 10 ����� �� 1000 ��.� � ��������� ������� ��������
	����� � �������� � ��� ���� �������� ������� ��� ���������� ������ � ����� ������� �������� � ���������� �����.
	����� :	*/
#include <iostream>
using namespace std;
int main()
{
	int n,g,a=0,c,k=0,i,o,j;
	setlocale(LC_ALL,".1251");
	cout<<"������� ����� ��������� �� 2-9 ����: ";	//���� � ������� "��" ���������� ��� ������� ��� �����
	cin>>n;
	_asm
	{
		mov i,10
		mov j,100
		mov c,10;
		mov ecx, 8
		mov eax, n; in eax n
		m1:	cdq
			idiv c; v a ostatki v k  chustnoe
			mov k, eax
			mov a, edx
			imul i
			add eax, 9
			imul c
			add edx, a
			mov o, eax
			mov eax, c
			imul j
			mov c, eax
			mov eax,o
			loop m1
			//k=o/c;
			/*a=o%c;
			g=(k*10)+9;
			o=(g*c)+a;
			c=c*100;*/
		

	}
	cout<<o;;
	system("pause");
	return 0;
}
/*		idiv c
m1:
		cmp ebx,0
		jne m2*/
		
