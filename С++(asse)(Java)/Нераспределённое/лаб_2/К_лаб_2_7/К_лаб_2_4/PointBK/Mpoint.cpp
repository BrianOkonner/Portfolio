//Класс точка
// Функции описаны внутри класса
#include "point.h"
#include <iostream>

using namespace std;
void main()
{
	point A(10,10);
	point B(20,20);
	point C(30,30);
	point D2,D,D1(5);
	D2=A;
	A=A+A+B+A+C;
	//D2.Print();
	A.Print();
}
		