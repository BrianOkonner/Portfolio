#pragma once
#include <iostream>
using namespace std;

class Ratio {
	int chisl;
	int znam;
public:
	Ratio();
	Ratio(int, int);
	Ratio(const Ratio &A);
	~Ratio();

	Ratio operator ++();
	Ratio operator ++(int);
	Ratio operator --();
	Ratio operator --(int);

	Ratio& operator = (const Ratio& A);
	Ratio operator - ();

	Ratio& operator +=(const Ratio &A);
	Ratio& operator -=(const Ratio &A);
	Ratio& operator *=(const Ratio &A);
	Ratio& operator /=(const Ratio &A);

	friend Ratio operator +(const Ratio &A, const Ratio& B);
	friend Ratio operator -(const Ratio &A, const Ratio& B);
	friend Ratio operator *(const Ratio &A, const Ratio& B);
	friend Ratio operator /(const Ratio &A, const Ratio& B);

	friend ostream& operator << (ostream& out, const Ratio& A);
	friend istream& operator >> (istream& is, Ratio& A);

	bool operator < (const Ratio A);
	bool operator > (const Ratio A);
};

