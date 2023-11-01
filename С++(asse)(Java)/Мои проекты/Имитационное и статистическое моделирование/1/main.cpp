#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "fun_h.h"
#define K 192
using namespace std;
void main()
{
    setlocale(LC_ALL, "rus");
    int n=1000,i,j,stepM=31,a01=146051657,c1=218599011,a02=351742397,
    c2=183050801,s;
    unsigned int M=2<<(stepM-1),b1=maxof2(M,M-c1),b2=maxof2(M,M-c2);
	double ax1=a01,ax3,ax2=a02,V[K],a1[1200];
	cout<<"����������������� ������������ �����"<<endl;
	V[0]=a01;
    for (i=1;i<=n+K;i++)
    {
		ax1=drobmod(ax1*b1,M)/M;
		a1[i]=ax1;
		if(i<K)
			V[i]=ax1;
		else
			a1[i-K]=ax1;
		switch (i)
		{
		case 100:
			cout<<"100-� �������: "<<ax1<<endl;
				break;
		case 900:
			cout<<"900-� �������: "<<ax1<<endl;
				break;
		case 1000:
			cout<<"1000-� �������: "<<ax1<<endl;
				break;
		}
    }
	cout<<"����� ������������������"<<endl;
	for (i=1;i<=n;i++)
    {
		ax2=drobmod(ax2*b2,M)/M;
		s=ax2*K;
		ax3=V[s];
		V[s]=a1[i];
		switch (i)
		{
		case 100:
			cout<<"100-� �������: "<<ax3<<endl;
				break;
		case 900:
			cout<<"900-� �������: "<<ax3<<endl;
				break;
		case 1000:
			cout<<"1000-� �������: "<<ax3<<endl;
				break;
		}
    }
    system("pause");
}
