//�������� �����
#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <cstdio>  
#include <cstring>   
#include <cstdlib>   
#include <fstream>
#include "Spisok.h"

using namespace std;

bool proverka (char*p);        // ��������� �� �����-�����



int main()
{
	setlocale(LC_ALL,".1251");
	FILE*in=fopen("Input.txt", "r"), *out=fopen("Output.txt", "w");
	char deliometers[] = " ,.;:";
	int Max, Min;
	char *s, *p;
	int * DArray=new int[1000];
	int * NewArray=new int[1000];
	for(int i=0;i<1000;i++)
	DArray[i]=0;
	s=new char[10000];
	int u=0;
	fputs("������� Matr ������� �� M �����\n",out);
	while (!feof(in))
	{
	fgets(s, 10000, in);
	p=strtok (s, deliometers);
	while (p!=0)
	{
	if (proverka(p)!=0)
	{
	fputs(p,out);
	fputs(" ",out);
	DArray[u]=atoi(p);     //��������� �����-����� ��������� � ������������ ������ DArray
	u++;
	}
	p=strtok (0, deliometers);
	}
	}
	for(int i=0;i<u;i++)
	{
		cout<<DArray[i]<<" ";  }    /*� ���������������  �������� ������������ ������ 
	                                ����� �������� �����-����� � ������� ������� push_back()*/

    cout<<endl;
	fputs("\n",out);
	for(int i=0;i<u;i++)	{
		if (DArray[i]%3==0){
			NewArray[i]=DArray[i];
			cout<<NewArray[i]<<" ";
			fputs(itoa(NewArray[i],s,10), out);//������� ����� � ������
			fputs(" ",out);
		}		
	}

	for(int i=0;i<u;i++)
	{
	
	int r=0,b, c, k;
	b = NewArray[i];
		while (b>0)	{
			c=b%10;
			k=c*c*c;
			r=k;
			r=r+k;
			b=b/10;
		}
		cout<<"\n"<<r;


	}
	_getch();
}


bool proverka (char*p)          // ��������� �� �����-�����
{
	int a=0;
	bool k=true;
	for (int i=0;i<strlen(p); i++)	{
		a=(int) p[i];
		if ((48>a)||(58<a))	{
			k=false;
		}
	}
	return k;
}


//�������� �����