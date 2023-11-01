#include <iostream>
#include "even.h"
using namespace std;

	// конструкторы
even::even(const int&  _n)
{
	if (_n % 2)
		throw NotEven();
	n = _n;
}
even::even(const even&  e): n(e.n) {}

	// функции
even	even::next( )  const	// следующее четное число
{
	return  even(n + 2);
}
even	even::prev( )  const	// предыдущее четное число
{
	return even(n - 2);
}
	// унарные операторы
even&	even::operator+=(const even&  e) 
{ 
	n += e.n;
	return *this;
}
even&	even::operator-=(const even&  e) 
{ 
	n -= e.n;
	return *this;
}
even&	even::operator*=(const even&  e) 
{ 
	n *= e.n;
	return *this;
}
	// унарный + и -
even&	even::operator-(void) 
{ 
	n = -n;
	return *this;
}
even&	even::operator+(void)
{
	return *this;
}
	// операторы сравнения
bool	operator<(const even&  e1, const even&  e2)
{
	return (e1.n < e2.n);
}
bool	operator>(const even&  e1, const even&  e2)
{
	return (e1.n > e2.n);
}
bool	operator==(const even&  e1, const even&  e2)
{
	return (e1.n == e2.n);
}
bool	operator!=(const even&  e1, const even&  e2)
{
	return (e1.n != e2.n);
}
bool	operator<=(const even&  e1, const even&  e2)
{
	return (e1.n <= e2.n);
}
bool	operator>=(const even&  e1, const even&  e2)
{
	return (e1.n >= e2.n);
}
	// бинарные арифметические операторы
even operator+(const even&  e1, const even&  e2)
{
	return  even(e1.n + e2.n);
}
even	operator-(const even&  e1, const even&  e2)
{
	return even(e1.n - e2.n);
}
even	operator*(const even&  e1, const even&  e2)
{
	return (e1.n * e2.n);
}
	// операторы ввода-вывода
istream&	operator>>(istream&  in, even&  e)
{
	if (e.n % 2)
		throw NotEven();
	return in >> e.n;
}
ostream&	operator<<(ostream&  out, const even&  e)
{
	return  out << e.n;
}



