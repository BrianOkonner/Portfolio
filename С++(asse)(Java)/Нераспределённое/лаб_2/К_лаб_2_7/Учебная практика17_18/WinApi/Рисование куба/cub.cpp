#include"cub.h"

Cub::Cub(const Point& p,int s1):Point(p),size(s1)
{
	sdvig=(int)(size/(2*1.414));
}

bool Cub::CanDraw(RECT rect)
{//находимся ли в границах рабочей области
	if((y-sdvig-1<=rect.top)||(x+size+sdvig+1>=rect.right-140)||(y+size+1>=rect.bottom)||(x-1<=rect.left))
		return FALSE;
	if(size>0)
		return TRUE;
	return FALSE;
}

void Cub::ChangeSize(const Point& p)
{//изменяет данные при изменении размеров
	if(p>0)  //по меньшему из приращений
		if(p.x+p.y>0)  
		{
			size-=p.y;
			y+=p.y;
		}
		else
		{
			size+=p.x;
			y-=p.x;
		}
	else
		if(p.x+p.y>0)
		{
			size+=p.x;
			y-=p.x;
		}
		else
		{
			size-=p.y;
			y+=p.y;
		}		
		sdvig=(int)(size/(2*1.414));
}

void Cub::Draw(HWND hwnd)
{
	HPEN        hPen1,hPen2;
	HDC         hdc;
	RECT        rect;
	hdc=GetDC(hwnd);
	GetClientRect (hwnd, &rect);
	if(CanDraw(rect))
	{
	Rectangle(hdc,rect.left,rect.top,rect.right-140,rect.bottom);
	srand(time(0));	
	hPen1=CreatePen(PS_SOLID,1,RGB(rand()%256,rand()%256,rand()%256));
	hPen2=CreatePen(PS_DASH,0,RGB(rand()%256,rand()%256,rand()%256));
	int i,j;
	i=x;
	j=y;
	SelectObject (hdc, hPen1);
	MoveToEx(hdc,i,j,NULL);
	
			   j+=size;   LineTo(hdc,i,j);
			   i+=size;   LineTo(hdc,i,j);
			   j-=size;   LineTo(hdc,i,j);
			   i-=size;   LineTo(hdc,i,j);
			   i+=sdvig; j-=sdvig;
			   LineTo(hdc,i,j);
			   SelectObject (hdc, hPen2);
			   j+=size;   LineTo(hdc,i,j);
			   i+=size;   LineTo(hdc,i,j);
			   SelectObject (hdc, hPen1);
			   j-=size;   LineTo(hdc,i,j);
			   i-=size;   LineTo(hdc,i,j);
			   MoveToEx(hdc,i+size-sdvig,j+sdvig,NULL);
			   i+=size;   LineTo(hdc,i,j);
			   MoveToEx(hdc,i-sdvig,j+size+sdvig,NULL);
			   j+=size;   LineTo(hdc,i,j);
			   SelectObject (hdc, hPen2);
			   MoveToEx(hdc,i-size-sdvig,j+sdvig,NULL);
			   i-=size; LineTo(hdc,i,j);
			   ReleaseDC(hwnd,hdc);
			    DeleteObject(hPen1);
			  DeleteObject(hPen2);
	}
}