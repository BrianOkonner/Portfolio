#include "header.h"

Vector::Vector()			// ����������� �� ���������
{
	cout << "input n for default constructor: ";  
	cin >> n;
	p = new int [n];
}
Vector::Vector(int n)		// ����������� � ����������
{
	this->n = n;
	p = new int [n];
}
Vector::Vector(const Vector& temp) // ����������� �����������
{
	n = temp.n;
	p = new int [n];
	for(int i = 0; i < n; ++i)
		p[i] = temp.p[i];
}
Vector::~Vector()			// �����������
{
	delete []p;
	n = 0;
}
void Vector::input()		// ���� ��������� 
{
	srand(time(0));
	for(int i = 0; i < n; ++i)
		p[i] = rand()%10;
}
void Vector::output()		// ����� ���������
{
	for(int i = 0; i < n; ++i)
		cout << p[i] << ' ';
	cout << endl;
}
void Vector::add(const Vector& v1, const Vector& v2)// �������� ���� ��������
{
	if(v1.n == v2.n){
		for(int i = 0; i < n; ++i)
			this->p[i] = v1.p[i] + v2.p[i];
	}
	else
		throw "Error";
}