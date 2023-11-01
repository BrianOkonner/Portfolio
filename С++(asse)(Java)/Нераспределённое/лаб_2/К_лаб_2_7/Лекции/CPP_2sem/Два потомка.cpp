#include <iostream>
using namespace std;
class F
{
protected:
	double x1,y1,x2,y2;
public:
	F()
	{
		x1=0; y1=0; x2=100; y2=100;
	}

	F(double X1, double Y1, double X2, double Y2)
	{
		x1=X1; y1=Y1; x2=X2; y2=Y2;
	}
	virtual double sq() 
	{
		return 0;
	}

};
class R:public F
{
	double w,h;
public:
	R(double w1, double h1):F()
	{
		w=w1; h=h1;
	}
	virtual double sq()
	{  
		return w*h;
	}

};
class C:public F
{
	double Rad;
public:
	C(double Rad1):F()
	{
		Rad=Rad1;
	}
	virtual double sq()
	{  
		return 3.1415*Rad*Rad;
	}

};
int main()
{
	F* f[10];
	f[0]= new R(2,4);
	f[1]= new R(3,5);
	f[2]= new C(3);
	f[3]= new R(20,40);
	f[4]= new F(1,1,2,2);
	for(int i=0; i<5; i++)
		cout<<f[i]->sq()<<endl;
}