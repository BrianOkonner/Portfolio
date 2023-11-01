#undef UNICODE
#include <windows.h>
#pragma comment(lib,"winmm.lib")
#include <wingdi.h>
#include <math.h>
#include <iostream>
#include <time.h>
using namespace std;
struct para
{
	int x;
	int y;
	int color;
	para():x(-1),y(-1),color(-1){}
	friend int operator ==(para &p1,para& p2);
	friend int operator !=(para &p1,para& p2);
	bool good();
};
class carta
{
private:
	int x1,y1,x2,y2;
	bool side;
	int color;
	bool exist;
public:
	carta():x1(0),x2(0),y1(0),y2(0),side(false),color(0),exist(true)
	{
		srand(time(0));
		color=rand()%3;
	};
	carta(int=0,int=0,int=30,int=30,int=0,bool=false,bool=false);
	void prisv(int=0,int=0,int=30,int=30,int=0,bool=false,bool=false);
	void Draw(HDC &hdc);
	void Perevorot();
	bool changeside()
	{
		side=!side;
		return !side;
	}
	bool getside()
	{
		return side;
	}
	void gencolor(int x)
	{	
		color=x%3;
	}
	int getcolor()
	{
		return color;
	}
	bool getexist()
	{
		return exist;
	}
	bool changeexist()
	{
		exist=!exist;
		return !exist;
	}
	void exists()
	{
		exist=true;
	}
	void noexist()
	{
		exist=false;
	}
	void sideopen()
	{
		side=true;
	}
	void sideclose()
	{
		side=false;
	} 
	int changecolor(int newcolor)
	{
		int a=color;
		color=newcolor;
		return a;
	}
};
para provbuttom(int,int);
void knowgeneration(int=3);
void DrawMenu(HDC &hdc);
void DrawBoard(HDC &hdc);
void DrawRectangleMenu(HDC &hdc,RECT &rect);
void DrawRam(HDC &hdc,RECT &rect);
void DrawSmallRectangle(HDC &hdc,RECT &rect);