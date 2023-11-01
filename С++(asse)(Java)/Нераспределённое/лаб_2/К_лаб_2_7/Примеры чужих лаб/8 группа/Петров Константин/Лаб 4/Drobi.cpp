/*
Петров Константин
8 группа
Лаб.4

Задание 2  Класс дробей.
Разработать интерфейс класса для обработки обычных дробей, заданными числителем и знаменателем.
Написать программу  для проверки  выполнения операций с обычными дробями.
*/

#include <iostream>
#include <fstream>
using namespace std;

int GCD(int a, int b) {
	a = abs(a);
	b = abs(b);
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}
int mypow(int a, int b) {
	return (b == 0) ? 1 : a*pow(a, b - 1);
}


class rFraction {
	int numerator;
	int denominator;
public:
	rFraction(int a = 1, int b = 1) : numerator(a), denominator(b) { Swap(); MyGCD(); }
	rFraction(const rFraction&);

	friend ostream& operator<<(ostream& out, const rFraction& A);
	friend istream& operator >> (istream& in, rFraction& A);


	rFraction operator -();

	rFraction operator++();
	rFraction operator++(int);
	rFraction operator--();
	rFraction operator--(int);

	rFraction operator += (rFraction);
	rFraction operator -= (rFraction);
	rFraction operator *= (rFraction);
	rFraction operator /= (rFraction);

	rFraction operator += (int);
	rFraction operator -= (int);
	rFraction operator *= (int);
	rFraction operator /= (int);

	friend rFraction operator +(rFraction, rFraction);
	friend rFraction operator -(rFraction, rFraction);
	friend rFraction operator *(rFraction, rFraction);
	friend rFraction operator /(rFraction, rFraction);

	friend rFraction operator +(int, rFraction);
	friend rFraction operator -(int, rFraction);
	friend rFraction operator *(int, rFraction);
	friend rFraction operator /(int, rFraction);
	friend rFraction operator +(rFraction, int);
	friend rFraction operator -(rFraction, int);
	friend rFraction operator *(rFraction, int);
	friend rFraction operator /(rFraction, int);

	bool operator >(rFraction);
	bool operator <(rFraction);
	bool operator ==(rFraction);
	bool operator !=(rFraction);
	bool operator >=(rFraction);
	bool operator <=(rFraction);

	bool operator >(int);
	bool operator <(int);
	bool operator ==(int);
	bool operator !=(int);
	bool operator >=(int);
	bool operator <=(int);

	rFraction operator () (int a) {		// a = a(3) // возведение в степень // за стабильность не отвечаю :)
		rFraction temp;
		temp.numerator = mypow(numerator, a);
		temp.denominator = mypow(denominator, a);
		return temp;
	}
	void Swap();
	void MyGCD();

};

rFraction::rFraction(const rFraction& A) {
	numerator = A.numerator;
	denominator = A.denominator;
	Swap();
}

ostream& operator<<(ostream& out, const rFraction& A) {
	if (A.denominator != 1)
		out << A.numerator << " / " << A.denominator;
	else
		out << A.numerator;
	return out;
}
istream& operator >> (istream& in, rFraction& A) {
	in >> A.numerator >> A.denominator;
	return in;
}

rFraction rFraction::operator -() {
	numerator = -1 * numerator;
	return *this;
}

rFraction rFraction::operator++() {
	numerator += denominator;
	return *this;
}
rFraction rFraction::operator++(int) {
	rFraction Copy(*this);
	numerator += denominator;
	return Copy;
}
rFraction rFraction::operator--() {
	numerator -= denominator;
	return *this;
}
rFraction rFraction::operator--(int) {
	rFraction Copy(*this);
	numerator -= denominator;
	return Copy;
}

rFraction rFraction::operator += (rFraction A) {
	numerator = numerator*A.denominator + denominator * A.numerator;
	denominator *= A.denominator;
	MyGCD();
	return *this;
}
rFraction rFraction::operator -= (rFraction A) {
	numerator = numerator*A.denominator - denominator * A.numerator;
	denominator *= A.denominator;
	MyGCD();
	return *this;
}
rFraction rFraction::operator *= (rFraction A) {
	numerator *= A.numerator;
	denominator *= A.denominator;
	MyGCD();
	return *this;
}
rFraction rFraction::operator /= (rFraction A) {
	numerator *= A.denominator;
	denominator *= A.numerator;
	MyGCD();
	return *this;
}

