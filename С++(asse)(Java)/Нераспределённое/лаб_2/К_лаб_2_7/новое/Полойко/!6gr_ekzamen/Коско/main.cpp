//Коско Дмитрий
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
int posl(int a)
{
	int x;
	while (a!=0)
	{
		x=a%10;
		a=(a-x)/10;
	}
	return x;
}
bool is_number(char c)
{
	return (c >= '0' && c <= '9');
}
bool kr3(int a)
{
	if (a%3==0)
		return true;
	else
		return false;
}
int razl(int a)
{
	int x=0;
		while (a!=0)
		{
			x+=(a%10)^3;
			a=(a-(a%10))/10;
		}
	return x;
}
int main()
{
	setlocale (LC_ALL,".1251");
	int n=0, i=0, t=0, x;
	int *ch=new int [100];
	int B[100];
	bool ka=false;
	char end='\n';
	char *tmp= new char[80];
	char *bufer= new char[80];
	char razd[]=" ,.;:";
	char **mas=new char * [20];
	for(i=0;i<20;i++)
		mas[i]=new char[256];
	int **Matr=new int * [100];
	for(i=0;i<100;i++)
		Matr[i]=new int [101];
	FILE *in, *out;
	if((in=fopen("Input.txt","r"))!=NULL)
	{
		out=fopen("Output.txt","w+");
		while(!feof(in))
		{
			fgets (tmp, 80, in);
			if (strlen(tmp)==1)
				continue;
			bufer=strtok(tmp,razd);
			while (bufer!=NULL);
			{
				for(int k=0; k<strlen(bufer); k++)
				{
					if(is_number(bufer[k]))
						ka=true;
					else
						if (bufer[k]==end)
							ka=true;
						else
							ka=false;
				}
				if(ka)
				{
					strcpy(mas[n],bufer);
					ch[n]=atoi(mas[n]);
					n++;
				}
				bufer=strtok(NULL,razd);
			}
		}
		for (int k=0; k<n;k++)
			Matr[0][k]=ch[k];
		for (int k=0; k<n;k++)
			if (kr3(Matr[0][k]))
			{
				Matr[1][t]=Matr[0][k];
				B[t]=posl(Matr[1][t]);
				t++;
			}
		for (int k=0; k<t; k++)
			for (int j=k+1; j<t; j++)
			{
				if (B[k]>B[j])
				{
					x=B[j];
					B[j]=B[k];
					B[k]=x;
					x=Matr[1][j];
					Matr[1][j]=Matr[1][k];
					Matr[1][k]=x;
				}
			}
		x=2;
		int z=3;
		for (z; z<t+3; z++)
		{
			Matr[z][1]=Matr[2][z-3];
			while(Matr[z][x]!=153)
			{
				Matr[z][x+1]=razl(Matr[z][x]);
				x++;
			}
			Matr[z][0]=x-3;
			x=2;
		}
		fprintf(out,"%s\n","Матрица Matr состоит из %d", z ," строк");
		for (int k=0;k<z;k++)
		{
			for (int j=0;j<100;j++)
				fprintf(out," %d", Matr[k][j]);
			fprintf(out,"\n");
		}
		fclose(in);
		fclose(out);
	}
	else
		printf("Файл не открывается");
for(i=0;i<20;i++)
		delete [] mas[i];
	delete [] mas;
	delete [] tmp;
	delete [] bufer;
	return 0;
}