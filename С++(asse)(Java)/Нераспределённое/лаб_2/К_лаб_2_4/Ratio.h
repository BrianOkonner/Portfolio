// ��������� ������ rational
#include <iostream.h>

struct Zero_divide {};

class ratio
{
	long n, d;		// ��������� � �����������
	void Reduce();	// ��������� �����
public:
		// ������������
	ratio();
	ratio(long n, long d);
	ratio(const ratio& r);
		// �������� ������������
	ratio& operator = (const ratio& r);
		// ������� ���������
	ratio& operator += (const ratio& r);
	ratio& operator -= (const ratio& r);
	ratio& operator *= (const ratio& r);
	ratio& operator /= (const ratio& r);
		// �������� �������������� ����
	operator double(void) const; 
		// ������� ����� � ����
	friend ratio operator -(const ratio& r);
	friend ratio operator +(const ratio& r);
		// ��������� ���������
	friend bool operator < (const ratio& r1, const ratio& r2);
	friend bool operator > (const ratio& r1, const ratio& r2);
	friend bool operator == (const ratio& r1, const ratio& r2);
	friend bool operator != (const ratio& r1, const ratio& r2);
	friend bool operator <= (const ratio& r1, const ratio& r2);
	friend bool operator >= (const ratio& r1, const ratio& r2);
		// �������� ���������
	friend ratio operator + (const ratio& r1, const ratio& r2);
	friend ratio operator - (const ratio& r1, const ratio& r2);
	friend ratio operator * (const ratio& r1, const ratio& r2);
	friend ratio operator / (const ratio& r1, const ratio& r2);
		// ��������� �����-������
	friend istream& operator>>(istream& in, ratio& r);
	friend ostream& operator<<(ostream& out, const ratio& r);

};
	
		


