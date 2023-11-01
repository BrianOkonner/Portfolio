
//Класс точка
#include "class_point_h.h"
#include <iostream>
using namespace std;
void main()
{
	point A(10,10);
	point B(20,20);
	point C(30,30);
	point D;
	A=A+A+B+A+C;
	cout<<A;
}
		