#include <iostream>
#include "ClassPoint.h"
using namespace std;
class ClassPolygon: public ClassPoint
{
	ClassPoint *A;
	int count;
public:
	ClassPolygon();
	ClassPolygon(int _n,...);
	ClassPolygon(const ClassPolygon& p);
	int GetCount();
	ClassPoint& operator [](const int& Index);
	friend istream& operator>>(istream &in,ClassPolygon &p);
	friend ostream& operator <<(ostream *out,const ClassPolygon &p);
};