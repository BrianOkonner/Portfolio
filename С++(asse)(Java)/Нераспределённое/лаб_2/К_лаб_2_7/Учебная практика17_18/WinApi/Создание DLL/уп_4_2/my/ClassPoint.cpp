#include <iostream>
#include <cmath>
#include "ClassPoint.h"
using namespace std;
ClassPoint::ClassPoint()
{
	x=0;
	y=0;
	
}
ClassPoint::ClassPoint(int a,int b)
{
	x=a;
	y=b;
}
ClassPoint::ClassPoint(const ClassPoint & p)
{
	x=p.x;
	y=p.y;
}
istream & operator >> (istream &in,ClassPoint &z)
{
	in>>z.x>>z.y;
	return in;

}
ostream & operator << (ostream &out,ClassPoint &z)
{
	out<<" x= "<<z.x<<" y= "<<z.y;
	return out;
}
ClassPoint & ClassPoint::operator =(const ClassPoint &z1)
{
	x=z1.x;
	y=z1.y;
	return *this;
}
bool operator ==(const ClassPoint &z1,const ClassPoint &z2)
{
	if ((z1.x == z2.x)&&(z1.y == z2.y))
		return true;
	else 
		return false;
}
bool operator !=(const ClassPoint &z1,const ClassPoint &z2)
{
	if ((z1.x == z2.x)&&(z1.y == z2.y))
		return false;
	else 
		return true;;
}
ClassPoint operator +(const ClassPoint &z1,const ClassPoint &z2)
{
	ClassPoint p;
	p.x=z1.x+z2.x;
	p.y=z1.y+z2.y;
	return p;
}
ClassPoint operator -(const ClassPoint &z1,const ClassPoint &z2)
{
	ClassPoint p;
	p.x=z1.x-z2.x;
	p.y=z1.y-z2.y;
	return p;
}
ClassPoint & ClassPoint::operator +=(const ClassPoint & z1)
{
	x+=z1.x;
	y+=z1.y;
	return *this;
}
ClassPoint & ClassPoint::operator -=(const ClassPoint & z1)
{
	x-=z1.x;
	y-=z1.y;
	return *this;
}
double ClassPoint::length(const ClassPoint& p1)
{
	return sqrt((double)(p1.x-x)*(p1.x-x) + (p1.y-y)*(p1.y-y));
}
int ClassPoint::GetX ()
{
	return x;
}
int ClassPoint::GetY ()
{
	return y;
}

ClassPoint &ClassPoint::operator ++(int)
{
	x+=1;
	y+=1;
	return ClassPoint(x-1,y-1);
}

ClassPoint& ClassPoint::operator ++()
{
	x+=1;
	y+=1;
	return *this;
}