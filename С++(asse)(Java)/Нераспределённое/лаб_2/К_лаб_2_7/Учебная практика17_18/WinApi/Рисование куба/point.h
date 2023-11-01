#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
class Point
	{
	public:
		int x,y;
	
		Point():x(0),y(0){} //конструктор по умолчанию
		Point(int x1,int y1);
		Point(const Point& p);  //конструктор копирования
		Point& operator=(const Point& p);
		Point operator-(const Point& p);
		Point& operator+(int i);
		Point& operator+=(const Point& p);
		friend bool operator>(const Point& p,int i); //сравнение точки с числом
		friend bool operator<(const Point& p,int i);
		virtual~Point(){}
	};
