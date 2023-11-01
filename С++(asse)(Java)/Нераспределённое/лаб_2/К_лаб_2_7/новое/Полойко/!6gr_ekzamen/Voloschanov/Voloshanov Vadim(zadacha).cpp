//Волошанов Вадим

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	char chis[80];
	char raz[]=" .,;:";
	int *Massiv1;
	Massiv1=new int[80];
	int *Massiv2;
	Massiv2=new int[80];
	int *Massiv3;
	Massiv3=new int[80];
	char *s;
	int o=0;
	int i=0;
	int j=0;
	int code;
	int code2;
	int e;
	int y=3;
	int summa=0;
	int **Rezult1;
	/* выделяем память для указателей на строки */
Rezult1=(int**)malloc(20*sizeof(int*));
/* выделяем память для строк */
	for (i=0;i<20;++i)
	{
		Rezult1[i] = (int*)malloc(20* sizeof(int));
		/* если ошибка, то освобождаем память и выходим из программы */
		if (!Rezult1[i])
    	{
			for (j = 0; j < i; ++j)
				free(Rezult1[j]);
			free(Rezult1);
			printf("Error: there is no memory.\n");

			return 1;
		}
	}
FILE* in;
	if(!(in = fopen("Input.txt", "r")))
	{
		printf("Open file failed.\n");
		return 1;
	}
FILE* out;
	if(!(out = fopen("Output.txt", "w")))
	{
		printf("Open file failed.\n");
		return 1;
	}
do  
	{ 
	fgets(chis, 80, in);
	s=strtok(chis, raz);
	while (s!=0)
	{
	Massiv1[i]=(int)s;
	Rezult1[0][j]=Massiv1[i];
	if(Massiv1[i]%3==o)
	{
		Massiv2[i]=Massiv1[i];
		Rezult1[1][j]=Massiv1[i];
	}
	i++;
	j++;
	s=strtok(NULL,raz);
	}}
	while(!feof(in));
	i=0;
	while(Massiv2[i]!=0)
	{
		summa=0;
		while(Massiv2[i]=0)
		{
		Massiv2[i]=Massiv2[i]/10;
		code=Massiv2[i]%10;
		code2=code*code;
		code=code*code2;
		summa=summa=code;
		}
		Massiv3[i]=summa;
		i++;
	}
for (i = 0; i < 20; ++i)
{
	for (j=0; j<20;++j)
	{
	Rezult1[i+4][j]=Massiv3[i];
	}}


for(i=0; i < 20; i++)
	for(j=0; j < 20; j++)
		fprintf(out, "%20d %20\n", Rezult1[i][j]);


/* освобождаем выделенную память */
for (i = 0; i < 20; ++i)
		free(Rezult1[i]);
	free(Rezult1);
fclose(in);
fclose(out);
return 0;
}


