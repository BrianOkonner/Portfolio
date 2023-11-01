#include <math.h>
const double pi=3.14159265,e=2.71828182846;

double celayastep(double a,int b)
{
	double r=1,i;
	for(i=1;i<=b;i++)
		r=r*a;
	return r;
}
double tanH(int x)
{
	double h=1,k;
	h=pow(e,x);
	k=(h-(1/h))/(h+(1/h));//Гиперболический тангенс HTan(X) = (Exp(X) - Exp(-X)) / (Exp(X) + Exp(-X))
	return k;
}
unsigned _int64 facial(int n)
{
	int a,b=1;
	if (n==0)
		return 0;
	for (a=1;a<=n;a++)
		b=b*a;
	return b;
}
double estepx(double x,int o)
{
	double h=1,s=1; int k;
	for(k=1;k<=o;k++)
		s=s+(celayastep(x,k)/facial(k));
	return s;
}
double tanH(double x,int o)
{
	double h=1,k,i,j;
	h=estepx(x,o);
	j=1/h;
	k=(h-(j))/(h+(j));//Гиперболический тангенс HTan(X) = (Exp(X) - Exp(-X)) / (Exp(X) + Exp(-X))
	return k;
}
long double tanH(double x,unsigned _int64 o)
{
	double h=1,k,i,j;
	h=estepx(x,o);
	j=1/h;
	k=(h-(j))/(h+(j));//Гиперболический тангенс HTan(X) = (Exp(X) - Exp(-X)) / (Exp(X) + Exp(-X))
	return k;
}

