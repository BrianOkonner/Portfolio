#include<iostream>

using namespace std;

class OX
{
	int n;
public:
	OX();
	OX(int x);
	OX &operator =(OX a);
	OX& operator +=(const OX& a);
	OX& operator -=(const OX* a);
	OX& operator *=(const OX* a);
	OX& operator /=(const OX* a);
	OX operator ++();
	friend OX operator +(OX a, OX b);
	friend OX operator -(OX a, OX b);
	friend OX operator *(OX a, OX b);
	friend OX operator /(OX a, OX b);
	friend ostream& operator <<(ostream &out, OX &a);
	friend istream& operator >>(istream &in, OX &a);
};
