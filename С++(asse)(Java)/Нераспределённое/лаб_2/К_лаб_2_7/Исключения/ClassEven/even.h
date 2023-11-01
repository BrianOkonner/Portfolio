#include <iostream>

using namespace std;

struct NotEven {};
class  even
{
	int	n;
	// ������������
	even( );
public:
	even(const int&  _n);
	even(const even&  e);
	// �������
	even	next( )  const;	// ��������� ������ �����
	even	prev( )  const;	// ���������� ������ �����
	// ������� ���������
	even&	operator+=(const even&  e);
	even&	operator-=(const even&  e);
	even&	operator*=(const even&  e);
	// ������� + � -
	even&	operator-(void);
	even&	operator+(void);
	// ��������� ���������
	friend	bool	operator<(const even&  e1, const even&  e2);
	friend	bool	operator>(const even&  e1, const even&  e2);
	friend	bool	operator==(const even&  e1, const even&  e2);
	friend	bool	operator!=(const even&  e1, const even&  e2);
	friend	bool	operator<=(const even&  e1, const even&  e2);
	friend	bool	operator>=(const even&  e1, const even&  e2);
	// �������� �������������� ���������
	friend	even	operator+(const even&  e1, const even&  e2);
	friend	even	operator-(const even&  e1, const even&  e2);
	friend	even	operator*(const even&  e1, const even&  e2);
	// ��������� �����-������
	friend	istream&	operator>>(istream&  in, even&  e);
	friend	ostream&	operator<<(ostream&  out, const even&  e);
};
