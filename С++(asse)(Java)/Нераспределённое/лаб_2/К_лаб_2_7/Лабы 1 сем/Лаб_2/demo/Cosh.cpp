

# include <iostream>
# include <math.h>
using namespace std;
void main ()
{ 
	double n,p,y1,y2,x,e;

	cout<<"x=";cin>>x;
	cout<<"e=";cin>>e;
	
	y1=(exp(x)+exp(-x))/2;

	p=1;
	y2=1; n=1;
while ( fabs(p)>=e)
{
	p=p*x*x/(n*(n+1));
	n+=2; 
	y2+=p;
}

		
	cout<<"standart="<<y1<<"   my="<<y2<<endl;
	
}
