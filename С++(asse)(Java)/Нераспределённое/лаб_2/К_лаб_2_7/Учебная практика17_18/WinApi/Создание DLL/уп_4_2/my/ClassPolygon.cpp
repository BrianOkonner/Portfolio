#include <iostream>
#include <stdarg.h>
#include "ClassPolygon.h"
using namespace std;
ClassPolygon::ClassPolygon()
{
	A=NULL;
	count=0;
}
ClassPolygon::ClassPolygon(int _n,...)
	{
		
		va_list vl;
		va_start(vl,_n);
		

		count=_n;
		A=new ClassPoint[count];
		for(int i=0;i<count;i++)
		{
			A[i]=va_arg(vl,ClassPoint);
		}

		va_end(vl);
	}
int ClassPolygon::GetCount()
{
	return count;
}
ClassPoint& ClassPolygon::operator [](const int& Index)
{
	return A[Index];
}
istream& operator>>(istream &in,ClassPolygon &p)
{
	if (p.count==0)
	{
		in>>p.count;
		
		p.A=new ClassPoint [p.count];
		for (int i=0;i<p.count;i++)
			in>>p.A[i];
	}
	else
	{
		delete []p.A;
		in>>p.count;
		p.A=new ClassPoint [p.count];
		for (int i=0;i<p.count;i++)
			in>>p.A[i];
	}
	return in;
}
ostream& operator <<(ostream &out,const ClassPolygon &p)
{
	return out;
}