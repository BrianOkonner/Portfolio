#include "Vector.h"
#include <vector>



Vector::Vector()
{
	size = 10;
	A = new int[size];
}

Vector::Vector(int _size)
{
	size = _size;
	A = new int[size];
}

Vector::Vector(const Vector & B)
{
	size = B.size;
	A = new int[size];
	for (int i = 0; i < size; i++)
		A[i] = B.A[i];
}

int Vector::getSize()
{
	return size;
}

Vector::~Vector()
{
	delete[]A;
}

Vector& Vector::operator=(const Vector & B)
{
		
		
			delete[]A;
			size = B.size;
			A = new int[size];
		
		for (int i = 0; i < size; i++)
			A[i] = B.A[i];
	return *this;
}

bool Vector::operator==(const Vector & B)
{
	if (size != B.size)
		return false;
	for (int i = 0; i < size; i++)
		if (A[i] != B.A[i])
			return false;
		else
	return true;
}

Vector Vector::operator +(const Vector & B)
{
	if (size == B.size)
	{
		Vector C(size);
		C.A = new int[C.size];
		for (int i = 0; i < size; i++)
			C.A[i] = A[i] + B.A[i];
		return C;
	}
	else {
		Bad_dimensions err;
		throw err;
	}
}
Vector Vector::operator -(const Vector & B)
{
	if (size == B.size)
	{
		Vector C(size);
		C.A = new int[C.size];
		for (int i = 0; i < size; i++)
			C.A[i] = A[i] - B.A[i];
		return C;
	}
	else {
		Bad_dimensions err;
		throw err;
	}
}


istream &operator >>(istream & in, Vector & B)
{
	int n, k;
	cout << "Введите размер вектора - " << endl;
	cin >> n;
	if (n != 0)
	{
		B.size = n;
		B.A = new int[n];
		cout << "Введите элементы:" << endl;
		for (int i = 0; i < n; i++)
		{
			in >> k;
			B.A[i] = k;
		}
	}
	return in;
}

ostream &operator <<(ostream & out, Vector & B)
{
	if (B.size != 0)
	{
		for (int i = 0; i < B.size; i++)
			cout << B.A[i] << " ";
	}
	else cout << "Вектор пуст!" << endl;
	return out;
}

int& Vector::operator[](int index)
{
	if (index<0 || index>size)
	{
		Bad_dimensions err;
		throw err;
	}
	return A[index];
}

Vector& Vector::operator+=(int a)
{
	Vector C(size);
	C = *this;
	delete[]A;
	size = size + 1;
	A = new int[size];
	for (int i = 0; i < (size - 1); i++)
		A[i] = C.A[i];
	A[size - 1] = a;
	return *this;
}

int Vector::search(int key)
{
	for (int i = 0; i < size; i++)
		if (A[i] == key)
			return i + 1;
	return -1;
}

void Vector::setVector()
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		A[i] = rand() % 100;
}

int Vector::front()
{
	return A[0];
}

int Vector::back()
{
	return A[size - 1];
}

bool Vector::isEmpty()
{
	if (size = 0)
		return true;
	return false;
}

Vector Vector::push_back(int a)
{
	Vector C(*this);
	delete[]A;
	size = size + 1;
	A = new int[size];
	for (int i = 0; i < (size - 1); i++)
		A[i] = C.A[i];
	A[size - 1] = a;
	return *this;
}

void Vector::pop_back()
{
	Vector C(*this);
	delete[]A;
	size = size - 1;
	A = new int[size];
	for (int i = 0; i < size; i++)
		A[i] = C.A[i];
}

Vector& Vector::operator*(const Vector & B)
{
	if (size != B.size)
	{
		cout << "Error" << endl;
		exit(1);
	}
	Vector C(size);
	for (int i = 0; i < size; i++)
		C.A[i] = A[i] * B.A[i];
	return C;
}

Vector& Vector::operator*=(int a)
{
	for (int i = 0; i < size; i++)
		A[i] = A[i] * a;
	return *this;
}

