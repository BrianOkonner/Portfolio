#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cstdlib>
#include "fun_h.h"
#include <ctime>
#include "Windows.h"
#include <stdio.h>
#include <time.h> 
#include <string>
#include <conio.h>
#include <vector>
#include "matr.cpp"
void change(int *a,int *b)
{
	*a=(*b)+(*a);
	*b=(*a)-(*b);
	*a=(*a)-(*b);
}
void bubble_srt(int *a,int n)//Сортировка улучшенным пузырьком
{
	int i,j,d=0,t=1;              
	i=1;
	while(i<=n && t!=0)
    {
		t=0;
		for (j=0;j<n-1;j++)
		  if (a[j]>a[j+1]) 
		  {
			change(&a[j],&a[j+1]);
		    t=1;
		  }
    i++;
	}
}
int main()
{
	setlocale(LC_ALL, "rus"); 
	cout<<"Введите номер способа выполнения задачи(1-через матрицу, 2- через массив)";
	switch(_getch()-'0')
	{
		case 1:
		{
			matr ma(6);
			int a,b,*ar;
			ifstream in("Data.txt");
			ofstream out("Output.txt");
			in>>ma;
			a=ma.matdim();
			b=ma[a-2][a-2];
			for(int i=0;i<a;i++)
				for(int j=0;j<a;j++)
					if(i<j)
						ma[i][j]=b;
			out<<ma;
			ar=new int[a];
			ar[0]=ma[0][0];
			for(int i=1;i<a;i++)
				ar[i]=ma[i][i]-ma[i-1][i-1];
			bubble_srt(ar,a);
			out<<endl;
			for(int i=0;i<a;i++)
				out<<ar[i]<<" ";
			out<<endl;
				return 0;
		}
		case 2:
		{
			int a,b,*ar;
			ifstream in("Data.txt");
			ofstream out("Output.txt");
			in>>a;
			vector<vector <int>> ma(a,a);
			for(int i=0;i<a;i++)
				for(int j=0;j<a;j++)
					in>>ma[i][j];
			b=ma[a-2][a-2];
			for(int i=0;i<a;i++)
				for(int j=0;j<a;j++)
					if(i<j)
						ma[i][j]=b;
			for(int i=0;i<a;i++)
			{
				for(int j=0;j<a;j++)
					out<<ma[i][j]<<" ";
				out<<endl;
			}
			ar=new int[a];
			ar[0]=ma[0][0];
			for(int i=1;i<a;i++)
				ar[i]=ma[i][i]-ma[i-1][i-1];
			bubble_srt(ar,a);
			out<<endl;
			for(int i=0;i<a;i++)
				out<<ar[i]<<" ";
			out<<endl;
			return 0;
		}
	}
}
