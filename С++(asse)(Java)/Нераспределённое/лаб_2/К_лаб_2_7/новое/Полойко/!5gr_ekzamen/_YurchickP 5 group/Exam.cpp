/*Yurchik Paul 5 group*/

#include<iostream>
#include<fstream>
#include<stdio.h>
#include"list.h"

using namespace std;

char razd[]={' ','-',',','.',':',';','!','"'};
int **mas;

int schot(int n)
{
	if (n!=0)
		return(schot(n/2)+n%2);
}

void sort(int aa, int bb)
{
	int ii=aa,jj=bb,xx=mas[(aa+bb)/2][0],zz;
	while (ii<jj)
	{
		while (mas[ii][0]<xx)
			ii=ii+1;
		while (mas[jj][0]>xx)
			jj=jj-1;
		if (ii<=jj)
		{
			zz=mas[ii][0];
			mas[ii][0]=mas[jj][0];
			mas[jj][0]=zz;
			zz=mas[ii][1];
			mas[ii][1]=mas[jj][1];
			mas[jj][1]=zz;
			ii=ii+1;
			jj=jj-1;
		}
	}
	if (ii<bb)
		sort(ii,bb);
	if (aa<jj)
		sort(aa,jj);
}

bool pr(char c)
{
	int i=0;
	bool induk=false;
	while ((i<8)&&(!induk))
	{
		if (c==razd[i])
			induk=true;
		i=i+1;
	}
	return (induk);
}

int pn(char* str,int pos)
{
	int i=0;
	while (!pr(str[pos+i]))
		i=i+1;
	return(i+pos);
}

void main()
{
	spisok_slov* spis,*uk;
	ifstream in("input.txt");
	FILE* out=fopen("result1.txt","w");
	char str[82],*str11;
	int pos=0,pos_nach,pos_kon,n,dl,i;
	spis=new spisok_slov;
	spis=NULL;
	while (!in.eof())
	{
		in.getline(str,80);
		dl=strlen(str);
		str[dl]=' ';
		str[dl+1]='\0';
		i=0;
		pos=0;
		while (str[i]!='\0')
		{
			while (pr(str[pos]))
				pos=pos+1;
			if (str[pos]=='\0')
			{
				i=pos;
				continue;
			}
			pos_kon=pn(str,pos);
			n=pos_kon-pos;
			str11=new char[n];
			strncpy(str11,str+pos,n);

			str11[n]='\0';
			uk=spis;
			if (n>0)
			{
				if (uk==NULL)
				{
					spis=new spisok_slov;
					spis=add_el(spis,str11,n);
					spis->no=1;
				}
				else
				{
					while (uk->next!=NULL)
						uk=uk->next;
					uk->next=add_el(spis,str11,n);
				}
			}
			uk=spis;
			while (uk->next!=NULL)
				uk=uk->next;
			vvod_dannyh(uk);
			i=pos_kon+1;
			pos=i;
		}
	}
	uk=spis;
	int kol;
	while (uk!=NULL)
	{
		if (uk->next!=NULL)
			uk->next->no=uk->no+1;
		kol=uk->no;
		fprintf(out,"%3d %81s %5c %5d %5d\n",uk->no,uk->slovo,uk->simvol,uk->dl,uk->pos);
		uk=uk->next;
	}
	in.close();
	fclose(out);
	int** matr;
	uk=spis;
	matr=new int* [kol];
	for (i=0;i<kol;i++)
		matr[i]=new int [4];
	int x,j;
	mas=new int* [kol];
	for (i=0;i<kol;i++)
	{
		mas[i]=new int [2];
		mas[i][0]=0;
		mas[i][1]=0;
	}
	for (i=0;i<kol;i++)
	{
		x=uk->dl;
		mas[i][1]=x;
		matr[i][0]=uk->no;
		matr[i][1]=uk->simvol;
		matr[i][3]=uk->pos;
		j=0;
		mas[i][0]=schot(x);
		uk=uk->next;
	}
	sort(0,kol-1);
	FILE* out2=fopen("result2.txt","w");
	for (i=0;i<kol;i++)
	{
		matr[i][2]=mas[i][1];
		fprintf(out2,"%3d %3c %3d %3d\n",matr[i][0],matr[i][1],matr[i][2],matr[i][3]);
	}
}
