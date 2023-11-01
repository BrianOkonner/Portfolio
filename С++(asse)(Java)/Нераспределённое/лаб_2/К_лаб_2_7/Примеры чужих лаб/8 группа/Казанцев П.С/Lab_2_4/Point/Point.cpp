#include "Point.h"

double MyPow(double a, int n)
{
	double res = 1;
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

Point::Point(const Point& A) {
	x = A.x;
	y = A.y;
}

ostream& operator<<(ostream& out, const Point& A) {
	out << "(" << A.x << ", " << A.y << ")";
	return out;
}
istream& operator >> (istream& in, Point& A) {
	in >> A.x >> A.y;
	return in;
}

Point Point::operator-() {
	x = -1 * x;
	y = -1 * y;
	return *this;
}

Point Point::operator ++() {
	++x;
	++y;
	return *this;
}
Point Point::operator++(int) {
	Point Copy(*this);
	x++; 
	y++;
	return Copy;
}
Point Point::operator --() {
	--x;
	--y;
	return *this;
}
Point Point::operator--(int) {
	Point Copy(*this);
	x--;
	y--;
	return Copy;
}

Point Point::operator +=(Point A) {
	x += A.x;
	y += A.y;
	return *this;
}
Point Point::operator -=(Point A) {
	x -= A.x;
	y -= A.y;
	return *this;
}
Point Point::operator *=(Point A) {
	x *= A.x;
	y *= A.y;
	return *this;
}
Point Point::operator /=(Point A) {
	x /= A.x;
	y /= A.y;
	return *this;
}

Point Point::operator +=(double operand) {
	x += operand;
	y += operand;
	return *this;
}
Point Point::operator -=(double operand) {
	x -= operand;
	y -= operand;
	return *this;
}
Point Point::operator *=(double operand) {
	x *= operand;
	y *= operand;
	return *this;
}
Point Point::operator /=(double operand) {
	x /= operand;
	y /= operand;
	return *this;
}

Point operator + (Point A, Point B) {
	Point C(A);
	C += B;
	return C;
}
Point operator -(Point A, Point B) {
	Point C(A);
	C -= B;
	return C;
}
Point operator * (Point A, Point B) {
	Point C(A);
	C *= B;
	return C;
}
Point operator / (Point A, Point B) {
	Point C(A);
	C /= B;
	return C;
}

Point operator +(double operand, Point A) {
	Point C = operand;
	C += A;
	return C;
}
Point operator -(double operand, Point A) {
	Point C = operand;
	C -= A;
	return C;
}
Point operator *(double operand, Point A) {
	Point C = operand;
	C *= A;
	return C;
}
Point operator /(double operand, Point A) {
	Point C = operand;
	C /= A;
	return C;
}
Point operator +(Point A, double operand) {
	Point C(A);
	C += operand;
	return C;
}
Point operator -(Point A, double operand) {
	Point C(A);
	C -= operand;
	return C;
}
Point operator *(Point A, double operand) {
	Point C(A);
	C *= operand;
	return C;
}
Point operator /(Point A, double operand) {
	Point C(A);
	C /= operand;
	return C;
}

bool Point::operator>(Point A) {
	return ((x*x + y*y) > (A.x*A.x + A.y*A.y));
}
bool Point::operator<(Point A) {
	return ((x*x + y*y) < (A.x*A.x + A.y*A.y));
}
bool Point::operator==(Point A) {
	return ((x*x + y*y) == (A.x*A.x + A.y*A.y));
}
bool Point::operator!=(Point A) {
	return ((x*x + y*y) != (A.x*A.x + A.y*A.y));
}
bool Point::operator>=(Point A) {
	return ((x*x + y*y) >= (A.x*A.x + A.y*A.y));
}
bool Point::operator<=(Point A) {
	return ((x*x + y*y) <= (A.x*A.x + A.y*A.y));
}

bool Point::operator>(double operand) {
	return(sqrt(x*x + y * y) > (operand));
}
bool Point::operator<(double operand) {
	return(sqrt(x*x + y * y) < (operand));
}
bool Point::operator==(double operand) {
	return(sqrt(x*x + y * y) == (operand));
}
bool Point::operator!=(double operand) {
	return(sqrt(x*x + y * y) != (operand));
}
bool Point::operator>=(double operand) {
	return(sqrt(x*x + y * y) >= (operand));
}
bool Point::operator<=(double operand) {
	return(sqrt(x*x + y * y) <= (operand));
}

double Point::Length(){
	return sqrt(x*x + y * y);
}