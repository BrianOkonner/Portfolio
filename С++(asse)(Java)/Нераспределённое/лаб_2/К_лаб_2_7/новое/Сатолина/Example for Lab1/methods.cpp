#include "header.h"

Vector::Vector()			// конструктор по умолчанию
{
	cout << "input n for default constructor: ";  
	cin >> n;
	p = new int [n];
}
Vector::Vector(int n)		// конструктор с параметром
{
	this->n = n;
	p = new int [n];
}
Vector::Vector(const Vector& temp) // конструктор копирования
{
	n = temp.n;
	p = new int [n];
	for(int i = 0; i < n; ++i)
		p[i] = temp.p[i];
}
Vector::~Vector()			// декструктор
{
	delete []p;
	n = 0;
}
void Vector::input()		// ввод элементов 
{
	srand(time(0));
	for(int i = 0; i < n; ++i)
		p[i] = rand()%10;
}
void Vector::output()		// вывод элементов
{
	for(int i = 0; i < n; ++i)
		cout << p[i] << ' ';
	cout << endl;
}
void Vector::add(const Vector& v1, const Vector& v2)// сложение двух векторов
{
	if(v1.n == v2.n){
		for(int i = 0; i < n; ++i)
			this->p[i] = v1.p[i] + v2.p[i];
	}
	else
		throw "Error";
}