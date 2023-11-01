/*
Петров Константин
8 группа
Лаб 5
Задание 2. Класс полином.
*/

/*	На ошибке с памятью нажать ПРОПУСТИТЬ	*/

#include <iostream>
#include<stdlib.h>
using namespace std;

double MyPow(double a, int b) {
	return (b == 0) ? 1 : a * MyPow(a, b - 1);
}

class PolynomExceptions :public exception {
private:
	int DataState;
public:
	PolynomExceptions(const char* msg, int DataState) :exception(msg) {
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

	// Алгоритм на выбор :)

	/*for (int i = 0; i <= A.n + B.n; i++)
	for (int j = 0; j <= A.n; j++)
	for (int k = 0; k <= B.n; k++) {
	if (j + k == i)
	C[i] += (A[j] * B[k]);
	}
	*/

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
	return C;
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

int main() {
	try {
		Polynom a(1., 1., 2.), b(1., 1., 2.);
		a = (b * 2 * b / 3);
		a.DisplayCoeff();
		cout << endl;
		system("pause");
	}
	catch (PolynomExceptions &exc) {
		cout << exc.what() << endl;
		cout << exc.GetDataState() << endl;
	}
	system("pause");
	return 0;
}


