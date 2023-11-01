#include<iostream>
using namespace std;
class OX
{
	int n;
public:
	OX()
	{
		n=10;
		cout<<n<<endl;
	};
	OX(int x)
	{
		n=x;
		cout<<n<<endl;

	};
	/*OX(int x=0)
	{
	    n=x;
		cout<<n<<endl;

	};*/
OX operator =(OX a)
{
	this->n=a.n;
	return *this;
};
OX operator =(const OX& a)
{
	this->n=a.n;
	return *this;
};
OX operator =(const OX* a)
{
	this->n=a->n;
	return *this;
};
OX operator ++()
{
	this->n=;
	return *this;
}
friend OX operator +(OX a);

friend OX operator +(OX a);

friend OX operator +(OX a);


};
 OX operator +(OX a)
{
	this->n=a.n;
	return *this;
};
 OX operator +(OX a)
{
	this->n=a.n;
	return *this;
}
 OX operator (OX a)
{
	this->n=a.n;
	return *this;
}