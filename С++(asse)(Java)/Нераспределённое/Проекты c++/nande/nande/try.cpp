#include "iostream"
#include "List.h"
using namespace std;
double facial(int n)//��������� ���������
{
	double b=1,a;
	if (n==0)
		return 0;
	for (a=1;a<=n;a++)
	{
		_asm
		{
			finit
			fld b
			fld a
			fmul
			fst b
		}
	}
	return b;
}
double celayastep(double a,int b)//���������� ����� � ����� �������
{
	double r=1,i;
	if(b==0)
		return 1;
	else
	{
		for(i=1;i<=b;i++)
		{
			_asm
			{
				finit
				fld r
				fld a
				fmul
				fst r
			}	
		}
		return r;
	}
}
double estepx(double x,int o)//��������� � � ������� �
{
	double h=1,s=1; int k;
	for(k=1;k<=o;k++)
		s=s+(celayastep(x,k)/facial(k));
	return s;
}
double tanH(double x,int o)//��������� ��������������� ������� 
{
	double h=1,k,j;
	h=estepx(x,o);
	j=1/h;
	k=(h-(j))/(h+(j));
	return k;
}
int main()
{
	const double pi=3.14159265;
	setlocale(LC_ALL, ".1251");
	/*char b[] = "������",a[]="� ���� ���";
	int len = 6;
	List i,o;
	_asm
	{
		inc len
		mov ecx, len
		lea esi, b
		lea edi, a
		rep movsb // ���������� �� esi � edi � ����������� esi � edi �� 1(�.�. movsB)
	}
	if(i.isEmpty())
			i.ins(9);
		i.ins(8);
	if(i.isEmpty())
	i.ins(1);
	cout << a;*/
	tanH(2*pi*0.1,11);
	return 0;
}
