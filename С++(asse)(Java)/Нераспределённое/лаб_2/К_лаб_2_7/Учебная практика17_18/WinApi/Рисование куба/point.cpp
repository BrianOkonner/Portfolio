#include"point.h"
#include <iostream>
using namespace std;
Point::Point(int x1,int y1)
{
	x=x1; y=y1;
}

Point::Point(const Point& p)
{
	x=p.x;  y=p.y;
}

Point& Point::operator=(const Point& p)
{
	if(this!=&p)
	{
		x=p.x;  y=p.y;
	}
	return *this;
}

Point Point::operator-(const Point& p)
{
	Point res;
	res.x=x-p.x;  res.y=y-p.y;
	return res;
}

Point& Point::operator+(int i)
{
	x+=i;  y+=i;
	return *this;
}

Point& Point::operator+=(const Point& p)
{
	x+=p.x;  y+=p.y;
	return *this;
}

bool operator>(const Point& p,int i)
{
	if((p.x>i)&&(p.y<i))
		return true;
	return false;
}

bool operator<(const Point& p,int i)
{
	if((p.x<i)&&(p.y>i))
		return true;
	return false;
}