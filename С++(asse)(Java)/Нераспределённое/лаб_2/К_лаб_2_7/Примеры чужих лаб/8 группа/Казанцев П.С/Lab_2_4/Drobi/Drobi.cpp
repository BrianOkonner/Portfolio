#include "Drobi.h"

int GCD(int a, int b) 
{
	a = abs(a);
	b = abs(b);
	return b ? GCD(b, a%b) : a;
}

int MyPow(int a, int n)
{
	int res = 1;
	if (!n) 
		return 1;
	while (n)
	{
		if (n % 2 == 0)
		{
			n /= 2;
			a *= a;
		}
		else
		{
			n--;
			res *= a;
		}
	}
	return res;
}

Drobi::Drobi(const Drobi& A) {
	chisl = A.chisl;
	znam = A.znam;
	Minus_swap();
}

ostream& operator<<(ostream& out, const Drobi& A) {
	if (A.znam != 1)
		out << A.chisl << " / " << A.znam;
	else
		out << A.chisl;
	return out;
 }
istream& operator >> (istream& in, Drobi& A) {
	in >> A.chisl >> A.znam;
	return in;
 }

Drobi Drobi::operator -() {
	chisl = -1 * chisl;
	return *this;
}

Drobi Drobi::operator++() {
	chisl += znam;
	return *this;
}
Drobi Drobi::operator++(int) {
	Drobi temp(*this);
	chisl += znam;
	return temp;
}
Drobi Drobi::operator--() {
	chisl -= znam;
	return *this;
}
Drobi Drobi::operator--(int) {
	Drobi temp(*this);
	chisl -= znam;
	return temp;
}

Drobi Drobi::operator += (Drobi A) {
	chisl = chisl*A.znam + znam * A.chisl;
	znam *= A.znam;
	Euclid();
	return *this;
}
Drobi Drobi::operator -= (Drobi A) {
	chisl = chisl*A.znam - znam * A.chisl;
	znam *= A.znam;
	Euclid();
	return *this;
}
Drobi Drobi::operator *= (Drobi A) {
	chisl *= A.chisl;
	znam *= A.znam;
	Euclid();
	return *this;
}
Drobi Drobi::operator /= (Drobi A) {
	chisl *= A.znam;
	znam *= A.chisl;
	Euclid();
	return *this;
}

Drobi Drobi::operator+=(int operand) {
	chisl += operand * znam;
	Euclid();
	return *this;
}
Drobi Drobi::operator-=(int operand) {
	chisl -= operand * znam;
	Euclid();
	return *this;
}
Drobi Drobi::operator*=(int operand) {
	chisl *= operand;
	Euclid();
	return *this;
}
Drobi Drobi::operator /=(int operand) {
	znam *= operand;
	Euclid();
	return *this;
}

Drobi operator +(Drobi A, Drobi B) {
	Drobi C(A);
	C += B;
	return C;
}
Drobi operator -(Drobi A, Drobi B) {
	Drobi C(A);
	C -= B;
	return C;
}
Drobi operator *(Drobi A, Drobi B) {
	Drobi C(A);
	C *= B;
	return C;
}
Drobi operator /(Drobi A, Drobi B) {
	Drobi C(A);
	C /= B;
	return C;
}

Drobi operator +(int operand, Drobi A) {
	Drobi C = operand;
	C += A;
	return C;
}
Drobi operator -(int operand, Drobi A) {
	Drobi C = operand;
	C -= A;
	return C;
}
Drobi operator *(int operand, Drobi A) {
	Drobi C = operand;
	C *= A;
	return C;
}
Drobi operator /(int operand, Drobi A) {
	Drobi C = operand;
	C /= A;
	return C;
}
Drobi operator +(Drobi A, int operand) {
	Drobi C(A);
	C += operand;
	return C;
}
Drobi operator -(Drobi A, int operand) {
	Drobi C(A);
	C -= operand;
	return C;
}
Drobi operator *(Drobi A, int operand) {
	Drobi C(A);
	C *= operand;
	return C;
}
Drobi operator /(Drobi A, int operand) {
	Drobi C(A);
	C /= operand;
	return C;
}

bool Drobi::operator >(Drobi& A) {
	int a1 = chisl * A.znam;
	int a2 = A.chisl * znam;
	return (a1 > a2);
}
bool Drobi::operator <(Drobi& A) {
	int a1 = chisl * A.znam;
	int a2 = A.chisl * znam;
	return (a1 < a2);
}
bool Drobi::operator ==(Drobi& A) {
	int a1 = chisl * A.znam;
	int a2 = A.chisl * znam;
	return (a1 == a2);
}
bool Drobi::operator !=(Drobi& A) {
	int a1 = chisl * A.znam;
	int a2 = A.chisl * znam;
	return (a1 != a2);
}
bool Drobi::operator >=(Drobi& A) {
	int a1 = chisl * A.znam;
	int a2 = A.chisl * znam;
	return (a1 >= a2);
}
bool Drobi::operator <=(Drobi& A) {
	int a1 = chisl * A.znam;
	int a2 = A.chisl * znam;
	return (a1 <= a2);
}

bool Drobi::operator >(int operand) {
	Drobi B = operand;
	return (*this > B);
}
bool Drobi::operator <(int operand) {
	Drobi B = operand;
	return (*this < B);
}
bool Drobi::operator ==(int operand) {
	Drobi B = operand;
	return (*this == B);
}
bool Drobi::operator !=(int operand) {
	Drobi B = operand;
	return (*this != B);
}
bool Drobi::operator >=(int operand) {
	Drobi B = operand;
	return (*this >= B);
}
bool Drobi::operator <=(int operand) {
	Drobi B = operand;
	return (*this <= B);
}
void Drobi::Minus_swap()
{
	if (znam < 0)
	{
		chisl = -1 * chisl;
		znam = -1 * znam;
	}
}
Drobi Drobi::operator() (int a)
{		
Drobi temp;
temp.chisl = MyPow(chisl, a);
temp.znam = MyPow(znam, a);
return temp;
}
void Drobi::Euclid()
{
	int E = GCD(chisl, znam);
	chisl /= E;
	znam /= E;
}