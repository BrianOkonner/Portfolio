// B9(L5).cpp : Defines the entry point for the console application.
/*												������ �B9
	��������� ������� ��������� ������������ ������������.( �������������: ���������� ������������. ������ 8).
	������� :����� ��������� ���� Input.txt, ���������  �� ���� � ��������� �����������.
������������� ����� ������� �������� ��������� ��������� ������ ����������.
�����  ������, � ������� ����������� ������ �����������, �������������� ������ � ��������� ����� �����������. 
��������� ��������  � ����� ���� Output.txt. ����������� �����  � ������� ������������ ��  �������� ���� ����, ��������� ����������
�������� � ���� Out_sort.txt. 
	������� �������� :(����������� ������ ���������� �� ����� � �������(���� � ��������) � ������������� �� � ����� ����������
� ��������� �����) 
	����� :*/
// file_read.cpp: ���������� ����� ����� ��� ����������� ����������.
 
//#include <stdafx>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <search.h>
#include <string>
#include <cstdio> 
using namespace std;
 
int main()
{
    //setlocale(LC_ALL, "rus"); 
    setlocale(LC_ALL,".1251");// ���������� ����������� ���������
	char buff[50]; // ����� �������������� �������� ������������ �� ����� ������
   
	// �����  ���� ������ "r" "w" -> ios::in ios::out  �.� std Class 
	ifstream in("input.txt",ios::in);      //   ������� ���� ��� ������
	ofstream out("output.txt",ios::out);   //  ��� ������
	ofstream outs("out_sort.txt",ios::out); //  ��� ������ ����.
	//
	if(in==NULL||out==NULL||outs==NULL)//����� ���������
   {
      cout<<"������ � �������� ����� "<<endl;
   }    
	else 
	{
	 
		// ��� ��������--->
	// ������� ��� ��������������� /*  */
	in >> buff; // ������� ������ ����� �� �����
    cout << buff << endl; // ���������� ��� �����
 
    in.getline(buff,50); // ������� ������ �� �����
    
	cout << endl;

	cout << buff << endl; // ���������� ��� ������
	
   // <-- ��� ��������

	 
	  // !!! ��� ������������� 
	 //   �� ���� ������ ��������
	 // ������ �� ��������
		int i=0,o=-1,p=-1,l=0,j=0,h,q=1,a=0,g;
		char *str,up[100],*c="12",*k;
		c=new char(100);
		str=new char (100);
		k=new char(200);
	
		for(i='A';i<='Z';i++&&j++)
			up[j]=i;
		for(i='�';i<='�';i++&&j++)
			up[j]=i;
		up[j]='�';
		up[j+1]='\0';
		for(j=j;j>=0;j--)
		cout<<up[j];
		while(!in.eof())
		{
			l++;
			in.getline(str,100,'\n');
		c[0]=str[0];
		if(strpbrk(c,up)!=0&&q==1)
			{o=0;
			h=l;
			for(i=0;str[i]<0||(ispunct(str[i])!=0&&isspace(str[i])!=0);i++)
				k[i]=str[i];
			k[i]=' ';
			k[i+1]=str[0];
			i++;
			for(g=1;str[g]!='\0';g++)//���� ���������������� ������ ������� � ����
				k[i+g]=str[g];
			g=1;
			k[i+g]='\0';
			str=k;//�� ��� �� ��� ��������, ����� ������� ������ ��� ���� ���� ����������
		}
			//for(i==i;(str[i]>0&&ispunct(str[i])==0)||(str[i]>0&&isspace(str[i])==0);i++){}
			//InsStrNum(k,str,i);
			//break;
		i=0;
		q=0;
        while(str[i]!='\0')   
        {
			c[0]=str[i+2];
			if((str[i]=='.'||str[i]=='!'||str[i]=='?')&&str[i+1]==' '&&strpbrk(c,up)!=0&&o==-1)
			{
				o=i+2;
				h=l;
			for(g=2;str[g]<0||(ispunct(str[i+g])!=0&&isspace(str[i+g])!=0);g++)
				k[g]=str[i+g];
			k[i+g]=' ';
			k[i+g+1]='\0';
			i++;
			}
		if (o!=-1)
		{
			if((str[i]=='.'||str[i]=='!'||str[i]=='?')&&(str[i+1]=='\0'||str[i+1]==' '))
			{
				p=i;
				a=l;
				for(i--;str[i]<0||(ispunct(str[i])==0&&isspace(str[i])==0);i--){}
				i++;
			for(g=0;str[i+g]<0||(ispunct(str[i+g])==0&&isspace(str[i+g])==0);g++)
				k[g]=str[i+g];
			k[g]=' ';
			k[g+1]='\0';
			break;
			}
		}
		if(str[i]=='.'||str[i]=='!'||str[i]=='?')
			q=1;
			i++;
		}
		for(g=0;str[g]!='\0';g++)
			out<<str[g];
		out<<endl;
		if(p!=-1)
		break;
		}
		cout<<o<<" "<<p<<" "<<a<<" "<<h<<endl;
		//for(i=0;!feof(in);i++);
		cout<<k;
	
	// ��������� �����
	in.close();
	out.close();
	outs.close();	
 
	}
   system("pause");
    return 0;
}