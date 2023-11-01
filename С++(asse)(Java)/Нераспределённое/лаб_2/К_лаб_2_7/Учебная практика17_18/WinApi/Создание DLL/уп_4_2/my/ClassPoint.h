#include <iostream>
using namespace std;
class ClassPoint
{
	
public:
	int x,y;
	ClassPoint();
	ClassPoint(int a,int b);// 2-х мерное пространство
	ClassPoint(const ClassPoint & p);
	friend istream & operator >> (istream &in,ClassPoint &z);
	friend ostream & operator << (ostream &out,ClassPoint &z);
	ClassPoint & operator ++();
	ClassPoint & operator ++(int);
	ClassPoint & operator =(const ClassPoint &z1);
	friend bool operator ==(const ClassPoint &z1,const ClassPoint &z2);
	friend bool operator !=(const ClassPoint &z1,const ClassPoint &z2);
	friend ClassPoint operator +(const ClassPoint &z1,const ClassPoint &z2);
	friend ClassPoint operator -(const ClassPoint &z1,const ClassPoint &z2);
	ClassPoint & operator +=(const ClassPoint & z1);
	ClassPoint & operator -=(const ClassPoint & z1);
	double length(const ClassPoint& p1);
	int GetX ();
	int GetY ();
};