rFraction rFraction::operator+=(int val) {
	numerator += val * denominator;
	MyGCD();
	return *this;
}
rFraction rFraction::operator-=(int val) {
	numerator -= val * denominator;
	MyGCD();
	return *this;
}
rFraction rFraction::operator*=(int val) {
	numerator *= val;
	MyGCD();
	return *this;
}
rFraction rFraction::operator /=(int val) {
	denominator *= val;
	MyGCD();
	return *this;
}

rFraction operator +(rFraction A, rFraction B) {
	rFraction C(A);
	C += B;
	return C;
}
rFraction operator -(rFraction A, rFraction B) {
	rFraction C(A);
	C -= B;
	return C;
}
rFraction operator *(rFraction A, rFraction B) {
	rFraction C(A);
	C *= B;
	return C;
}
rFraction operator /(rFraction A, rFraction B) {
	rFraction C(A);
	C /= B;
	return C;
}

rFraction operator +(int val, rFraction A) {
	rFraction C = val;
	C += A;
	return C;
}
rFraction operator -(int val, rFraction A) {
	rFraction C = val;
	C -= A;
	return C;
}
rFraction operator *(int val, rFraction A) {
	rFraction C = val;
	C *= A;
	return C;
}
rFraction operator /(int val, rFraction A) {
	rFraction C = val;
	C /= A;
	return C;
}
rFraction operator +(rFraction A, int val) {
	rFraction C(A);
	C += val;
	return C;
}
rFraction operator -(rFraction A, int val) {
	rFraction C(A);
	C -= val;
	return C;
}
rFraction operator *(rFraction A, int val) {
	rFraction C(A);
	C *= val;
	return C;
}
rFraction operator /(rFraction A, int val) {
	rFraction C(A);
	C /= val;
	return C;
}

bool rFraction::operator >(rFraction A) {
	int a1 = numerator * A.denominator;
	int a2 = A.numerator * denominator;
	return (a1 > a2);
}
bool rFraction::operator <(rFraction A) {
	int a1 = numerator * A.denominator;
	int a2 = A.numerator * denominator;
	return (a1 < a2);
}
bool rFraction::operator ==(rFraction A) {
	int a1 = numerator * A.denominator;
	int a2 = A.numerator * denominator;
	return (a1 == a2);
}
bool rFraction::operator !=(rFraction A) {
	int a1 = numerator * A.denominator;
	int a2 = A.numerator * denominator;
	return (a1 != a2);
}
bool rFraction::operator >=(rFraction A) {
	int a1 = numerator * A.denominator;
	int a2 = A.numerator * denominator;
	return (a1 >= a2);
}
bool rFraction::operator <=(rFraction A) {
	int a1 = numerator * A.denominator;
	int a2 = A.numerator * denominator;
	return (a1 <= a2);
}

bool rFraction::operator >(int val) {
	rFraction B = val;
	return (*this > B);
}
bool rFraction::operator <(int val) {
	rFraction B = val;
	return (*this < B);
}
bool rFraction::operator ==(int val) {
	rFraction B = val;
	return (*this == B);
}
bool rFraction::operator !=(int val) {
	rFraction B = val;
	return (*this != B);
}
bool rFraction::operator >=(int val) {
	rFraction B = val;
	return (*this >= B);
}
bool rFraction::operator <=(int val) {
	rFraction B = val;
	return (*this <= B);
}
void rFraction::Swap(){
	if (denominator < 0)
	{
		numerator = -1 * numerator;
		denominator = -1 * denominator;
	}
}
void rFraction::MyGCD(){
	int E = GCD(numerator, denominator);
	numerator /= E;
	denominator /= E;
}

int main() {
	rFraction a(3, -2), b(3, 4), q(2, 3);
	
	system("pause");
	return 0;
}

