#include <iostream>
#include <windows.h>
using namespace std;

class point
{
protected:
	int x, y;
public:
	point()
	{
		x = y = 50;
	}
	//int getX() { return x; }
	point(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	point(const point&p)
	{
		x = p.x;
		y = p.y;
	}
	~point() {}
	/*void print()
	{
		cout << "Точка " << x << " "<<y << endl;
	}*/
	void Draw(HWND hWnd); 
};

class circle : public point
{
protected:
	int r;
public:
	circle() :point()
	{
		r = 200;
	};
	circle(int r1, int x1, int y1) :point(x1,y1)
	{
		r = r1;
	}
	/*void print()
	{
		cout << "Круг " << r << " " << x << " " << y << endl;
	}*/
	void Draw(HWND hWnd); 
	circle& shift(int t)//перенос центра
	{
		x += t;
		y += t;
		return *this;
	}
	circle& rad(int t)//увеличение радиуса
	{
		r += t;
	}
};

class rectangle : public circle
{
public:
	rectangle() :circle(){};
	rectangle(int r, int x, int y) :circle(r, x, y){};
	/*void print()
	{
		cout << "Прямоугольник "<< x<<" "<< y<<" "<< x+r<< " "<< y+r  << endl;
	}*/
	void Draw(HWND hWnd)
	{
	HPEN        hPen;
	HDC         hDC;
	RECT        rect;
	hDC=GetDC(hWnd);
	GetClientRect (hWnd, &rect);
	hPen = CreatePen(PS_SOLID, 5, RGB(30,144,255));
	SelectObject (hDC, hPen);
	Rectangle( hDC,  x, y, x+r, y+r);
	}
	rectangle& shift(int t)//сдвигаем точку
	{
		x += t;
		y += t;
	}
	rectangle& rad(int t)//увеличиваем прямоугольник
	{
		r += t;
	}
};