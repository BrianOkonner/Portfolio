//�������� �����.7 ������.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{

	setlocale(LC_ALL,"RUS");
	
	char buf[99];
	char *leksem;
	char delim[]=" -,.;:!";
	char zagolovok[]="����� �����		�����		������		����� ������������������		����� �������\n";
	int s=1;
	int t=0;
	int k=1;
	int j=1;



	FILE *in;
	FILE *out1;
	FILE *out2;

	if((in=fopen("Input.txt", "r"))==NULL)
		cout<<"error Input file open"<<endl;
	if((out1=fopen("Result1.txt", "w+"))==NULL)
		cout<<"error Result1 file open"<<endl;
	if((out2=fopen("Result2.txt", "w+"))==NULL)
		cout<<"error Result2 file open"<<endl;

	fprintf(out1,"%s",zagolovok);

//��������� �� ����� � ��������� �� �������.
	do{
		fgets(buf,99,in);
		cout<<buf<<endl;
		leksem=strtok(buf,delim);
		
			while(leksem!=NULL)
			{
			fprintf(out1,"%d			%s",s,leksem);	
			cout<<leksem<<endl;	
			//���� ���������� ���������������������
			for(int i=1;i<strlen(leksem);i++)
			{
				if(leksem[t]==leksem[i])
					k++;//����� ������������������
				else
				{

					cout<<"������� ������������������ "<<leksem[t]<<"  ";
					fprintf(out1,"	%c",leksem[t]);
					t+=k;//��������� �� ��������� �������
					j=k;//����� ������������������ ����������� � j			
					cout<<"����� ������������������  "<<j<<endl;
					fprintf(out1,"		%d",j);
					k=1;

				}
				
			}

			s++;//����� �����
			leksem=strtok(NULL,delim);
			}
	}while(!feof(in));



	fclose(in);
	fclose(out1);
	fclose(out2);


	
	return 0;
}


