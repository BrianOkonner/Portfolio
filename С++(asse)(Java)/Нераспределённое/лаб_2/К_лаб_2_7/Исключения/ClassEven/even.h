#include <iostream>

using namespace std;

struct NotEven {};
class  even
{
	int	n;
	// конструкторы
	even( );
public:
	even(const int&  _n);
	even(const even&  e);
	// функции
	even	next( )  const;	// следующее четное число
	even	prev( )  const;	// предыдущее четное число
	// унарные операторы
	even&	operator+=(const even&  e);
	even&	operator-=(const even&  e);
	even&	operator*=(const even&  e);
	// унарный + и -
	even&	operator-(void);
	even&	operator+(void);
	// операторы сравнения
	friend	bool	operator<(const even&  e1, const even&  e2);
	friend	bool	operator>(const even&  e1, const even&  e2);
	friend	bool	operator==(const even&  e1, const even&  e2);
	friend	bool	operator!=(const even&  e1, const even&  e2);
	friend	bool	operator<=(const even&  e1, const even&  e2);
	friend	bool	operator>=(const even&  e1, const even&  e2);
	// бинарные арифметические операторы
	friend	even	operator+(const even&  e1, const even&  e2);
	friend	even	operator-(const even&  e1, const even&  e2);
	friend	even	operator*(const even&  e1, const even&  e2);
	// операторы ввода-вывода
	friend	istream&	operator>>(istream&  in, even&  e);
	friend	ostream&	operator<<(ostream&  out, const even&  e);
};
