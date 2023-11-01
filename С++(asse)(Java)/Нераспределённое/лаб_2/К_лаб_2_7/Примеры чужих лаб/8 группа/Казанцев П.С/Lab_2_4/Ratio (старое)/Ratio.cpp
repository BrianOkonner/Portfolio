#include "Ratio.h"

Ratio::Ratio() :chisl(1), znam(1) {}

Ratio::Ratio(int a, int b) : chisl(a), znam(b) {}

Ratio::Ratio(const Ratio& A) {
	chisl = A.chisl;
	znam = A.znam;
}
Ratio::~Ratio() {}
ostream& operator <<(ostream& out, const Ratio& A) {
	out << A.chisl << " / " << A.znam;
	return out;
}
istream& operator >> (istream& is, Ratio& A) {
	is >> A.chisl >> A.znam;
	return is;
}
bool Ratio::operator <(const Ratio A) {
	return (this->chisl * A.znam < A.chisl * this->znam);
}
bool Ratio::operator >(const Ratio A) {
	return (this->chisl * A.znam > A.chisl * this->znam);
}
Ratio& Ratio::operator +=(const Ratio& A) {
	chisl = chisl * A.znam + znam * A.chisl;
	znam *= A.znam;

	int a = fabs(chisl), b = fabs(znam);
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	chisl /= a;
	znam /= a;
	if (znam < 0)
	{
		znam *= -1;
		chisl *= -1;
	}
	return *this;
}
Ratio& Ratio::operator -=(const Ratio& A) {
	chisl = chisl * A.znam - znam * A.chisl;
	znam *= A.znam;

	int a = fabs(chisl), b = fabs(znam);
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}

	chisl /= a;
	znam /= a;
	if (znam < 0)
	{
		znam *= -1;
		chisl *= -1;
	}
	return *this;
}
Ratio& Ratio::operator *=(const Ratio& A) {
	chisl *= A.chisl;
	znam *= A.znam;

	int a = fabs(chisl), b = fabs(znam);
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}

	chisl /= a;
	znam /= a;
	if (znam < 0)
	{
		znam *= -1;
		chisl *= -1;
	}
	return *this;
}
Ratio& Ratio::operator /=(const Ratio& A) {
	int temp1 = A.chisl, temp2 = A.znam;

	chisl *= temp2;
	znam *= temp1;

	int a = fabs(chisl), b = fabs(znam);
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}

	chisl /= a;
	znam /= a;
	if (znam < 0)
	{
		znam *= -1;
		chisl *= -1;
	}
	return *this;
}
Ratio Ratio::operator ++() {
	chisl += znam;
	return *this;
}
Ratio Ratio::operator ++(int) {
	const Ratio temp(*this);
	chisl += znam;
	return temp;
}
Ratio Ratio::operator --() {
	chisl -= znam;
	return *this;
}
Ratio Ratio::operator --(int) {
	Ratio temp(*this);
	chisl -= znam;
	return temp;
}
Ratio& Ratio::operator =(const Ratio& A) {
	chisl = A.chisl;
	znam = A.znam;
	return *this;
}
Ratio Ratio::operator -() {
	chisl = -chisl;
	return *this;
}
Ratio operator *(const Ratio& A, const Ratio& B) {
	return Ratio(A) *= B;
}
Ratio operator /(const Ratio& A, const Ratio& B) {
	return Ratio(A) /= B;
}
Ratio operator +(const Ratio& A, const Ratio& B) {
	return Ratio(A) +=B;
}
Ratio operator -(const Ratio& A, const Ratio& B) {
	return Ratio(A) -= B;
}
