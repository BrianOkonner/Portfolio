/*
	Петров Константин 
		8 группа

	Лаб 4  - Класс рациональных дробей

	Задание 2  Класс дробей.
 Разработать интерфейс класса для обработки обычных дробей, заданными числителем и знаменателем. 
 Написать программу  для проверки  выполнения операций с обычными дробями.  
	
*/

#include <iostream>
using namespace std;

class Drobi {
	int chisl;
	int znam;
public:
	Drobi();
	Drobi(int, int);
	Drobi(const Drobi &A);
	~Drobi();
	
	Drobi& operator ++();
	Drobi& operator ++(int);
	Drobi& operator --();
	Drobi& operator --(int);

	Drobi& operator = (const Drobi& A);
	Drobi operator - ();

	Drobi& operator +=(const Drobi &A);
	Drobi& operator -=(const Drobi &A);
	Drobi& operator *=(const Drobi &A);
	Drobi& operator /=(const Drobi &A);

	friend Drobi& operator +(const Drobi &A, const Drobi& B);
	friend Drobi& operator -(const Drobi &A, const Drobi& B);
	friend Drobi& operator *(const Drobi &A, const Drobi& B);
	friend Drobi& operator /(const Drobi &A, const Drobi& B);

	friend ostream& operator << (ostream& out, const Drobi& A);
	friend istream& operator >> (istream& is, Drobi& A);

	bool operator < (const Drobi A);
	bool operator > (const Drobi A);
};

Drobi::Drobi() :chisl(1), znam(1){}
Drobi::Drobi(int a, int b): chisl(a), znam(b){}
Drobi::Drobi(const Drobi& A) {
	chisl = A.chisl;
	znam = A.znam;
}
Drobi::~Drobi() {
	//cout << "Сработал деструктор" << endl;
}
ostream& operator <<(ostream& out, const Drobi& A) {
	out << A.chisl << " / " << A.znam;
	return out;
}
istream& operator >> (istream& is, Drobi& A) {
	is >> A.chisl >> A.znam;
	return is;
}
bool Drobi::operator <(const Drobi A) {
	return (this->chisl * A.znam < A.chisl * this->znam);
}
bool Drobi::operator >(const Drobi A) {
	return (this->chisl * A.znam > A.chisl * this->znam);
}
Drobi& Drobi::operator +=(const Drobi& A) {
	chisl = chisl * A.znam + znam * A.chisl;
	znam *= A.znam;

	int a = chisl, b = znam;
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	
	chisl /= a;
	znam /= a;

	return *this;
}
Drobi& Drobi::operator -=(const Drobi& A) {
	chisl = chisl * A.znam - znam * A.chisl;
	znam *= A.znam;

	int a = chisl, b = znam;
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}

	chisl /= a;
	znam /= a;

	return *this;
}
Drobi& Drobi::operator *=(const Drobi& A) {
	chisl *= A.chisl;
	znam *= A.znam;

	int a = chisl, b = znam;
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	
	chisl /= a;
	znam /= a;
	return *this;
}
Drobi& Drobi::operator /=(const Drobi& A) {
	int temp1 = A.chisl, temp2 = A.znam;

	chisl *= temp2;
	znam *= temp1;

	int a = chisl, b = znam;
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}

	chisl /= a;
	znam /= a;
	return *this;
}
Drobi& Drobi::operator ++() {
	chisl += znam;
	return *this;
}
Drobi& Drobi::operator ++(int) {
	Drobi temp(*this);
	chisl += znam;
	return temp;
}
Drobi& Drobi::operator --() {
	chisl -= znam;
	return *this;
}
Drobi& Drobi::operator --(int) {
	Drobi temp(*this);
	chisl -= znam;
	return temp;
}
Drobi& Drobi::operator =(const Drobi& A) {
	chisl = A.chisl;
	znam = A.znam;
	return *this;
}
Drobi Drobi::operator -() {
	chisl = -chisl;
	return *this;
}
Drobi& operator *(const Drobi& A, const Drobi& B) {
	return Drobi(A) *= B;
}
Drobi& operator /(const Drobi& A, const Drobi& B) {
	return Drobi(A) /= B;
}
Drobi& operator +(const Drobi& A, const Drobi& B) {
	return Drobi(A) += B;
}
Drobi& operator -(const Drobi& A, const Drobi& B) {
	return Drobi(A) -= B;
}

int main() {
	setlocale(LC_ALL, "rus");
	Drobi A(1, 3), B(2, 5);
	Drobi C = A*B;
	cout << "A = " << A << endl;
	cout << "B = " << B << endl << endl;
	cout << "A * B = " << C << endl;
	C = A / B;
	cout << "A / B = " << C << endl;
	C = A + B;
	cout << "A + B = " << C << endl;
	C = A - B;
	cout << "A - B = " << C << endl;
	A++;
	cout << "A++ = " << A << endl;
	A--;
	cout << "A-- = " << A << endl;
	A += B;
	cout << "A + =B  = " << A << endl;
	A -= B;
	cout << "A -= B  = " << A << endl;
	A *= B;
	cout << "A *= B  = " << A << endl;
	A /= B;
	cout << "A /= B  = " << A << endl;
	-A;
	cout << "-A = " << A << endl;
	-A;
	cout << "A>B - ?  - " << (A > B) << endl;
	cout << "A<B - ?  - " << (A < B) << endl;
	return 0;
}