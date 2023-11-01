#include "Header.h"

double MyPow(double a, int b) {
	return (b == 0) ? 1 : a*MyPow(a, b - 1);
}


Polynom::Polynom() :n(0) {
	coeff = (double*)malloc(8);
	coeff[0] = 0;
}
Polynom::Polynom(double _n...) : n((int)_n) {
	if (_n < 0)
		throw PolynomExceptions("NegativeDegree", _n);
	coeff = (double*)malloc((_n + 1) * 8);
	double *p = &_n;
	p++;
	double *pp = (double*)p;
	int i = 0, copy = _n;
	copy++;
	for (; copy--; pp++, i++)
		coeff[i] = (*pp);
}
Polynom::Polynom(const Polynom& A) :n(A.n) {
	coeff = (double*)malloc((n + 1) * 8);
	for (int i = 0; i < n + 1; i++)
		coeff[i] = A.coeff[i];
}
Polynom::~Polynom() {
	coeff = (double*)realloc(coeff, 0);
}

double Polynom::Value(double a) {
	double val = coeff[0];
	for (int i = 1; i < n + 1; i++)
		val += coeff[i] * MyPow(a, i);
	return val;
}
double& Polynom::operator[](int i)const {
	if (i > n || i < 0) throw PolynomExceptions("Out of range", i);
	return coeff[i];
}
Polynom& Polynom::operator=(const Polynom& A) {
	if (n != A.n)
		this->pRealloc(A.n);
	for (int i = 0; i < n + 1; i++)
		coeff[i] = A.coeff[i];

	return *this;
}

Polynom Polynom::operator-() {
	for (int i = 0; i < n + 1; i++)
		coeff[i] = -1 * coeff[i];
	return *this;
}
Polynom Polynom::operator+() {
	return *this;
}
Polynom Polynom::operator +=(const Polynom& A) {
	//Описание смотри ниже ))
	if (A.n > n) {

		this->pRealloc(A.n);

		for (int i = 0; i < n + 1; i++)
			coeff[i] += A.coeff[i];
	}
	else {
		for (int i = 0; i < A.n + 1; i++)
			coeff[i] += A.coeff[i];
	}
	return *this;
}
Polynom Polynom::operator -=(const Polynom& A) {
	if (A.n > n) {
		this->pRealloc(A.n);						//Довыделение памяти

		for (int i = 0; i < n + 1; i++)				// Само вычитание
			coeff[i] -= A.coeff[i];
	}
	else {
		for (int i = 0; i < A.n + 1; i++)
			coeff[i] -= A.coeff[i];
	}
	return *this;
}
Polynom Polynom::operator *=(const Polynom& A) {
	this[0] = this[0] * A;
	return *this;
}
Polynom Polynom::operator /=(const Polynom& A) {
	if (A.n > n) {

		this->pRealloc(A.n);

		for (int i = 0; i < n + 1; i++) {
			if (A.coeff[i] == 0) throw PolynomExceptions("Devision by zero", i);
			coeff[i] /= A.coeff[i];
		}
	}
	else {
		for (int i = 0; i < A.n + 1; i++) {
			if (A.coeff[i] == 0) throw PolynomExceptions("Devision by zero", i);
			coeff[i] /= A.coeff[i];
		}
	}
	return *this;
}

Polynom operator +(const Polynom& A, const Polynom& B) {
	Polynom C(A);
	C += B;
	return C;
}
Polynom operator -(const Polynom& A, const Polynom& B) {
	Polynom C(A);
	C -= B;
	return C;
}
Polynom operator *(const Polynom& A, const Polynom& B) {
	Polynom C;
	C.pRealloc(A.n + B.n);
	for (int i = 0; i <= A.n; ++i) {
		for (int j = 0; j <= B.n; ++j) {
			C[i + j] += A[i] * B[j];
		}
	}
	return C;
}
Polynom operator /(const Polynom& A, const Polynom& B) {
	Polynom C(A);
	C /= B;
	return C;
}

Polynom Polynom::operator +=(int a) {
	coeff[0] += a;
	return *this;
}
Polynom Polynom::operator -=(int a) {
	coeff[0] -= a;
	return *this;
}
Polynom Polynom::operator *= (int a) {
	for (int i = 0; i <= n; i++)
		coeff[i] *= a;
	return *this;
}
Polynom Polynom::operator /= (int a) {
	if (a == 0) throw PolynomExceptions("Division by zero", a);
	for (int i = 0; i <= n; i++)
		coeff[i] /= a;
	return *this;
}

Polynom operator +(int a, const Polynom& A) {
	Polynom C(A);
	C.coeff[0] += a;
	return C;
}
Polynom operator -(int a, const Polynom& A) {
	Polynom C(A);
	C = -C;
	C.coeff[0] += a;
	return C;
}
Polynom operator *(int a, const Polynom& A) {
	Polynom C(A);
	C *= a;
	return C;
}

Polynom operator +(const Polynom& A, int a) {
	Polynom C(A);
	C.coeff[0] += a;
	return C;
}
Polynom operator -(const Polynom& A, int a) {
	Polynom C(A);
	C.coeff[0] -= a;
}
Polynom operator *(const Polynom& A, int a) {
	Polynom C(A);
	C *= a;
	return C;
}
Polynom operator /(const Polynom& A, int a) {
	Polynom C(A);
	C /= a;
	return C;
}


void Polynom::DisplayCoeff() {
	for (int i = 0; i < n + 1; i++)
		cout << this[0][i] << " ";
}
void Polynom::pRealloc(int a) {
	double* copy;
	copy = new double[n + 1];						 //Запоминание коэфф.
	int count = n + 1;
	for (int i = 0; i < n + 1; i++)
		copy[i] = coeff[i];

	coeff = (double*)realloc(coeff, 0);				//Довыделение памяти
	coeff = (double*)realloc(coeff, a * 8);
	n = a;
	for (int i = 0; i < n + 1; i++)					//Восстановление и заполнение новых нулями
		coeff[i] = 0;
	for (int i = 0; i < count; i++)
		coeff[i] = copy[i];
}
