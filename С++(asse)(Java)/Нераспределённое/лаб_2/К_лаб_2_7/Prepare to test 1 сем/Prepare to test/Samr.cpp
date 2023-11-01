#include <iostream>
#include "fun_h.h"
using namespace std;
void main()
{
	setlocale(LC_ALL,".1251");
	int *a=0,**b=0,k,n,i=1,m,*o,q=0,j,h;
	cin>>m;
	a=mass_dclr(a,m);
	mass_cel_rand4N(a,m);
	o=mass_dclr(0,m*4);
	for(j=0;j<m;j++)
	{
		//while (i!=-100)
			i=0;
			while (a[j]%celincelayastep(10,i)!=a[j])
			{
				o[q]=(a[j]%celincelayastep(10,i+1))/celincelayastep(10,i);
				i++;
				q++;
			}
	}
	bubble_srt(o,q);
	i=0;
	while (i!=-100)
		if (q+1>(i*i))
			i++;
		else 
			break;
	b=matr2_dclr(b,i,i);
	input_matr2_zer(b,i,i);
	vivodmassbig(a,m);
	vivodmass(o,q);
	a[0][0]=o[0];
	h=0;
	j=1
	while (j<m)
		if o[j]>o[0];
			a[][]
	vivodmatr2(b,i,i);
	system("pause");
}


	
	