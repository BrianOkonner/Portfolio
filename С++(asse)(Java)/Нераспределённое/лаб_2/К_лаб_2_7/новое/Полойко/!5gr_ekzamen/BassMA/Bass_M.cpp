//Bass-6
# include <stdafx.h>
# include <iostream>
# include <stdio.h>
# include <string>
# include <stdlib.h>
# include <conio.h>
# include <fstream>

using namespace std;


void obnul (int **str)
{
	for (int y=0;y<256;y++)
		for (int x=0;x<256;x++)
			str[y][x]=1;
}

void slova (int *N,int *lg, char *str , char **mas, int n, int m)
{
	int maxt=0;
	for (int y=0;y<n;y++)//word
	{
		for (int x=0;x<strlen(mas[y]-1);x++)
		{	
			if(mas[y][x]==mas[y][x+1])
			{
				m++;
			}
			if (m>maxt)
			{
				maxt=m;
				str[y]=mas[y][x-maxt];
				lg[y]=maxt;
				*N=x-maxt;
			}
			if (mas[y][x]!=mas[y][x+1])
				m=0;
		}
	}
}

int main()
{
	setlocale(LC_ALL,".1251");
	int i=0,n=0,k=0,m=0;
	FILE *in,*out;
	char* temp = new char[256];
	char* buff = new char[256];
	char* str = new char[256];
	int* lg = new int[256];
	int* N = new int[256];
	char razd[] = " ,.;:!";
//
	char **mas = new char * [20];
	for(i=0;i<20;i++)
		mas[i] = new char[256];
//
	if((in = fopen("input.txt","r"))!=NULL)
	{
		out = fopen("Result1.txt","w+");
		while(!feof(in))
		{
			fgets (temp,256,in);
			if(strlen(temp)==1)
				continue;
			buff=strtok(temp,razd);
			while(buff!=NULL)
			{
					strcpy(mas[n],buff);
					n++;
				buff=strtok(NULL,razd);
			}
		}
		slova(N,lg,str,mas,n,m);
		fprintf(out,"%s\n","Word Number\tWord\tSumbol\tHow long\tSumbol number");
		for (int y=0;y<n;y++)
			fprintf(out,"%s\n",y,"\t",mas[y],"\t",str[y],"\t",lg[y],"\t",N[y]);
		fclose(in);
		fclose(out);
	}
	
	else cout<<"Error opening file"<<endl;
	cout<<"\Thank\n";
	for(i=0;i<20;i++)
		delete [] mas[i];
	delete [] mas;
	delete [] temp;
	delete [] buff;
	delete [] str;
	_getch();
}