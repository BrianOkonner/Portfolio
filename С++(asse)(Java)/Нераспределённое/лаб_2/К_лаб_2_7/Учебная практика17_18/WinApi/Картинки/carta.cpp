#include "carta.h"
#undef UNICODE
carta::carta(int a,int b,int c,int d,int s,bool t,bool q)
{
	srand(time(0));
	x1=a;
	y1=b;
	x2=c;
	y2=d;
	color=s;
	exist=t;
	side=q;
}
void carta::prisv(int a,int b,int c,int d,int s,bool t,bool q)
{
	x1=a;
	y1=b;
	x2=c;
	y2=d;
	color=s;
	exist=t;
	side=q;
}
void carta::Draw(HDC &hdc)
{
	HBRUSH hBrush,hOldBrush;
	HPEN hPen, hOldPen;
	HBITMAP hBmp;
	if(!exist)	
	{
		hPen=CreatePen(PS_SOLID,5,RGB(230,150,150));
		hOldPen=(HPEN)SelectObject(hdc,hPen);
		hBrush=CreateSolidBrush(RGB(150,300,150));
		hOldBrush=(HBRUSH)SelectObject(hdc,hBrush);
		RoundRect(hdc,x1-2,y1-2,x2+2,y2+2,10,10);
		SelectObject(hdc,hOldPen);
		DeleteObject(hOldPen);
		SelectObject(hdc,hOldBrush);
		DeleteObject(hBrush);
		return;
	}
	if(side==true)
	{
		switch(color)
		{
		case 0:
			hBmp=(HBITMAP)LoadImage(NULL,"0.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 1:
			hBmp=(HBITMAP)LoadImage(NULL,"1.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 2:
			hBmp=(HBITMAP)LoadImage(NULL,"2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 3:
			hBmp=(HBITMAP)LoadImage(NULL,"3.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 4:
			hBmp=(HBITMAP)LoadImage(NULL,"4.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 5:
			hBmp=(HBITMAP)LoadImage(NULL,"5.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 6:
			hBmp=(HBITMAP)LoadImage(NULL,"6.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 7:
			hBmp=(HBITMAP)LoadImage(NULL,"7.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 8:
			hBmp=(HBITMAP)LoadImage(NULL,"8.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 9:
			hBmp=(HBITMAP)LoadImage(NULL,"9.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 10:
			hBmp=(HBITMAP)LoadImage(NULL,"10.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		case 11:
			hBmp=(HBITMAP)LoadImage(NULL,"11.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
			break;
		default:
			return;
		}
		hPen = CreatePen(PS_SOLID, 5, RGB(150,150, 150));
		hOldPen = (HPEN)SelectObject (hdc, hPen);
		hBrush=CreateSolidBrush(RGB(130,0,1000));
		hOldBrush= (HBRUSH)SelectObject (hdc, hBrush);
		HDC     hMemDC;
		HBITMAP hOldBitmap;
		hMemDC = CreateCompatibleDC(hdc);
		if (hMemDC)
		{
		   hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBmp);
		   RoundRect(hdc,x1-2,y1-2,x2+2,y2+2,10,10);
		   BitBlt(hdc, x1,y1, 90, 90, hMemDC, 0, 0, SRCCOPY);
		   SelectObject(hMemDC, hOldBitmap);
		   DeleteDC(hMemDC);
		   SelectObject(hdc,hOldPen);
		   SelectObject(hdc,hBrush);
		   DeleteObject(hPen);
		   DeleteObject(hBrush);
		}
		else
		{
			return;
		}
		return;
	}
	else
	{
		hPen = CreatePen(PS_SOLID, 5, RGB(150,150, 150));
		hOldPen = (HPEN)SelectObject (hdc, hPen);
		hBrush=CreateSolidBrush(RGB(130,0,100));
		hOldBrush= (HBRUSH)SelectObject (hdc, hBrush);
		RoundRect(hdc,x1-2,y1-2,x2+2,y2+2,10,10);
		SelectObject(hdc,hOldPen);
		SelectObject(hdc,hBrush);
		DeleteObject(hPen);
		DeleteObject(hBrush);
		return;
	}
	return;
}
bool para::good()
{
	return (x!=-1)&&(y!=-1);
}
para provbuttom(int x,int y)
{
	para p1;
	if(x%100<=90&&y%100<=90&&x>=0&&y>=0&&x<600&&y<600)
	{
		int s=x/100,t=y/100;
		p1.x=s;	
		p1.y=t;
		return p1;
	}
	p1.x=-1;
	p1.y=-1;
	return p1;
}
int operator ==(para &p1,para& p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}
int operator !=(para &p1,para& p2)
{
	return (p1.x != p2.x || p1.y != p2.y);
}
void DrawBoard(HDC &hdc)
{
	HPEN hPen,hOldPen;
	HBRUSH hBrush,hOldBrush;
	hPen=CreatePen(PS_SOLID,10,RGB(235,235,0));
	hBrush=CreateSolidBrush(RGB(100,100,100));
	hOldPen=(HPEN)SelectObject(hdc,hPen);
	hOldBrush=(HBRUSH)SelectObject(hdc,hBrush);
	POINT a[5];
	a[0].x=7;
	a[0].y=7;
	a[1].x=622;
	a[1].y=7;
	a[2].x=622;
	a[2].y=622;
	a[3].x=7;
	a[3].y=622;
	a[4]=a[0];
	Polyline(hdc,a,5);
	RoundRect(hdc,10,10,620,620,10,10);	
	SelectObject(hdc,hOldPen);
	SelectObject(hdc,hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);	
}
void DrawRectangleMenu(HDC &hdc,RECT &rect)
{
	HPEN hPen,hOldPen;
	HBRUSH hBrush,hOldBrush;
	hPen=CreatePen(PS_SOLID,10,RGB(235,235,0));
	hBrush=CreateSolidBrush(RGB(0,200,200));
	hOldPen=(HPEN)SelectObject(hdc,hPen);
	hOldBrush=(HBRUSH)SelectObject(hdc,hBrush);
	RoundRect(hdc,max(rect.right-130-7,672),rect.top+180,max(rect.right-130-7,672)+130,rect.top+320,10,10);
	SelectObject(hdc,hOldPen);
	SelectObject(hdc,hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);	
}
/*void DrawSmallRectangle(HDC &hdc,RECT &rect)
{
	HPEN hPen,hOldPen;
	HBRUSH hBrush,hOldBrush;
	hPen=CreatePen(PS_SOLID,10,RGB(235,235,0));
	hBrush=CreateSolidBrush(RGB(0,200,200));
	hOldPen=(HPEN)SelectObject(hdc,hPen);
	hOldBrush=(HBRUSH)SelectObject(hdc,hBrush);
	RoundRect(hdc,max(rect.right-130-7,675),rect.top+180,max(rect.right-100+89,675),rect.top+320,10,10);
	SelectObject(hdc,hOldPen);
	SelectObject(hdc,hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);	
}*/