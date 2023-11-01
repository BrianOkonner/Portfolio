#include <iostream>
#include <cstdio>
using namespace std;
/////////////////////////////////////////////
bool palindrom(int a)
{
int n=0;
int b=a;
while(b!=0) 
{	  
	n = n*10 + b%10;
	b = b/10;
}	
if(a==n)       
	return true;
else 
	return false;
}
//////////////////////////////////////////////
bool prostoe(int a)
{int t=1;
for(int i=2;(i<=sqrt(a*1.))&&(t==1);i++)
	if (a%i==0) t=0;
if (t==1)return true;
else return false;
}
//////////////////////////////////////////////