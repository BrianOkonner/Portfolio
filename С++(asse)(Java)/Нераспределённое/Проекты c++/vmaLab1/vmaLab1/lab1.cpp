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
using namespace std;
int main()
{
	setlocale(LC_ALL,"rus");
	ifstream in("matr.txt"),inf("f.txt");
	int n,i,j,k;
	double **ma,*f,*delit,*x,set=0,**marab,*nev,**ed,perem,opr,**obr;
	in>>(n);
	ma=new double*[n];
	for(i=0;i<n;i++)
		ma[i]=new double[n];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			in >> ma[i][j];
	}
	cout<<"Исходная матрица:"<<endl;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			cout << ma[i][j] << "  ";
		cout <<endl;
	}
	cout<<"Вектор f:"<<endl;
	inf>>n;
	f=new double[n];
	for(i=0;i<n;i++)
		inf>>f[i];
	for(i=0;i<n;i++)
		cout<<f[i]<<endl;
	marab=new double *[n];
	obr=new double*[n];
	for(i=0;i<n;i++)
		marab[i]=new double[2*n+1];
	in.clear();
	in.seekg(0,ios::beg);
	in>>n;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			in >> marab[i][j];
	for(i=0;i<n;i++)
	{
		for(j=n+1;j<2*n+1;j++)
			if(i==j-(n+1))
				marab[i][j]=1;
			else
				marab[i][j]=0;
	}
	inf.clear();
	inf.seekg(0,ios::beg);
	inf>>n;
	for(i = 0; i < n; i++)
		 inf>> marab[i][n];
	cout<<"Исходная матрица+вектор f+начало обратной матрицы(единичная):"<<endl;
	for(k = 0; k < n; k++)
	{
		for(j = 0; j < 2*n+1; j++)
			cout << marab[k][j] << "  ";
		cout <<endl;
	}
	delit=new double[n];
	for(i=0;i<n;i++)
	{
		delit[i]=marab[i][i];
		j=i;
		for(k=0;k<2*n+1;k++)
			marab[j][k]=marab[j][k]/delit[i];
		for(j=i+1;j<n;j++)
		{
			perem=marab[j][i];
			for(k=i;k<2*n+1;k++)
				marab[j][k]-=(marab[i][k]*perem);
		}
	}
	opr=1;
	for(i=0;i<n;i++)
		opr/=delit[i];
	x=new double[n];
	cout<<"Верхнетреугольная матрица с вектором f и началом обратной матрицы:"<<endl;
	for(k = 0; k < n; k++)
	{
		for(j = 0; j < 2*n+1; j++)
			cout << marab[k][j] << "  ";
		cout <<endl;
	}
	for(i=0;i<n;i++)
		obr[i]=new double[n];
	for(i=0;i<n;i++)
		for(j=n-1;j>=0;j--)
			if(j==n-1)
				obr[j][i]=marab[j][j+i+2];
			else
			{
				for(k=n-1;k>j;k--)
					set+=-(obr[k][i]*marab[j][k]);
				set+=marab[j][n+i+1];
				obr[j][i]=set;
				set=0;
			}
	cout<<"Обратная матрица:"<<endl;
	for(k = 0; k < n; k++)
	{
		for(j = 0; j < n; j++)
			cout << obr[k][j] << "  ";
		cout <<endl;
	}
	for(i=n-1;i>=0;i--)
	{
		if(i==n-1)
			x[i]=marab[i][i+1];
		else
		{
			for(k=n-1;k>i;k--)
				set+=-(x[k]*marab[i][k]);
			set+=marab[i][n];
			x[i]=set;
			set=0;
		}
	}
	ed=new double*[n];
	for(i=0;i<n;i++)
	{
		ed[i]=new double[n];
		for(j=0;j<n;j++)
		{
			ed[i][j]=0;
			for(k=0;k<n;k++)
				ed[i][j]+=ma[i][k]*obr[k][j];
		}
	}
	cout<<"Проверочная единичная матрица"<<endl;
	for(k = 0; k < n; k++)
	{
		for(j = 0; j < n; j++)
			cout << ed[k][j] << "  ";
		cout <<endl;
	}
	cout<<"Вектор x:"<<endl;
	for(i=0;i<n;i++)
		cout<<x[i]<<endl;
	nev=new double[n];
	for(i=0;i<n;i++)
		nev[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			nev[i]+=ma[i][j]*x[j];
	for(i=0;i<n;i++)
		nev[i]-=f[i];
	cout<<"Вектор невязки:"<<endl;
	for(i=0;i<n;i++)
	{
		printf("%.2e",nev[i]);
		cout<<endl;
	}
	cout<<"Определитель исходной матрицы:"<<endl;
	cout<<1/opr<<endl;
	system("pause");
}