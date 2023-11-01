// ����� � 8 ������
// �lass Ox

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;

class OX {
	int n;
public:
	OX() :n(10) {};
	OX(int);
	OX(const OX& a);
	~OX();
	OX& operator = (const OX& a) {
		OX b(a);
		cout << "�������� �������� = " << endl;;
		return b;
	}
	OX& operator += (const OX& a) {
		this->n += a.n;
		cout << "�������� �������� +=" << endl;
		return *this;
	}
	OX& operator -= (const OX& a) {
		this->n -= a.n;
		cout << "�������� �������� -=" << endl;
		return *this;
	}
	OX& operator *= (const OX& a) {
		this->n *= a.n;
		cout << "�������� �������� *=" << endl;
		return *this;
	}
	OX& operator /= (const OX& a) {
		this->n /= a.n;
		cout << "�������� �������� /=" << endl;
		return *this;
	}
	friend OX& operator - (const OX& a, const OX& b) {
		OX R(a);
		R -= b;
		cout << "�������� �������� -" << endl;
		return R;
	}
	friend OX& operator +(const OX& a, const OX& b) {
		OX R(a);
		R += b;
		cout << "�������� �������� +" << endl;
		return R;
	}
	friend OX& operator *(const OX& a, const OX& b) {
		OX R(a);
		R *= b;
		cout << "�������� �������� *" << endl;
		return R;
	}
	friend OX& operator /(const OX& a, const OX& b) {
		OX R(a);
		R /= b;
		cout << "�������� �������� /" << endl;
		return R;
	}
	friend ostream& operator << (ostream& out, const OX& a) {
		out << a.n << endl;
		return out;
	}
	friend istream& operator >> (istream& in, OX& a) {
		cin >> a.n;
		return in;
	}

};

OX::OX(int a) {
	n = a;
	cout << "�������� ���������� � ����������" << endl;
}
OX::OX(const OX&a) {
	this->n = a.n;
	cout << "�������� ���������� �����������" << endl;
}
OX::~OX() {
	cout << "�������� ����������" << endl;
}


int main() {
	setlocale(LC_ALL, "rus");
	int z = 15;
	OX a, b(z), c(b), d;
	d *= a;
	Sleep(400 );
	d += a;
	Sleep(400 );
	d -= a;
	Sleep(400 );
	d /= a;
	Sleep(400 );
	OX q;
	q = a + b;
	Sleep(400 );
	q = a - b;
	Sleep(400 );
	q = a * b;
	Sleep(400 );
	q = a / b;
	OX u;
	cout << endl << endl << c << endl;
	cin >> u;
	system("pause");
	return 0;
}


