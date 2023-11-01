
//made by ����� ���������, 8 ������ 2009_10
/*9. ����� ��������� ���� Input.txt, ��������� �� ����, � ��������� �����������. 
������������� ����� ������� �������� ��������� ��������� ������ ����������. 
����� ������, � ������� ����������� ������ �����������, 
�������������� ������ � ��������� ����� �����������.   
��������� �������� � ����� ���� Output.txt. 
����������� �����  � ������� ������������ �� �������� ���� ����, 
��������� ���������� �������� � ���� Out_sort.txt. 

�� ��������� ������ ��� ����������� � ������ � ����� ���������� ����. ���������
����������� � ������ � ����� ������ �������������� ����� ������.

���������� ���� �� ������ ��������� 255, ����� ������� ������������ � ����������.
����� ���� ����� (�������� � ������������� � ���������) �� ������ ������������ maxLength.
��� �������� ������� ��� ������ �� �������� ���� �������� �� asm, �� C++ �� �������� ����
������ � �������, ����-�����, ����� �������, ���� ��� ���������� ������� ���� � 
���������� �������� ����� �������. ��������� ��� ������ (������ � �������) ���� �������
�� C++ ������������� �� ��������� ������������� ��������� ������� ������������� ���������
� �������� ����������-������.*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
using namespace std;

const int maxLength=1000;

void main()				//made by ����� ���������, 8 ������
{
	int i=0,n=0,ind=1;
	char* k=NULL;
	char** mas=new char*[255];
	char *str1=new char[maxLength],*sent=new char[maxLength],*strout=new char[maxLength];
	char *strtmp=NULL;
	FILE *fin,*fout,*fsort;

	setlocale(LC_ALL,".1251");

	fin=fopen("input.txt","r");
	fout=fopen("output.txt","w");
	fsort=fopen("outSort.txt","w");

	sent[0]='\0';
	k=&sent[0];
	while ((*k)=='\0')
	{
		printf("������� ������-����\n");
		gets(sent);
		k=findFirstWord(sent,n);
	}

	while (!feof(fin))
	{
		fgets(str1,maxLength,fin);
		delEndl(str1);	//������� ������ �������� ������
		if (ifSent(sent,str1))	//�������� �� ��������� ����������� � ������
		{	//���������� � output.txt
			strout[0]='\0';
			strtmp=findFirstWord(str1,n);
			addWordEnd(strout,strtmp,n);
			addWordEnd(strout," ");		//��������� ������ �����
			addWordEnd(strout,str1);
			strtmp=findLastWord(str1,n);
			addWordEnd(strout," ");
			addWordEnd(strout,strtmp,n);	//��������� ��������� �����
			fprintf(fout,"%s\n",strout);	//���������� ���������

			i=0;		//�������� ����� ���� � �������
			k=detFirstWord(str1);
			while ((*k)!='\0') 
			{
				mas[i]=k;
				i++;
				k=detFirstWord(str1);
			}								//�������� ������ �� �����
			sortArrWord(mas,i);				//������������� ������
			strout[0]='\0';
			for(int j=0;j<i;j++) 
			{
				addWordEnd(strout,mas[j]); 
				if (j!=i-1) addWordEnd(strout," ");
			}								//���������� ��������������� ������ � ������
			fprintf(fsort,"%s\n",strout);	//� � ����
			//cout<<strout<<endl;
		}
		printf("������ %d ����������\n",ind);
		ind++;
	}
	fclose(fin);
	fclose(fout);
	fclose(fsort);
	delete[] mas;
}