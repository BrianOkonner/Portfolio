#include "Circle.h"

Circle::Circle(const Point3D& p3d, double rr): Point3D(p3d), radius(rr){

}

void Circle::Draw(){
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

 	glColor4d(col.R, col.G, col.B, col.Alpha);
	glTranslated(coordinate.x,
				 coordinate.y,
				 coordinate.z);
	auxSolidSphere(radius);

	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
};

Circle::~Circle(){
}