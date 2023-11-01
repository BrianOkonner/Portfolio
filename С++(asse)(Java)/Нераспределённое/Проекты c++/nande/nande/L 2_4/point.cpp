/*Перевязчиков Владислав
  8 группа
  Условие:Задание 1  Класс точка.
Разработать интерфейс класса для обработки координат на плоскости  ( в пространстве) Написать программу  для проверки выполнения операций с координатами точек. 

Реализовать  классы для :
a)	имеющий конструктор, конструктор копирования, деструктор.
b)	Выполнить перегрузку операций, написать функции для обработки +, -, *(умножение на число),  /(деление на число), ++,--,=,==, !=, >=,<=, [] - как членов класса.
c)	Выполнить перегрузку операций, написать функции для обработки нескольких объектов +, -, *, как дружественные функции..
d)	операции ввода–вывода:  перегрузку операторов<<,>>, как дружественные функции.
*/#include "point.h"
point::point(double i,double j,double k)
{
	x=i;
	y=j;
	z=k;
}
point::point(const point &q)
{
	x=q.x;
	y=q.y;
	z=q.z;
}
point::~point()
{
	x=0;
	y=0;
	z=0;
}
point point::operator*(double q)
{ 
	point buf(0,0,0);
	buf.x*=q;
	buf.y*=q;
	buf.z*=q;
	return buf;
}
point point::operator/(double q)
{ 
	point buf(0,0,0);
	buf.x/=q;
	buf.y/=q;
	buf.z/=q;
	return buf;
}
point point::operator+()
{
	return *this;
}
point point::operator-()
{
	point buf(0,0,0);
	buf.x=-x;
	buf.y=-y;
	buf.z=-z;
	return buf;
}
point point::operator++()
{
	++x;
	++y;
	++z;
	return *this;
}
point point::operator++(int)
{
	point buf(*this);
	x++;
	y++;
	z++;
	return buf;
}
point point::operator--()
{
	--x;
	--y;
	--z;
	return *this;
}
point point::operator--(int)
{
	point buf(*this);
	x--;
	y--;
	z--;
	return buf;
}
bool point::operator<=(point q)
{
	if(x+y+z<=q.x+q.y+q.z)
		return true;
	else 
		return false;
}
bool point::operator>=(point q)
{
	if(x+y+z>=q.x+q.y+q.z)
		return true;
	else 
		return false;
}
bool point::operator<(point q)
{
	if(x+y+z<q.x+q.y+q.z)
		return true;
	else 
		return false;
}
bool point::operator>(point q)
{
	if(x+y+z>=q.x+q.y+q.z)
		return true;
	else 
		return false;
}
bool point::operator==(point q)
{
	if(x==q.x&&y==q.y&&z==q.z)
		return true;
	else 
		return false;
}
bool point::operator!=(point q)
{
	if(x==q.x&&y==q.y&&z==q.z)
		return false;
	else 
		return true;
}
point point::operator=(point q)
{	
	x=q.x;
	y=q.y;
	z=q.z;
	return *this;
}
point operator +(point q,point e)
{
	q.x+=e.x;
	q.y+=e.y;
	q.z+=e.z;
	return q;
}
ostream& operator <<(ostream& out,point q)
{
	out<<"("<<q.x<<" "<<q.y<<" "<<q.z<<")";
	return out;
}
point operator -(point q,point e)
{
	q.x-=e.x;
	q.y-=e.y;
	q.z-=e.z;
	return q;
}
point operator *(point q,point e)
{
	q.x*=e.x;
	q.y*=e.y;
	q.z*=e.z;
	return q;
}
istream& operator >>(istream &in,point &q)
{
	in>>q.x>>q.y>>q.z;
	return in;
}
int main()
{
	point q(0,0,0),e(1,2,3),c(e);
	cin>>q;
	q=-e;
	if(q>e)e++;
	q=q+e*(c-q);
		cout<<q;
	system("pause");
	return 0;
}
