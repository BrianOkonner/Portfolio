#pragma once

#include <iostream>
#include<stdlib.h>
using namespace std;

double MyPow(double a, int b);

class PolynomExceptions :public exception {
private:
	int DataState;
public:
	PolynomExceptions(char *msg, int DataState) :exception(msg) {
		this->DataState = DataState;
	}
	int GetDataState() { return DataState; }
};

class Polynom {
	int		n;
	double*	coeff;
public:
	Polynom();
	Polynom(double _n...);
	Polynom(const Polynom&);
	~Polynom();

	double Value(double);
	double& operator [](int i) const;
	Polynom& operator = (const Polynom&);
	Polynom operator += (const Polynom&);
	Polynom operator -= (const Polynom&);
	Polynom operator *= (const Polynom&);
	Polynom operator /= (const Polynom&);																											// throw(Zero_divide)											
	Polynom operator -();
	Polynom operator +();

	friend Polynom operator + (const Polynom&, const Polynom&);
	friend Polynom operator - (const Polynom&, const Polynom&);
	friend Polynom operator * (const Polynom&, const Polynom&);
	friend Polynom operator / (const Polynom&, const Polynom&);

	Polynom operator +=(int);
	Polynom operator -=(int);
	Polynom operator *=(int);
	Polynom operator /=(int);

	friend Polynom operator +(int, const Polynom&);
	friend Polynom operator -(int, const Polynom&);
	friend Polynom operator *(int, const Polynom&);

	friend Polynom operator +(const Polynom&, int);
	friend Polynom operator -(const Polynom&, int);
	friend Polynom operator *(const Polynom&, int);
	friend Polynom operator /(const Polynom&, int);

	void DisplayCoeff();
	int GetDegree() { return n; }
	void pRealloc(int);
};