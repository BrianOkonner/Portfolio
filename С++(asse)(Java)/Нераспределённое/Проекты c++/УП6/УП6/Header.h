#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <iomanip>
#include <ctime>
using namespace std;

class AbstractUnit
{
private:
	int orientation;
	int size_x, size_y, center_x, center_y;
	double m_speed;

public:
	virtual ~AbstractUnit() = 0 {}
	void setSize(const int x, const int y)
	{
		size_x = x; size_y = y;
	}
	void setSpeed(const double speed);
	double getSpeed() const;
	int get_size_x() { return size_x; }
	int get_size_y() { return size_y; }
	int get_center_x() { return center_x; }
	int get_center_y() { return center_y; }
	void add_center_x(int x) { orientation = 1; center_x = 100; center_x += x; }
	void add_center_y(int y) { orientation = 2; center_y = 100; center_y += y; }
	void sub_center_x(int x) { orientation = -1; center_x = 100; center_x -= x; }
	void sub_center_y(int y) { orientation = -2; center_y = 100; center_y -= y; }
	int get_or() { return orientation; }
};

class Tank : public AbstractUnit
{
public:
	Tank()
	{
		setSize(0, 0);
		//	setSpeed(speed);
	}
	void setTank(int size_x, int size_y, int speed)
	{
		setSize(size_x, size_y);
		//	setSpeed(speed);
	}
	~Tank()
	{

	}
	void paint(HDC hdc, int center_x, int center_y)
	{
		Rectangle(hdc, center_x - get_size_x() / 2, center_y - get_size_y() / 2, center_x + get_size_x() / 2, center_y + get_size_y() / 2);
		MoveToEx(hdc, center_x, center_y, NULL);
		if ((*this).get_or() == 1)
			LineTo(hdc, center_x + get_size_x(), center_y);
		if ((*this).get_or() == -1)
			LineTo(hdc, center_x - get_size_x(), center_y);
		if ((*this).get_or() == 2)
			LineTo(hdc, center_x , center_y + get_size_y());
		if ((*this).get_or() == -2)
			LineTo(hdc, center_x , center_y - get_size_y());
	}

	void move_right()
	{
		(*this).add_center_x(10);
	}
	void move_left()
	{
		(*this).sub_center_x(10);
	}
	void move_top()
	{
		(*this).sub_center_y(10);
	}
	void move_bottom()
	{
		(*this).add_center_y(10);
	}
	//void animateMoveToPoint(const Point2D& moveToPoint) override
	//{
	//	// play particle
	//	// play sound
	//	// run skeleton animation
	//}
};