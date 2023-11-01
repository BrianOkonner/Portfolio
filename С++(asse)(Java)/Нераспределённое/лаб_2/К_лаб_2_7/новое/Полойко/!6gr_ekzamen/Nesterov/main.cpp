//   Нестеров Михаил 6гр

#include <string.h>
#include "stdio.h"
#include "conio.h"
#include "iostream"
#include "func.h"
#include "Spisok.h"
using namespace std;


void main()
{
	setlocale(LC_ALL,".1251");
	FILE* fread, *stream1;
	fread = fopen("input.txt","r");
	stream1 = fopen("output.txt","w+");

	char *str, *DArray, *DA;
	int i=0, j=0, a=0, n=0, g, mas_n, krat3_n, *mas, *krat3, *sort_krat3, *mas_sum, **Matr;
	mas = new int[50];
	krat3 = new int[50];
	sort_krat3 = new int[50];
	mas_sum = new int[100];
	str=new char[1000];
	DArray=new char[1000];
	DA = new char[1000];
	Matr=new int*[100];
	for (i=0;i<100;i++)
		Matr[i] =new int[100];


	node List;
	InitList();
		
	str = Fread(fread);
	DArray = slova_chisla(str);
	
	for(i=0; DArray[i]!=NULL; i++)
		DA[i]=DArray[i];
	DA[i]=NULL;
	i=0;
	char* ch = strtok(DA," ");
	mas[i++] = atoi(ch);
	while(ch!=NULL)
	{
		ch = strtok(NULL," ");
		if(ch!=NULL)
			mas[i++]=atoi(ch);
	}
	mas_n = i;
	for(i=0; i<mas_n; i++)
		push_front(mas[i]);
	for(i=0, j=0; i<mas_n; i++)
		if(mas[i]%3==0)
			krat3[j++]=mas[i];
	krat3_n = j;

	for(i=0; i<mas_n; i++)
		Matr[0][i]=mas[i];
	for(i=0; i<krat3_n; i++)
		Matr[1][i]=krat3[i];
	for(i=0; i<krat3_n; i++)
		sort_krat3[i]=krat3[i];
	sort_int(sort_krat3,krat3_n);
	for(i=0; i<krat3_n; i++)
		Matr[1][i]=sort_krat3[i];
	for(int i=0; i<mas_n ;i++)
			fprintf(stream1,"%5d",mas[i]);
		fprintf(stream1,"\n");
	for(int i=0; i<krat3_n ;i++)
			fprintf(stream1,"%5d",krat3[i]);
		fprintf(stream1,"\n");
	for(int i=0; i<krat3_n ;i++)
			fprintf(stream1,"%5d",sort_krat3[i]);
		fprintf(stream1,"\n");
	for(g=0; g<krat3_n; g++)
	{
	mas_sum[0] = sum_cub(sort_krat3[g]);
	for(i=0; mas_sum[i]!=153; i++)
	{
		mas_sum[i+1]=sum_cub(mas_sum[i]);
	}
	fprintf(stream1,"%d ",i+1);
	fprintf(stream1,"%d ",sort_krat3[g]);
	for(int j=0; j<i+1 ;j++)
			fprintf(stream1,"%5d",mas_sum[j]);
		fprintf(stream1,"\n");
	}
	rewind(stream1);
	fprintf(stream1,"Матрица состоит из %d строк\n",g+3);
	

	delete mas;
	delete krat3;
	delete sort_krat3;
	delete mas_sum;
	delete str;
	delete DArray;
	delete DA;
	_getch();
}
