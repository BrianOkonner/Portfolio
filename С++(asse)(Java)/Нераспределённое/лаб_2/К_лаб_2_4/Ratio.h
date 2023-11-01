// интерфейс класса rational
#include <iostream.h>

struct Zero_divide {};

class ratio
{
	long n, d;		// числитель и знаменатель
	void Reduce();	// сокращает дробь
public:
		// конструкторы
	ratio();
	ratio(long n, long d);
	ratio(const ratio& r);
		// оператор присваивания
	ratio& operator = (const ratio& r);
		// унарные операторы
	ratio& operator += (const ratio& r);
	ratio& operator -= (const ratio& r);
	ratio& operator *= (const ratio& r);
	ratio& operator /= (const ratio& r);
		// оператор преобразования типа
	operator double(void) const; 
		// унарный минус и плюс
	friend ratio operator -(const ratio& r);
	friend ratio operator +(const ratio& r);
		// операторы сравнения
	friend bool operator < (const ratio& r1, const ratio& r2);
	friend bool operator > (const ratio& r1, const ratio& r2);
	friend bool operator == (const ratio& r1, const ratio& r2);
	friend bool operator != (const ratio& r1, const ratio& r2);
	friend bool operator <= (const ratio& r1, const ratio& r2);
	friend bool operator >= (const ratio& r1, const ratio& r2);
		// бинарные операторы
	friend ratio operator + (const ratio& r1, const ratio& r2);
	friend ratio operator - (const ratio& r1, const ratio& r2);
	friend ratio operator * (const ratio& r1, const ratio& r2);
	friend ratio operator / (const ratio& r1, const ratio& r2);
		// операторы ввода-вывода
	friend istream& operator>>(istream& in, ratio& r);
	friend ostream& operator<<(ostream& out, const ratio& r);

};
	
		


