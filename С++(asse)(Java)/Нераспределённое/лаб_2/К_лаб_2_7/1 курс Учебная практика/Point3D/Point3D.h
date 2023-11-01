#ifndef POINT3D_CLASS
#define POINT3D_CLASS

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

struct Color{
	double R,	// ������� ����������
		   G,	// ������� ����������
		   B,	// ����� ����������
		   Alpha;	// ������������ �����

	// �������������
	Color(const Color& cc);
	Color();
	Color(double RR, double GG, double BB, double Alp);
};

struct Coord{
	double x, y, z;	// ��������������� ����������

	// ������������
	Coord(const Coord& cc);
	Coord();
	Coord(double xx, double yy, double zz);
};

class Point3D{
protected:
	Coord coordinate;	// ��������� ������������� ����������
	Color col;			// ����
public:
	// ������������
	Point3D(double xx, double yy, double zz, const Color& cl);
	Point3D(const Coord& c, const Color& cl);
	Point3D(const Point3D& p3d);
	Point3D();

	// ������������� ���������
	double getX()const;
	double getY()const;
	double getZ()const;
	const Color& getColor()const;
	const Coord& getCoord()const;

	// ��������� ���������
	void setX(double xx);
	void setY(double yy);
	void setZ(double zz);
	void setColor(const Color& cl);
	void setCoord(const Coord& c);

	// ������������ ����� �� ������
	virtual void Draw();

	// ����������� ���� ����� ������
	Point3D& operator=(const Point3D& p3d);

	// ���������� �����
	Point3D operator+(const Point3D& p3d)const;
	Point3D operator+(double dd)const;

	// �������� �����
	Point3D operator-(const Point3D& p3d)const;
	Point3D operator-(double dd)const;

	// ������� ���������
	Point3D operator+();
	Point3D& operator++();
	Point3D operator++(int);

	Point3D operator-();
	Point3D& operator--();
	Point3D operator--(int);

	// ��������� ������������
	double operator*(const Point3D& p3d);

	// ����������
	virtual ~Point3D();
};
#endif; // POINT3D_CLASS