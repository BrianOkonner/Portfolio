#pragma once
#include <iostream>
#include <ctime>
using namespace std;

struct Bad_dimensions {};

class Vector
{
	int * A;
	int size;
public:
	Vector();//������������
	Vector(int _size);
	Vector(const Vector & B);
	~Vector();//����������
	//���������� ����������
	Vector & operator=(const Vector & B);
	Vector operator +(const Vector & B);
	bool operator==(const Vector & B);
	Vector & operator+=(int a);
    Vector operator-(const Vector & B);
	Vector & operator*(const Vector & B);
	Vector & operator*=(int a);
	int & operator [](int index);

	friend istream &operator >>(istream & in, Vector & B);
	friend ostream &operator <<(ostream & out, Vector & B);
	int search(int key);//����� �������� 
	void setVector();//������� �������
	int getSize();//������ ������
	int front();//�������� ������ �������
	int back();//�������� ��������� �������
	bool isEmpty();//�������� �� �������
	Vector push_back(int a);//�������� ������� � �����
	void pop_back();//������� ��������� �������
};


