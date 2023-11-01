#ifndef CIRCLE_CLASS
#define CIRCLE_CLASS

#include "Point3D.h"

class Circle: public Point3D{
	double radius;
public:
	Circle(const Point3D& p3d, double rr);
	void Draw();
	~Circle();
};
#endif; // CIRCLE_CLASS