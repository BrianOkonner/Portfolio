#include <iostream>
#include <iomanip>
#include "fun_h.h"
#include <ctime>
using namespace std;
void main()
{
	int x,y=8,z=2; double o=4.365851;
	setlocale(LC_ALL,".1251");
	x=cmp_int(&y,&z);
	cout<<x;
/*	int *a,n,i=0;
	a=new int[101];
	unsigned int clk;
	setlocale(LC_ALL,".1251");
	cout<<"¬ведите n (n<=100): ";
	cin>>n;
	mass_from_file(a,n);*/
    /*while(true)
	{c++; if(c>10) break;}
	cout<<"jyj  "<<c;*/
	system("pause");
}
