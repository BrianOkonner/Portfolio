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
	Vector();//конструкторы
	Vector(int _size);
	Vector(const Vector & B);
	~Vector();//деструктор
	//перегрузка операторов
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
	int search(int key);//поиск элемента 
	void setVector();//задание вектора
	int getSize();//узнать размер
	int front();//показать первый элемент
	int back();//показать последний элемент
	bool isEmpty();//проверка на пустоту
	Vector push_back(int a);//добавить элемент в конец
	void pop_back();//удалить последний элемент
};


