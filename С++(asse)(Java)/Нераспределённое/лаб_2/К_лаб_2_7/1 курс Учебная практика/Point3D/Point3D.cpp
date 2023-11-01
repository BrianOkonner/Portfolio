/*
 * Copyright: Pavel Lomonosov
 */
#include "Point3D.h"

/*************************************************************************/
/******************** Realization of struct Color ************************/
/*************************************************************************/

Color::Color(const Color &cc){
	R = cc.R;
	G = cc.G;
	B = cc.B;
	Alpha = cc.Alpha;
}

Color::Color(double RR, double GG, double BB, double Alp){
	R = RR;
	G = GG;
	B = BB;
	Alpha = Alp;
}

Color::Color(){
	R = G = B = Alpha = 0;
}
/*************************************************************************/
/******************** Realization of struct Coord ************************/
/*************************************************************************/

Coord::Coord(double xx, double yy, double zz){
	x = xx;
	y = yy;
	z = zz;
}

Coord::Coord(const Coord &cc){
	x = cc.x;
	y = cc.y;
	z = cc.z;
}

Coord::Coord(){
	x = y = z = 0;
}
/*************************************************************************/
/******************** Realization of class Point3D ***********************/
/*************************************************************************/

/////////////////////////////////////////////////////
//			Отрисовываем точку на экране
/////////////////////////////////////////////////////
void Point3D::Draw(){
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

 	glColor4d(col.R, col.G, col.B, col.Alpha);
	glTranslated(coordinate.x,
				 coordinate.y,
				 coordinate.z);
	auxSolidSphere(0.2);

	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
}

/////////////////////////////////////////////////////
//			Конструкторы класса точка
/////////////////////////////////////////////////////
Point3D::Point3D(){
	coordinate.x = 0;
	coordinate.y = 0;
	coordinate.z = 0;

	col.Alpha = col.B = col.G = col.R = 0;
}

Point3D::Point3D(double xx, double yy, double zz, const Color& cl){
	coordinate.x = xx;
	coordinate.y = yy;
	coordinate.z = zz;
	col = cl;
}

Point3D::Point3D(const Coord& c, const Color& cl){
	coordinate = c;
	col = cl;
}

Point3D::Point3D(const Point3D& p3d){
	coordinate = p3d.coordinate;
	col = p3d.col;
}

/////////////////////////////////////////////////////
//			Устанавливаем координаты
/////////////////////////////////////////////////////
double Point3D::getX()const{
	return coordinate.x;
}

double Point3D::getY()const{
	return coordinate.y;
}

double Point3D::getZ()const{
	return coordinate.z;
}

const Color& Point3D::getColor()const{
	return col;
}

const Coord& Point3D::getCoord()const{
	return coordinate;
}

/////////////////////////////////////////////////////
//			Считываем координаты
/////////////////////////////////////////////////////
void Point3D::setX(double xx){
	coordinate.x = xx;
}

void Point3D::setY(double yy){
	coordinate.y = yy;
}

void Point3D::setZ(double zz){
	coordinate.z = zz;
}

void Point3D::setColor(const Color& cl){
	col = cl;
}

void Point3D::setCoord(const Coord& c){
	coordinate = c;
}

/////////////////////////////////////////////////////
//			Присваиваем одну точку другой
/////////////////////////////////////////////////////
Point3D& Point3D::operator=(const Point3D& p3d){
	coordinate.x = p3d.coordinate.x;
	coordinate.y = p3d.coordinate.y;
	coordinate.z = p3d.coordinate.z;

	col.Alpha = p3d.col.Alpha;
	col.B = p3d.col.B;
	col.G = p3d.col.G;
	col.R = p3d.col.R;

	return *this;
}

/////////////////////////////////////////////////////
//			Складываем точку
/////////////////////////////////////////////////////
Point3D Point3D::operator+(const Point3D& p3d)const{
	Point3D sum(coordinate.x + p3d.coordinate.x,
				coordinate.y + p3d.coordinate.y,
				coordinate.z + p3d.coordinate.z, col);
	return sum;
}

Point3D Point3D::operator+(double dd)const{
	Point3D sum(coordinate.x + dd,
				coordinate.y + dd,
				coordinate.z + dd, col);
	return sum;
}

/////////////////////////////////////////////////////
//			Вычитаем точку
/////////////////////////////////////////////////////
Point3D Point3D::operator-(const Point3D& p3d)const{
	Point3D sum(coordinate.x - p3d.coordinate.x,
				coordinate.y - p3d.coordinate.y,
				coordinate.z - p3d.coordinate.z, col);
	return sum;
}

Point3D Point3D::operator-(double dd)const{
	Point3D sum(coordinate.x - dd,
				coordinate.y - dd,
				coordinate.z - dd, col);
	return sum;
}

/////////////////////////////////////////////////////
//			Унарные операторы
/////////////////////////////////////////////////////
Point3D Point3D::operator+(){
	return *this;
}

Point3D Point3D::operator-(){
	Point3D tmp(-coordinate.x, -coordinate.y, -coordinate.z, col);
	return tmp;
}

Point3D& Point3D::operator++(){
	coordinate.x++;
	coordinate.y++;
	coordinate.z++;

	return *this;
}

Point3D Point3D::operator++(int){
	return ++(*this);
}

Point3D& Point3D::operator--(){
	coordinate.x--;
	coordinate.y--;
	coordinate.z--;

	return *this;
}

Point3D Point3D::operator--(int){
	return ++(*this);
}

/////////////////////////////////////////////////////
//			Деструктор
/////////////////////////////////////////////////////
Point3D::~Point3D(){
}

/////////////////////////////////////////////////////
//			Скалярное произведение
/////////////////////////////////////////////////////
double Point3D::operator*(const Point3D& p3d){
	double result;
	result = coordinate.x*p3d.coordinate.x + 
			 coordinate.y*p3d.coordinate.y + 
			 coordinate.z*p3d.coordinate.z;
	return result;
}