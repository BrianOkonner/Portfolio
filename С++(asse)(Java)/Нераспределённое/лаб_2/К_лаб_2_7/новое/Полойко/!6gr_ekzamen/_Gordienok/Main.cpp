// Гордиенок Максим 6 группа 1 курс 19.12.2010

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include "Math.h"
#include "Spisok.h"
using namespace std;
int s;
int Array (int n)
{
	int t;
	if (n/10 == 0)
	{
		s+=n*n*n;
		return s;
	}
	else 
	{
		t = n%10;
		s+= t*t*t;
		Array (n/10);
	}
	return s;
}
int* sort (int* mass,int n)
{
	int tmp,*res, *last, m = 0;
	last = new int [n];
	res = new int [n];
	for (int i = 0;i<n;i++)
		res[i] = mass[i];
	for (int i = 0;i<n;i++)
	{
		tmp = res[i];
		while (tmp>9)
		{
			tmp/=10;
		}
		last[m++] = tmp;
	}
	for (int i = n-1;i>0;i--)
	{
		for (int m = 0;m<n;m++)
			if (last[i]<last[i-1])
			{
				tmp = res[i];
				res[i] = res[i-1];
				res[i-1] = tmp;
				tmp = last[i];
				last[i] = last[i-1];
				last[i-1] = tmp;
			}
	}
	delete [] last;
	return res;
}
int _tmain(int argc, _TCHAR* argv[])
{
	FILE *in,*out;
	int i;
	char *str;
	head->init();
	if (!(in = fopen("Input.txt","r")))
		{
			cout<<"File not found!";
			_getch();
			return 0;
		}
	out = fopen("Out.txt","w+");
	str = new char [81];
	int N_3 = 0, N_ALL = 0;
	while (fgets(str,80,in)!= NULL)
	{
		for (i = 0;i<strlen(str);i++)
		{
			if ((str[i]>='0')&&(str[i]<='9'))
			{
				head->push_in_head(atoi((str+i)));
				if ((head->item%3) == 0)
					N_3++;
				while ((str[i]>='0')&&(str[i]<='9'))
					++i;
				N_ALL++;
			}
		}
	}
	int M = N_3 + 3, **Matr, Arr[100];
	for (i=0;i<100;++i)
		Arr[i] = -1;
	Matr = new int* [M];
	Matr[0] = new int [N_ALL];
	Matr[1] = new int [N_3];
	Matr[2] = new int [N_3];
	i = 0;
	int m=0, k = 3, u = 1, r = 0;
	while (!tail->isEmpty())
	{
		if (tail->item%3 == 0)
		{
			i = 0;
			Arr[i++] = tail->item;
			do
			{
				Arr[i++] = Array (Arr[i-1]);
				s = 0;
			}
			while (Arr[i-1] != 153);
			i = 0;
			Matr[1][r++] = Arr[i];
			Matr [k] = new int [i+2];
			u=1;
			do
				Matr [k][u++] = Arr[i];
			while (Arr[i++] != 153);
			Matr[k++][0] = i-1;
		}
		Matr[0][m++] = tail->pop_out_tail();
	}
	for (i = 0;i<N_ALL;++i)
		fprintf(out,"%d ",Matr[0][i]);
	fprintf(out,"\n");
	for (i=0;i<N_3;i++)
		fprintf(out,"%d ",Matr[1][i]);
	fprintf(out,"\n");
	Matr[2] = sort (Matr[1],N_3);
	for (i = 0;i<N_3;++i)
		fprintf(out,"%d ",Matr[2][i]);
	fprintf(out,"\n");
	for (i=3;i<k;i++)
	{
		m = 0;
		do
			fprintf(out,"%d ",Matr[i][m]);
		while (Matr [i][m++] != 153);
		fprintf(out,"\n");
	}
	delete [] Matr;
	_getch();
	return 0;
}

