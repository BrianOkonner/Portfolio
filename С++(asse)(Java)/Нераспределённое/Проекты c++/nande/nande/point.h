#include <fstream>
#include <iostream>
using namespace std;
class point
{
	double x;
	double y;
	double z;
public:
	point(double i,double j,double k);
	point(const  point&);
	~point();
	point operator +();
	point operator -();
	point operator *(double);
	point operator /(double);
	point operator ++();
	point operator ++(int);
	point operator --();
	point operator --(int);
	point operator =(point);
	bool operator ==(point);
	bool operator !=(point);
	bool operator >=(point);
	bool operator <=(point);
	bool operator >(point);
	bool operator <(point);
	friend point operator +(point,point);
	friend point operator -(point,point);
	friend point operator *(point,point);
	friend point operator==(point,point);
	friend ostream& operator <<(ostream&,point);
	friend istream& operator>>(istream&,point&);
};