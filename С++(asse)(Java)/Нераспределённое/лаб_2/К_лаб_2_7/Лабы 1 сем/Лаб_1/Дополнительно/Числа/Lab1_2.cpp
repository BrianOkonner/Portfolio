// Lab1_2.cpp : Defines the entry point for the console application.
/* ����������� ��������� ��� ������ �� ����� ���������� N ����� ������������, 
   ���������� �� �������� '*' � �������� ���:

      *
      ***
      *****
      .......

   ��� ���� ����������� ������� ������ � ������ ���� N - �������� �����.*/

#include "stdafx.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	int n=-1;
	//���� N
	printf("Input N:\n");
	scanf("%d",&n);
	//��������� �� ��������
	if (n%2)
	{   //������ ����������        
		printf("The result:\n");
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=i;++j)
				printf("* ");
            printf("\n");
		}
	}
	else
        printf("N=2*k,k-integer value\n");   //����� ������
	return 0;
}
