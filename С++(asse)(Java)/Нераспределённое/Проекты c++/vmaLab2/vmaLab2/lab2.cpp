#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cstdlib>
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
	double **ma,**mat,**ma2,*f,*f2,*d,**s,sum=0,sum2=0,*y,*x,*nev,det=1;
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
	mat=new double*[n];
	for(i=0;i<n;i++)
		mat[i]=new double[n];
	ma2=new double*[n];
	for(i=0;i<n;i++)
		ma2[i]=new double[n];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			mat[i][j]=ma[j][i];
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			ma2[i][j]=0;
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				ma2[i][j]+=ma[i][k]*mat[k][j];
	}
	cout<<"Матрица А*Ат:"<<endl;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			cout << ma2[i][j] << "  ";
		cout <<endl;
	}
	cout<<"Вектор f:"<<endl;
	inf>>n;
	f=new double[n];
	for(i=0;i<n;i++)
		inf>>f[i];
	for(i=0;i<n;i++)
		cout<<f[i]<<endl;
	f2=new double[n];
	for(i=0;i<n;i++)
		f2[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			f2[i]+=mat[i][j]*f[j];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			f2[i]+=mat[i][j]*f[j];
	cout<<"Матрица Ат на вектор f:"<<endl;
	for(i=0;i<n;i++)
		cout<<f2[i]<<endl;
	d=new double [n];
	s=new double *[n];
	y=new double [n];
	x=new double [n];
	for(i=0;i<n;i++)
		s[i]=new double[n];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			s[i][j]=0;
	}
	for(i=0;i<n;i++)
	{
		if(i>0)
			for(k=0;k<=i-1;k++)
			{
				sum+=s[k][i]*s[k][i]*d[k];
			}
		d[i]=(ma2[i][i]-sum)/abs(ma2[i][i]-sum);
		s[i][i]=sqrt(abs(ma2[i][i]-sum));
		det*=s[i][i]*s[i][i]*d[i];
		for(j=i+1;j<n;j++)
		{
			for(k=0;k<=i-1;k++)
				sum2+=s[k][i]*d[k]*s[k][j];
			s[i][j]=(ma2[i][j]-sum2)/(d[i]*s[i][i]);
			sum2=0;
		}
		sum=0;
	}
	cout<<"Матрица S:"<<endl;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			cout << s[i][j] << "  ";
		cout <<endl;
	}
	for(i=0;i<n;i++)
	{
		for(k=0;k<=i-1;k++)                                                                                                                                                                                          
			sum+=s[k][i]*y[k];
		y[i]=(f2[i]-sum)/s[i][i];
		sum=0;
	}
	cout<<"Вектор y:"<<endl;
	for(i=0;i<n;i++)
		cout<<y[i]<<endl;
	sum=0;
	for(i=n-1;i>=0;i--)
	{
		for(k=i+1;k<n;k++)
			sum+=d[i]*x[k]*s[i][k];
		x[i]=(y[i]-sum)/(d[i]*s[i][i]);
		sum=0;
	}
	cout<<"Вектор x:"<<endl;
	for(i=0;i<n;i++)
		cout<<x[i]<<endl;
	nev=new double[n];
	for(i=0;i<n;i++)
		nev[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			nev[i]+=ma2[i][j]*x[j];
	for(i=0;i<n;i++)
		nev[i]-=f2[i];
	cout<<"Вектор невязки:"<<endl;
	for(i=0;i<n;i++)
		cout<<nev[i]<<endl;
	det=sqrt(det);
	cout<<"Модуль определителя исходной матрицы:"<<endl<<det<<endl;
	system("pause");
}