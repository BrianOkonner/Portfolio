#include <iostream>
#include <fstream>
using namespace std;

int MyPow(int a, int b);

class Drobi {
	int chisl;
	int znam;
public:
	Drobi(int a = 1, int b = 1) : chisl(a), znam(b) 
	{ 
		Minus_swap(); 
		Euclid(); 
	}
	Drobi(const Drobi&);

	friend ostream& operator<< (ostream& out, const Drobi& A);
	friend istream& operator>> (istream& in, Drobi& A);


	Drobi operator -();

	Drobi operator++();
	Drobi operator++(int);
	Drobi operator--();
	Drobi operator--(int);

	Drobi operator += (Drobi);
	Drobi operator -= (Drobi);
	Drobi operator *= (Drobi);
	Drobi operator /= (Drobi);

	Drobi operator += (int);
	Drobi operator -= (int);
	Drobi operator *= (int);
	Drobi operator /= (int);

	friend Drobi operator +(Drobi, Drobi);
	friend Drobi operator -(Drobi, Drobi);
	friend Drobi operator *(Drobi, Drobi);
	friend Drobi operator /(Drobi, Drobi);

	friend Drobi operator +(int, Drobi);
	friend Drobi operator -(int, Drobi);
	friend Drobi operator *(int, Drobi);
	friend Drobi operator /(int, Drobi);
	friend Drobi operator +(Drobi, int);
	friend Drobi operator -(Drobi, int);
	friend Drobi operator *(Drobi, int);
	friend Drobi operator /(Drobi, int);

	bool operator >(Drobi&);
	bool operator <(Drobi&);
	bool operator ==(Drobi&);
	bool operator !=(Drobi&);
	bool operator >=(Drobi&);
	bool operator <=(Drobi&);

	bool operator >(int);
	bool operator <(int);
	bool operator ==(int);
	bool operator !=(int);
	bool operator >=(int);
	bool operator <=(int);

	Drobi operator () (int a);
	void Minus_swap();
	void Euclid();

};