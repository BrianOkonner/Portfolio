/*������������ ���������
  8 ������
  �������:������� 1  ����� �����.
����������� ��������� ������ ��� ��������� ��������� �� ���������  ( � ������������) �������� ���������  ��� �������� ���������� �������� � ������������ �����. 

�����������  ������ ��� :
a)	������� �����������, ����������� �����������, ����������.
b)	��������� ���������� ��������, �������� ������� ��� ��������� +, -, *(��������� �� �����),  /(������� �� �����), ++,--,=,==, !=, >=,<=, [] - ��� ������ ������.
c)	��������� ���������� ��������, �������� ������� ��� ��������� ���������� �������� +, -, *, ��� ������������� �������..
d)	�������� ������������:  ���������� ����������<<,>>, ��� ������������� �������.
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
