#include <iostream>
#include <time.h>
using namespace std;

class Vector
{
public:
	Vector();					// конструктор по умолчанию
	Vector(int n);				// конструктор с параметром
	Vector(const Vector& temp); // конструктор копирования
	~Vector();					// декструктор
	void input();				// ввод элементов 
	void output();				// вывод элементов
	void add(const Vector& v1, const Vector& v2);// сложение двух векторов
private:
	int *p;
	int n;
};