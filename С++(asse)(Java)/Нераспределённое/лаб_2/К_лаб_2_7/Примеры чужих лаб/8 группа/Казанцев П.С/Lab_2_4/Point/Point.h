#pragma once
#include <iostream>
using namespace std;

double MyPow(double a, int n);

class Point {
protected:
	double x;
	double y;
public:
	Point(double a = 0, double b = 0) :x(a), y(b){}
	Point(const Point&);

	friend ostream& operator <<(ostream&, const Point&);
	friend istream& operator >> (istream&, Point&);

	Point operator-();

	Point operator ++();
	Point operator ++(int);
	Point operator --();
	Point operator --(int);

	Point operator += (Point);
	Point operator -= (Point);
	Point operator *= (Point);
	Point operator /= (Point);

	Point operator += (double);
	Point operator -= (double);
	Point operator *= (double);
	Point operator /= (double);

	friend Point operator +(Point, Point);
	friend Point operator -(Point, Point);
	friend Point operator *(Point, Point);
	friend Point operator /(Point, Point);

	friend Point operator +(double, Point);
	friend Point operator -(double, Point);
	friend Point operator *(double, Point);
	friend Point operator /(double, Point);
	friend Point operator +(Point, double);
	friend Point operator -(Point, double);
	friend Point operator *(Point, double);
	friend Point operator /(Point, double);
	
	bool operator >(Point);
	bool operator <(Point);
	bool operator ==(Point);
	bool operator !=(Point);
	bool operator >=(Point);
	bool operator <=(Point);
	
	bool operator >(double);
	bool operator <(double);
	bool operator ==(double);
	bool operator !=(double);
	bool operator >=(double);
	bool operator <=(double);

	double Length();

	Point operator()(int st) {
		Point temp;
		temp.x = MyPow(x, st);
		temp.y = MyPow(y, st);
		return temp;
	}
};