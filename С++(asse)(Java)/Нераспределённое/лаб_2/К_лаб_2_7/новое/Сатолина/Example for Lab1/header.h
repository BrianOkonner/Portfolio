#include <iostream>
#include <time.h>
using namespace std;

class Vector
{
public:
	Vector();					// ����������� �� ���������
	Vector(int n);				// ����������� � ����������
	Vector(const Vector& temp); // ����������� �����������
	~Vector();					// �����������
	void input();				// ���� ��������� 
	void output();				// ����� ���������
	void add(const Vector& v1, const Vector& v2);// �������� ���� ��������
private:
	int *p;
	int n;
};