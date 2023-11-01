#include <iostream>
#include  <iomanip>
#include  <math.h>
using namespace std;
void main()
{
	int m,n,h,a,b;
	double s,e=0.00001,x,p,s1,s2,s3,func,pi=3.14;

	x=100.;
	while ((x>=2*pi) || (x<0))
 //   {учитывается период}
	{
		if (x<0)    x=x+2*pi;
           else    x=x-2*pi;
		//   cout<<x<<endl;	
	}  
	cout<<x<<endl;	
   p=x;   s=x;   n=1;
    while (fabs(p)>=e)
	{
            p=(-p*x*x)/(2*n*(2*n+1));
            s=s+p;
	    n=n+1;
		cout<<p<<endl;
	}
    cout<<"sinx="<<sin(x)<<" s="<<s<<endl;
	}