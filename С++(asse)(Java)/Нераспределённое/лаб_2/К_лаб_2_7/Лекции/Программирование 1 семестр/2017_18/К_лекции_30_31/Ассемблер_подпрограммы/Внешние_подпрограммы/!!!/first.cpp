//Maiseyonok Alexei group8
//8.Вычислит   S=sum((1+arctg(hx))*(cos(2nx))/(1+n^3))при заданном m,если  х изменяется от a до b с шагом h. 
//Результаты получить в виде таблицы. 

#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
extern "C" double __cdecl Cosin(double);
extern "C" double __cdecl Cosinasm(double);

double Count (double x, double m)
{
 double n,s=0;
 for(n=1;n<=m;n++)
s+=(1+atan((double) x))/(1+n*n*n);
 return s;
}
void main()
{
	double x,m,i,k,a,z=1,b,f,h,r,j,sa;
	cout<<"Vvedite znachenie a, b, h, m:";
cin>>a>>b>>h>>m;

if (h<=0)
{
cout<<"\n\n Oshibka !!!!!!!!!!!!  shag (H) vveden ne verno\n";
return;
	}
	cout<< "  -----------------------------------------------------------------------------\n" ;
	cout<< "  | Znachenie peremennoj X |       Summa          | Znachenie s pomoschju Cos |\n" ;	
	cout<< "  -----------------------------------------------------------------------------\n" ;

	
	j=0;
	r=0;
	f=0;
	if (a<=b)
		for (x=a;x<=b;x+=h)
		{
			 sa=2*x;
		 i=Cosin(sa);
		 r=Count(x,m);
		 f+=r*i;
		 sa=Cosinasm(sa);
		 j+=r*sa;
		 	 cout<<"  |         "<<x<<'\t'<<"           |      "<<f<<'\t'<<"    |        "<<j<<"         |\n";
			 cout<< "  -----------------------------------------------------------------------------\n" ;
		
		}
	else 
	     for (x=a;x>=b;x-=h)
		 {
	 sa=2*x;
		 i=Cosin(sa);
		 r=Count(x,m);
		 f+=r*i;
		 sa=Cosinasm(sa);
		 j+=r*sa;
		 	 cout<<"|"<<x<<'\t'<<"|"<<f<<'\t'<<"|"<<j<<"|\n";
			 cout<< "  -------------------------------------------------------------------------------\n" ;
		}

}
