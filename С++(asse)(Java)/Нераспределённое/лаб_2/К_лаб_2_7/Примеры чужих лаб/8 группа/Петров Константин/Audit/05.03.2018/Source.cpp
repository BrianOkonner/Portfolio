/*
Петров Константин
8 группа
05.03.2018


*/

#include<iostream>
using namespace std;


class MyPoint {
	int x;
	int y;
public:
	MyPoint() :x(0), y(0) {};
	MyPoint(int, int);
	MyPoint(const MyPoint&);
	~MyPoint();

	MyPoint& operator ++();
	MyPoint operator ++(int);
	MyPoint& operator --();
	MyPoint operator --(int);
	friend MyPoint& operator +(const MyPoint& A, const MyPoint& B);
	friend MyPoint& operator -(const MyPoint& A, const MyPoint& B);
	friend MyPoint& operator *(const MyPoint& A, const MyPoint& B);
	friend MyPoint& operator /(const MyPoint& A, const MyPoint& B);
	MyPoint& operator +=(const  MyPoint&);
	MyPoint& operator -=(const  MyPoint&);
	MyPoint& operator *=(const  MyPoint&);
	MyPoint& operator /=(const  MyPoint&);
	friend ostream& operator <<(ostream&, const MyPoint&);
};

MyPoint::MyPoint(int a, int b) {
	x = a;
	y = b;
}
MyPoint::MyPoint(const MyPoint& A) {
	x = A.x;
	y = A.y;
}
MyPoint::~MyPoint() {
	//cout << "Сработал деструктор" << endl;
}
MyPoint& MyPoint::operator++() {
	x++;
	y++;
	return *this;
}
MyPoint MyPoint::operator++(int) {
	MyPoint temp(*this);
	++x;
	++y;
	return temp;
}
MyPoint& MyPoint::operator--() {
	x--;
	y--;
	return *this;
}
MyPoint MyPoint::operator--(int) {
	MyPoint temp(*this);
	--x;
	--y;
	return temp;
}
MyPoint& operator +(const MyPoint& A, const MyPoint& B) {
	MyPoint Res(A);
	Res.x += B.x;
	Res.y += B.y;
	return Res;
}
MyPoint& operator -(const MyPoint& A, const MyPoint& B) {
	MyPoint Res(A);
	Res.x -= B.x;
	Res.y -= B.y;
	return Res;
}
MyPoint& operator *(const MyPoint& A, const MyPoint& B) {
	MyPoint Res(A);
	Res.x *= B.x;
	Res.y *= B.y;
	return Res;
}
MyPoint& operator /(const MyPoint& A, const MyPoint& B) {
	MyPoint Res(A);
	Res.x /= B.x;
	Res.y /= B.y;
	return Res;
}
MyPoint& MyPoint::operator +=(const  MyPoint& A) {
	x += A.x;
	y += A.y;
	return *this;
}
MyPoint& MyPoint::operator -=(const  MyPoint& A) {
	x -= A.x;
	y -= A.y;
	return *this;
}
MyPoint& MyPoint::operator *=(const  MyPoint& A) {
	x *= A.x;
	y *= A.y;
	return *this;
}
MyPoint& MyPoint::operator /=(const  MyPoint& A) {
	x /= A.x;
	y /= A.y;
	return *this;
}
ostream& operator <<(ostream& out, const MyPoint& A) {
	cout << A.x << "   " << A.y;
	return out;
}
int main() {
	setlocale(LC_ALL, "rus");


	MyPoint A(1, 2);
	MyPoint B(2, 3);
	MyPoint C;
	cout << "A  - " << A << endl;
	cout << "B  - " << B << endl;

	A = (++A++) +(++B);
	cout <<"A = (++A++) +(++B);  --- "<< A << endl;


	system("pause");
	return 0;
}