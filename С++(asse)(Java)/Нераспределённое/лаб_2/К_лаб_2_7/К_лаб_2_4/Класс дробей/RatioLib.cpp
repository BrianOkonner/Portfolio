// Реализация функций-членов класса

#include <stdio.h>
#include "ratio.h"
#include <math.h>
#include <string.h>
ratio& ratio::operator ++()
{	
	n += d;
	return *this;
}
	ratio& ratio::operator ++(int x)
	{
	n += d;
	return *this;
	}

void ratio::Reduce()
{	long x,y;
	x=abs(n);
	y=abs(d);
	if (d==0) 
		throw Zero_divide();
	if (n==0) 
		d=1;
	else
	{
	while (x!=y)
		if (x>y) x-=y;
		else y-=x;
	n/=x;
	d/=x;}
}

ratio::ratio()
{	n=0;
	d=1;
}

ratio::ratio(long x,long y)
{	n=x;
    d=y;
	Reduce();
}

ratio::ratio(const ratio& r)
{	n=r.n;
	d=r.d;
}

ratio&ratio::operator =(const ratio& r)
{	if (&r==this)
		return *this;
	n=r.n;
	d=r.d;
	return *this;
}

ratio&ratio::operator +=(const ratio& r)
{	n=r.n*d+n*r.d;
	d*=r.d;
	Reduce();
	return *this;
}
	
ratio&ratio::operator -=(const ratio& r)
{	n=n*r.d-r.n*d;
	d*=r.d;
	Reduce();
	return *this;
}

ratio&ratio::operator *=(const ratio& r)
{	n*=r.n;
	d*=r.d;
	Reduce();
	return *this;
}	

ratio&ratio::operator /=(const ratio& r)
{	n*=r.d;
	d*=r.n;
	Reduce();
	return *this;
}

istream&	operator>>(istream&  in, ratio&  r)
{
	in >>r.n>>r.d;
	if (r.d==0) 
		throw Zero_divide();
	return in;
}
ostream&	operator<<(ostream&  out, const ratio&  r)
{	
	return  out <<r.n<<"/"<<r.d;
}

ratio::operator double(void) const
{	return 1.0*n/d;
} 

ratio  operator -(const ratio &r)
{	ratio Lamo;
    Lamo.d=r.d;
	Lamo.n=-r.n;
	return Lamo;
}
ratio operator +(const ratio &r)
{ return r;
}

ratio operator + (const ratio& r1, const ratio& r2)
{	ratio temp=r1;
	temp+=r2;
	return temp;
}
ratio operator + (const ratio& r1, int x)
{	ratio temp;
	temp.n=r1.n+x*r1.d;
	temp.d=r1.d;
	return temp;
}

ratio operator + (int x,const ratio& r1)
		{
			return r1+x;
		}
	
ratio operator - (const ratio& r1, const ratio& r2)
{	ratio temp=r1;
	temp-=r2;
	return temp;
}

ratio operator * (const ratio& r1, const ratio& r2)
{	ratio temp=r1;
	temp*=r2;
	return temp;
}

ratio operator / (const ratio& r1, const ratio& r2)
{	ratio temp=r1;
	temp/=r2;
	return temp;
}

bool operator 	< (const ratio& r1, const ratio& r2)
{	ratio temp=r1;
	temp-=r2;
	if (temp.n<0)
	return true;
	return false;
}

bool operator 	> (const ratio& r1, const ratio& r2)
{	ratio temp=r1;
	temp-=r2;
	if (temp.n>0)
	return true;
	return false;
}

bool operator 	== (const ratio& r1, const ratio& r2)
{	ratio temp=r1;
	temp-=r2;
	if (temp.n==0)
	return true;
	return false;
}
	
bool operator 	!= (const ratio& r1, const ratio& r2)
{	ratio temp=r1;
	temp-=r2;
	if (temp.n!=0)
	return true;
	return false;
}
