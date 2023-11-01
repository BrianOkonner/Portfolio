#include <math.h>
#include "Kostlib.h"

bool prost(double x)
{
	if (x == 1) return false;//���� �������� ����� 1, �� ��� �� �������
	else
	{
		int i = 2;//���� ��������, ������� � 2
		while (i <= int (sqrt(x))) //���� ������� ������ ����������� ����� �� ��������� �����
		{
			if (((int(x))%i) == 0) return false;//���� �� ���-�� ��������� � �������� ���� � �������,�� ����� �� �������
			i = i + 1;
		}
		return true;//���� �� ������� �� ��� ��� �� ��������, �� ����� �������. ��������� ������.
	}
}
/////////////////////////
//�������. �������� ����������
void obm(int* mas,int n)
{
	bool flag;
	int co,i,per;
	co=1;
	flag=true;
////////////////
	while (flag)
	{
		flag=false;//������ ���� �� ������, ���� ������ ������������.
		//(���� ��� ���,���� ���������� � ���� �������� � �� �������� ���� => ����� �� �������� �����)
		i=0;
		while (i!=n-co)//���� �� ������ �� ����� ����������������� ����� �������
		{
			if (*(mas+i)>*(mas+i+1))//���� ���������� ������� ������ ����������
			{
				per=*(mas+i);//������ �� �������
				*(mas+i)=*(mas+i+1);
				*(mas+i+1)=per;
				flag=true;//������ ���� <=> ������ �� ��� ������������ �� ������� �� ����,����� ���������� ����������
			}
			i=i+1;//��������� �������
		}
		co=co+1;//����������,"����������" �� ������� ��������������� �����.
	}
}
/////////////////////////
//�������.���� ������������ ������� � �������.
int maximum(int* mas,int n)
{
	int i;
	int ind;
	i=1;
	ind=0;
////////////////
	while (i!=n)//���� �� ������ �� ����� �������
		{
			if (*(mas+i)>*(mas+ind)) ind=i;//���� ������� ������� ������ �������������, ���������� ��� ������
			i=i+1;
		}
	return ind;//���������� ������ ������������� ��������
}
/////////////////////////
//�������.���������� �������.
void vyb(int* mas,int n)
{
	int i,per;
////////////////
	while (n>0)//���� �� ������ �� ����� �������
	{
		i = maximum(mas,n);//������� ������ ������������� �������� � ����������������� ����� �������
		//������ ������� ������� ������������ ������� �� ��� �����
		per=*(mas+i);
		*(mas+i)=*(mas+n-1);
		*(mas+n-1)=per;
		n=n-1;//"��������" �� ��������� ������� ��������������� �����
	}
}
/////////////////////////
//������.���������� ���������
void vstav(int *mas, int n)
{
	int i,j,per;
	i=1;
////////////////
	while (i<n)//���� �� ������ �� ����� �������
	{
    per=*(mas+i);//����������� per �������� i-���� ��������
	j=i-1;//����������� �������� j �������� i-1
	while ((j>=0)&&(per<*(mas+j)))//���� �� ������ ����� ��� �������
	{
      *(mas+j+1)=*(mas+j);//�������� ������
	  j=j-1;
	}
    *(mas+j+1)=per;//��������� � ��������� ����� per �������
	i=i+1;
	}
}
/////////////////////////
int minel(int a, int b, int c)//����� �������� �� ���� �����
{
	int min=a;
	if (b<min) min=b;
	if (c<min) min=c; 
	return min;
}
/////////////////////////
/*bool sitest(char ch)//�������� ������� �� �����������
{
	const char sign[24]={' ','.',',',';',':','\\','/','!','?','(',')','{','}','[',']','@','\"','+','-','=','*','<','>'};
	int i=0;
	while (i<24)
	{
		if (ch==sign[i]) {return true;}
		else i=i+1;
	}
	if (i==24) return false;
}*/
/////////////////////////
