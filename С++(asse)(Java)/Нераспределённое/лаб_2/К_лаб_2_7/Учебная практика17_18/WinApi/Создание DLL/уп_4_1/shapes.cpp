//Беличенко Алексей 1 курс 7 группа
#include "shapes.h"
#include <cmath>

KCircle::KCircle(int r, POINT c) : KShape()
{
	rad = r;
	center = c;
	isShown = true;
}

KCircle::KCircle(int r = 1)
{
	rad = r;
	isShown = true;
}

KCircle::KCircle(const KCircle & c) : KShape(c)
{
	center = c.center;
	rad = c.rad;
	isShown = c.isShown;
}

void KCircle::SetRad(int r)
{
	rad = r;
}

void KCircle::SetCenter(const POINT& p)
{
	center = p;
}

KCircle& KCircle::operator = (const KCircle& c)
{
	center = c.center;
	rad = c.rad;
	isShown = c.isShown;
	return *this;
}

void KCircle::Shift(int dx, int dy)
{
	center.x += dx;
	center.y += dy;
}

void KCircle::MoveTo(const POINT& p)
{
	center = p;
}

void KCircle::Explode(double x)
{
	rad *= x;
}

void KCircle::Draw(HDC hdc)
{
	SelectObject(hdc,GetStockObject(NULL_BRUSH));
	if (isShown) Ellipse(hdc,center.x - rad, center.y - rad, center.x + rad, center.y + rad);
}

KTriangle::KTriangle(POINT v1, POINT v2, POINT v3) : KShape()
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

POINT KTriangle::Center()
{
	POINT tmp;
	tmp.x = (vertices[0].x + vertices[1].x + vertices[2].x)/3;
	tmp.y = (vertices[0].y + vertices[1].y + vertices[2].y)/3;
	return tmp;
}

int KTriangle::Radius()
{
	POINT tmp = this->Center();
	POINT tmp2 = vertices[0];
	int res = sqrt((double)((tmp.x - tmp2.x) * (tmp.x - tmp2.x)) + ((tmp.y - tmp2.y) * (tmp.y - tmp2.y)));
	return res;
}

void KTriangle::Shift(int dx, int dy)
{
	for (int i = 0; i < 3; i++)
	{
		vertices[i].x += dx;
		vertices[i].y += dy;
	}
}

void KTriangle::Explode(double k)
{
	POINT tmp = this->Center();
	if (k != 1)
	{
		for (int i = 0; i < 3; i++)
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
		POINT tmp = this->Center();
		for (int i = 0; i < 3; i++)
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

void KTriangle::MoveTo(const POINT& p)
{
	int dx = Center().x - p.x;
	int dy = Center().y - p.y;
	Shift(dx, dy);
}

void KTriangle::Draw(HDC hdc)
{
	SelectObject(hdc,GetStockObject(NULL_BRUSH));
	if (isShown) Polygon(hdc, vertices, 3);
}

KTriangleFilled::KTriangleFilled(POINT v1, POINT v2, POINT v3, int col) : KTriangle(v1, v2, v3)
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

void KTriangleFilled::Draw(HDC hdc)
{
	if (isShown)
	{
		HBRUSH hBrush = CreateSolidBrush(RGB(color >> 16, (color >> 8) % 256, color % (256 * 256)));
		SelectObject(hdc, hBrush);
		Polygon(hdc, vertices, 3);
		DeleteObject(hBrush);
		SelectObject(hdc,GetStockObject(NULL_BRUSH));
	}
}

KCirclePartFilled::KCirclePartFilled(int r, POINT c, double a1, double a2, int col) : KCircle(r, c)
{
	color = col;
	angle1 = a1;
	angle2 = a2;
}

KCirclePartFilled::KCirclePartFilled(const KCirclePartFilled &c) : KCircle(c)
{
	center = c.center;
	rad = c.rad;
	isShown = c.isShown;
	color = c.color;
	angle1 = c.angle1;
	angle2 = c.angle2;
}

KCirclePartFilled& KCirclePartFilled::operator =(const KCirclePartFilled &c)
{
	color = c.color;
	angle1 = c.angle1;
	angle2 = c.angle2;
	return *this;
}

void KCirclePartFilled::Draw(HDC hdc)
{
	if (isShown)
	{
		SelectObject(hdc,GetStockObject(NULL_BRUSH));
		Ellipse(hdc, center.x - rad, center.y - rad, center.x + rad, center.y + rad);
		HBRUSH hBrush = CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
		SelectObject(hdc, hBrush);
		Chord(hdc, center.x - rad, center.y - rad, center.x + rad, center.y + rad,	//координаты эллипса
			center.x + cos(angle1) * rad, center.y - sin(angle1) * rad,	//координаты первой точки
			center.x + cos(angle2) * rad, center.y - sin(angle2) * rad);//и второй
		DeleteObject(hBrush);
		SelectObject(hdc,GetStockObject(NULL_BRUSH));

		//минусы в y, чтобы углы считались традиционно
	}
}

KCirclePunched::KCirclePunched(int r, POINT c, int rIn) : KCircle(r, c)
{
	radIn = rIn;
}

KCirclePunched::KCirclePunched(const KCirclePunched &c) : KCircle(c)
{
	radIn = c.radIn;
}

KCirclePunched& KCirclePunched::operator =(const KCirclePunched &c)
{
	center = c.center;
	rad = c.rad;
	isShown = c.isShown;
	radIn = c.radIn;
	return *this;
}

void KCirclePunched::Draw(HDC hdc)
{
	if (isShown)
	{
		SelectObject(hdc,GetStockObject(NULL_BRUSH));
		Ellipse(hdc, center.x - rad, center.y - rad, center.x + rad, center.y + rad);
		Ellipse(hdc, center.x - radIn, center.y - radIn, center.x + radIn, center.y + radIn);
	}
}

void KCirclePunched::Explode(double x)
{
	rad *= x;
	radIn *= x;
}