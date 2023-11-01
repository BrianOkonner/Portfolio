#include "ClassShapes.h"
#include <cmath>
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
KCircle::KCircle(int r, ClassPoint c) : KShape()
{
	R = r;
	center = c;
	isShown = true;
}

KCircle::KCircle(int r = 1)
{
	R = r;
	isShown = true;
}

KCircle::KCircle(const KCircle & c) : KShape(c)
{
	center = c.center;
	R = c.R;
	isShown = c.isShown;
}

void KCircle::SetRad(int r)
{
	R = r;
}

void KCircle::SetCenter(const ClassPoint& p)
{
	center = p;
}

KCircle& KCircle::operator = (const KCircle& c)
{
	center = c.center;
	R = c.R;
	isShown = c.isShown;
	return *this;
}

void KCircle::Shift(int dx, int dy)
{
	center.x += dx;
	center.y += dy;
}

void KCircle::MoveTo(const ClassPoint& p)
{
	center = p;
}

void KCircle::Explode(int x)
{
	R *= x;
}

void KCircle::Draw(CPaintDC &dc)
{
	//CPaintDC dc;
	dc.SelectObject(GetStockObject(NULL_BRUSH));
	if (isShown) dc.Ellipse(center.x - R, center.y - R, center.x + R, center.y + R);
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
KTriangle::KTriangle(ClassPoint v1, ClassPoint v2, ClassPoint v3) : KShape()
{
	vertices[0] = v1;
	vertices[1] = v2;
	vertices[2] = v3;
}

KTriangle::KTriangle(const KTriangle &c) : KShape(c)
{
	for(int i = 0; i <= 2; i++) vertices[i] = c.vertices[i];
}

KTriangle& KTriangle::operator =(const KTriangle& c)
{
	for (int i = 0; i <= 2; i++) vertices[i] = c.vertices[i];
	return *this;
}

ClassPoint KTriangle::Center()
{
	ClassPoint tmp;
	tmp.x = (vertices[0].x + vertices[1].x + vertices[2].x)/3;
	tmp.y = (vertices[0].y + vertices[1].y + vertices[2].y)/3;
	return tmp;
}

int KTriangle::Radius()
{
	ClassPoint tmp = this->Center();
	ClassPoint tmp2 = vertices[0];
	int res = sqrt((double)((tmp.x - tmp2.x) * (tmp.x - tmp2.x)) + ((tmp.y - tmp2.y) * (tmp.y - tmp2.y)));
	return res;
}

void KTriangle::Shift(int dx, int dy)
{
	for (int i = 0; i < 2; i++)
	{
		vertices[i].x += dx;
		vertices[i].y += dy;
	}
}

void KTriangle::Explode(int k)
{
	ClassPoint tmp = this->Center();
	if (k != 1)
	{
		for (int i = 0; i < 2; i++)
		{
			vertices[i].x += (vertices[i].x - tmp.x) * (k - 1);
			vertices[i].y += (vertices[i].y - tmp.y) * (k - 1);
		}
	}
}

void KTriangle::Rotate(double radian)
{
	if (radian)
	{
		ClassPoint tmp = this->Center();
		for (int i = 0; i < 2; i++)
		{
			vertices[i].x -= tmp.x;
			vertices[i].y -= tmp.y;
			vertices[i].x = vertices[i].x * (int)cos(radian) - vertices[i].y * (int)sin(radian);
			vertices[i].y = vertices[i].x * (int)sin(radian) + vertices[i].y * (int)cos(radian);
			vertices[i].x += tmp.x;
			vertices[i].y += tmp.y;
		}
	}
}

void KTriangle::MoveTo(const ClassPoint& p)
{
	int dx = Center().x - p.x;
	int dy = Center().y - p.y;
	Shift(dx, dy);
}

void KTriangle::Draw(CPaintDC &dc)
{
	//CPaintDC dc;
	dc.SelectObject(GetStockObject(NULL_BRUSH));
	if (isShown) dc.Polygon(reinterpret_cast<const POINT *> (vertices), 3);
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
KTriangleFilled::KTriangleFilled(ClassPoint v1, ClassPoint v2, ClassPoint v3, int col) : KTriangle(v1, v2, v3)
{
	color = col;
}

KTriangleFilled::KTriangleFilled(const KTriangleFilled &t) : KTriangle(t)
{
	color = t.color;
}

KTriangleFilled& KTriangleFilled::operator = (const KTriangleFilled& c)
{
	for(int i = 0; i <= 2; i++) vertices[i] = c.vertices[i];
	color = c.color;
	return *this;
}

void KTriangleFilled::Draw(CPaintDC &dc)//?
{
	if (isShown)
	{
	//HBRUSH hBrush = CreateSolidBrush(RGB(color >> 16, (color >> 8) % 256, color % (256 * 256)));
	//CPen MyPen(PS_DASHDOT,1,RGB(0,0,0));
		//CPaintDC dc;
		CBrush MyBrush(RGB(color >> 16, (color >> 8) % 256, color % (256 * 256)));
		dc.SelectObject(MyBrush);
		dc.Polygon(reinterpret_cast<const POINT *> (vertices), 3);
		//dc.DeleteObject(MyBrush);
		dc.SelectObject(GetStockObject(NULL_BRUSH));
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
KCircleFilled::KCircleFilled(int r, ClassPoint c, int col) : KCircle(r,c)
{
	color = col;
}
KCircleFilled::KCircleFilled(const KCircleFilled &t) : KCircle(t)
{
	color = t.color;
}

KCircleFilled& KCircleFilled::operator = (const KCircleFilled& c)
{
	center = c.center;
	R = c.R;
	color = c.color;
	return *this;
}

void KCircleFilled::Draw(CPaintDC &dc)//?
{
	if (isShown)
	{
	//HBRUSH hBrush = CreateSolidBrush(RGB(color >> 16, (color >> 8) % 256, color % (256 * 256)));
	CBrush MyBrush(RGB(color >> 16, (color >> 8) % 256, color % (256 * 256)));
	dc.SelectObject(MyBrush);
	dc.Ellipse(center.x - R, center.y - R, center.x + R, center.y + R);
	//DeleteObject(hBrush);
	dc.SelectObject(GetStockObject(NULL_BRUSH));
	}
}