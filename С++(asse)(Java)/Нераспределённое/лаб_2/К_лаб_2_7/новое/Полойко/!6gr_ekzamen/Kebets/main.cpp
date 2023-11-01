// main.cpp : Defines the entry point for the console application.
//

//Kebets 6 group

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "spisok.h"
#include "sort.h"
#include "kebets.h"
#include <iostream>
using namespace std;


void poisk(char *a,char *b,int &n) //Поиск слова в строке,  начиная  с заданной позиции
{
	int i=0,p;
	for(;a[n]!='\0';++n)
		if(a[n]!=',' && a[n]!=' ' && a[n]!='.' && a[n]!=':' && a[n]!=';')
		{
			for(p=n;a[p]!=',';++i,++p)
			{
				if(a[p]=='\0' || a[p]==' ' || a[p]=='.' || a[p]==';' || a[p]==':') break;
				b[i]=a[p];
			}
			if(p!=0){b[i]='\0';n=p+1;break;}
		}
}

bool chislo(char *a)//проверка слова: число или нет
{
	int i,t=0,z=0;
	for(i=0;a[i]!='\0';++i)++z;
	for(i=0;i<z;++i)
	switch(a[i])
	{
		case '0':++t;break;
		case '1':++t;break;
		case '2':++t;break;
		case '3':++t;break;
		case '4':++t;break;
		case '5':++t;break;
		case '6':++t;break;
		case '7':++t;break;
		case '8':++t;break;
		case '9':++t;break;
		default:break;
	}
	if (t==z) return true;
	else return false;
}



void Ekzamen()
{
	InitList();
	setlocale(LC_ALL,".1251");
	int i,j=0,k=0,n=0,Length=0,sizeMatr=0,sizeMatr2=0, qwerty=0,p,sum=0;
	char *slovo=(char*) malloc(500);
	char *temp=(char*) malloc(500);
	char *str=(char*) malloc(500);
	FILE *in,*out;
	in=fopen("Input.txt","a+");
	out=fopen("Out.txt","w+");

	while(!feof(in))
	{
		Length=0;
		fgets(str,499,in);
		for(i=0;str[i]!='\0';++i)
		{
			if(str[i]=='\n')
			{
				str[i]='\0';
				break;
			}
			++Length;
		}
		n=0;
		while(n<Length)
		{
			poisk(str, slovo, n);
			if(chislo(slovo)==true)
			{
				push_front(atoi(slovo));
				++sizeMatr;
				if(atoi(slovo)%3==0)
					++sizeMatr2;
			}
		}
	}

	int **Matr=new int*[3+sizeMatr2];
	Matr[0]=new int[sizeMatr];
	Matr[1]=new int[sizeMatr2];
	Matr[2]=new int[sizeMatr2];

	fputs("Matritsa Matr sostoit is ",out);
	fputs(itoa(3+sizeMatr2,temp,10),out);
	fputs(" strok\n",out);

	for(i=0;i<sizeMatr;++i)
	{
		Matr[0][i]= pop_back();
		fputs(itoa(Matr[0][i],temp,10),out);
		fputs(" ",out);
		if(Matr[0][i]%3==0)
		{
			Matr[1][j]=Matr[0][i];
			Matr[2][j]=Matr[0][i];
			++j;
		}
	}
	fputs("\n",out);
	for(i=0;i<sizeMatr2;++i)
	{
		fputs(itoa(Matr[1][i],temp,10),out);
		fputs(" ",out);
	}
	sort(Matr[2],sizeMatr2);
	fputs("\n",out);
	for(i=0;i<sizeMatr2;++i)
	{
		fputs(itoa(Matr[2][i],temp,10),out);
		fputs(" ",out);
	}

	for(i=0;i<sizeMatr2;++i)
	{
		k=0;
		j=3;
		sum=0;
		qwerty=Matr[1][i];
		while(sum!=153)
		{
			sum=0;
			while(qwerty!=0)
			{
				p=qwerty%10;
				qwerty=qwerty/10;
				sum+=p*p*p;
			}
			++k;
			qwerty=sum;
		}
		Matr[j]=new int[k];
		++j;
	}

	fputs("\n",out);
	for(i=0;i<sizeMatr2;++i)//poisk posledovatelnosti summy kubov
	{
		k=0;
		j=3;
		sum=0;
		qwerty=Matr[1][i];
		while(sum!=153)
		{
			sum=0;
			while(qwerty!=0)
			{
				p=qwerty%10;
				qwerty=qwerty/10;
				sum+=p*p*p;
			}
			Matr[j][k]=sum;
			fputs(itoa(Matr[j][k],temp,10),out);
			fputs(" ",out);
			++k;
			qwerty=sum;
		}
		fputs("\n",out);
		++j;
	}

	kebets();
}

void main()
{
	Ekzamen();
	_getch();
}

//Kebets 6 group