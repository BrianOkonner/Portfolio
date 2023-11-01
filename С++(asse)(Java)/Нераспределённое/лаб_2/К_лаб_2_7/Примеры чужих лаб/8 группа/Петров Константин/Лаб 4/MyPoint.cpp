/*
Петров Константин
8 группа
Лаб 4 Класс Точка

Задание 1  Класс точка.
Разработать интерфейс класса для обработки координат на плоскости  ( в пространстве).
Написать программу  для проверки выполнения операций с координатами точек.
*/

#include <iostream>
using namespace std;

double mypow(double a, int b) {
	return (b == 0) ? 1 : a * pow(a, b - 1);
}

class MyPoint {
protected:
	double x;
	double y;
public:
	MyPoint(double a = (double)0, double b = (double)0) :x(a), y(b) {}
	MyPoint(const MyPoint&);

	friend ostream& operator <<(ostream&, const MyPoint&);
	friend istream& operator >> (istream&, MyPoint&);

	MyPoint operator-();

	MyPoint operator ++();
	MyPoint operator ++(int);
	MyPoint operator --();
	MyPoint operator --(int);

	MyPoint operator += (MyPoint);
	MyPoint operator -= (MyPoint);
	MyPoint operator *= (MyPoint);
	MyPoint operator /= (MyPoint);

	MyPoint operator += (double);
	MyPoint operator -= (double);
	MyPoint operator *= (double);
	MyPoint operator /= (double);

	friend MyPoint operator +(MyPoint, MyPoint);
	friend MyPoint operator -(MyPoint, MyPoint);
	friend MyPoint operator *(MyPoint, MyPoint);
	friend MyPoint operator /(MyPoint, MyPoint);

	friend MyPoint operator +(double, MyPoint);
	friend MyPoint operator -(double, MyPoint);
	friend MyPoint operator *(double, MyPoint);
	friend MyPoint operator /(double, MyPoint);
	friend MyPoint operator +(MyPoint, double);
	friend MyPoint operator -(MyPoint, double);
	friend MyPoint operator *(MyPoint, double);
	friend MyPoint operator /(MyPoint, double);
	//Сравнение радиус векторов	
	bool operator >(MyPoint);
	bool operator <(MyPoint);
	bool operator ==(MyPoint);
	bool operator !=(MyPoint);
	bool operator >=(MyPoint);
	bool operator <=(MyPoint);
	//Cравнение радиус вектора точки и числа 
	bool operator >(double);
	bool operator <(double);
	bool operator ==(double);
	bool operator !=(double);
	bool operator >=(double);
	bool operator <=(double);

	double GetSize() {
		return sqrt(x*x + y * y);
	}
	MyPoint operator()(int st) {
		MyPoint temp;
		temp.x = mypow(x, st);
		temp.y = mypow(y, st);
		return temp;
	}
};

MyPoint::MyPoint(const MyPoint& A) {
	x = A.x;
	y = A.y;
}

ostream& operator<<(ostream& out, const MyPoint& A) {
	out << "( " << A.x << ", " << A.y << " )";
	return out;
}
istream& operator >> (istream& in, MyPoint& A) {
	in >> A.x >> A.y;
	return in;
}

MyPoint MyPoint::operator-() {
	x = -1 * x;
	y = -1 * y;
	return *this;
}

MyPoint MyPoint::operator ++() {
	++x;
	++y;
	return *this;
}
MyPoint MyPoint::operator++(int) {
	MyPoint Copy(*this);
	x++;
	y++;
	return Copy;
}
MyPoint MyPoint::operator --() {
	--x;
	--y;
	return *this;
}
MyPoint MyPoint::operator--(int) {
	MyPoint Copy(*this);
	x--;
	y--;
	return Copy;
}

MyPoint MyPoint::operator +=(MyPoint A) {
	x += A.x;
	y += A.y;
	return *this;
}
MyPoint MyPoint::operator -=(MyPoint A) {
	x -= A.x;
	y -= A.y;
	return *this;
}
MyPoint MyPoint::operator *=(MyPoint A) {
	x *= A.x;
	y *= A.y;
	return *this;
}
MyPoint MyPoint::operator /=(MyPoint A) {
	x /= A.x;
	y /= A.y;
	return *this;
}

MyPoint MyPoint::operator +=(double val) {
	x += val;
	y += val;
	return *this;
}
MyPoint MyPoint::operator -=(double val) {
	x -= val;
	y -= val;
	return *this;
}
MyPoint MyPoint::operator *=(double val) {
	x *= val;
	y *= val;
	return *this;
}
MyPoint MyPoint::operator /=(double val) {
	x /= val;
	y /= val;
	return *this;
}

MyPoint operator + (MyPoint A, MyPoint B) {
	MyPoint C(A);
	C += B;
	return C;
}
MyPoint operator -(MyPoint A, MyPoint B) {
	MyPoint C(A);
	C -= B;
	return C;
}
MyPoint operator * (MyPoint A, MyPoint B) {
	MyPoint C(A);
	C *= B;
	return C;
}
MyPoint operator / (MyPoint A, MyPoint B) {
	MyPoint C(A);
	C /= B;
	return C;
}

MyPoint operator +(double val, MyPoint A) {
	MyPoint C = val;
	C += A;
	return C;
}
MyPoint operator -(double val, MyPoint A) {
	MyPoint C = val;
	C -= A;
	return C;
}
MyPoint operator *(double val, MyPoint A) {
	MyPoint C = val;
	C *= A;
	return C;
}
MyPoint operator /(double val, MyPoint A) {
	MyPoint C = val;
	C /= A;
	return C;
}
MyPoint operator +(MyPoint A, double val) {
	MyPoint C(A);
	C += val;
	return C;
}
MyPoint operator -(MyPoint A, double val) {
	MyPoint C(A);
	C -= val;
	return C;
}
MyPoint operator *(MyPoint A, double val) {
	MyPoint C(A);
	C *= val;
	return C;
}
MyPoint operator /(MyPoint A, double val) {
	MyPoint C(A);
	C /= val;
	return C;
}

bool MyPoint::operator>(MyPoint A) {
	return (this->GetSize() > A.GetSize());
}
bool MyPoint::operator<(MyPoint A) {
	return (this->GetSize() < A.GetSize());
}
bool MyPoint::operator==(MyPoint A) {
	return (this->GetSize() == A.GetSize());
}
bool MyPoint::operator!=(MyPoint A) {
	return (this->GetSize() != A.GetSize());
}
bool MyPoint::operator>=(MyPoint A) {
	return (this->GetSize() >= A.GetSize());
}
bool MyPoint::operator<=(MyPoint A) {
	return (this->GetSize() <= A.GetSize());
}

bool MyPoint::operator>(double val) {
	return(this->GetSize() > (val));
}
bool MyPoint::operator<(double val) {
	return(this->GetSize() < (val));
}
bool MyPoint::operator==(double val) {
	return(this->GetSize() == (val));
}
bool MyPoint::operator!=(double val) {
	return(this->GetSize() != (val));
}
bool MyPoint::operator>=(double val) {
	return(this->GetSize() >= (val));
}
bool MyPoint::operator<=(double val) {
	return(this->GetSize() <= (val));
}

int main() {
	MyPoint a(1, 2), b, c(5), d(2, 1);

	system("pause");
	return 0;
}