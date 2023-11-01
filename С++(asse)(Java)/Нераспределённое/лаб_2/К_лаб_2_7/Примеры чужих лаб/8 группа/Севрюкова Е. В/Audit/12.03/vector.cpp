/*  
	12.03
	1 курс
	8 группа
	Севрюкова Елизавета

*/
#include <iostream>
#include <fstream>
using namespace std;

class vector {
	int n;
	int *a;
public:
	vector();
	vector(int k) { n = k; a = new int[n]; }
	~vector();
	vector(const vector &);
	friend istream& operator >>(istream &, vector &);
	friend ostream& operator <<(ostream &, vector &);
	vector operator +(vector b);
	vector & operator =(vector b);
	friend vector operator+(vector b, int k);
	friend vector operator+(int k, vector b);
};
vector::vector()
{
	n = 0;
	a = NULL;
}
vector::~vector()
{
	delete[]a;
}

vector::vector(const vector & b)
{
	n = b.n;
	a = new int[n];
	for (int i = 0; i<n; i++)
		a[i] = b.a[i];
}

vector vector::operator +(vector b)
{
	vector c;
	c.n = n;
	c.a = new int[n];
	for (int i = 0; i<n; i++)
		c.a[i] = a[i] + b.a[i];
	return c;
}
vector &vector::operator =(vector b)
{
	if (a != NULL)
		delete[]a;
	a = new int[b.n];
	n = b.n;
	for (int i = 0; i<n; i++)
		a[i] = b.a[i];
	return (*this);
}
vector operator+(vector b, int k)
{
	vector c;
	if (b.n != 0)
	{
		c.n = b.n;
		c.a = new int[c.n];
		for (int i = 0; i<b.n; i++)
			c.a[i] = b.a[i] + k;
	}
	else { c.n = 0; c.a = NULL; }
	return c;
}
vector operator+(int k, vector b)
{
	vector c;
	if (b.n != 0)
	{
		c.n = b.n;
		c.a = new int[c.n];
		for (int i = 0; i<b.n; i++)
			c.a[i] = b.a[i] + k;
	}
	else { c.n = 0; c.a = NULL; }
	return c;
}

istream & operator>>(istream &in, vector &b)
{
	int k;
	cout << "input razmer prostranstva\n";
	in >> k;

	if (k != 0)
	{
		b.n = k;
		b.a = new int[k];
		cout << "Vvedite elementi\n";
		for (int i = 0; i<b.n; i++)
		{
			in >> k;
			b.a[i] = k;
		}
	}
	return in;
}
ostream & operator <<(ostream &out, vector &b)
{
	if (b.n != 0)
	{
		for (int i = 0; i<b.n; i++)
			out << b.a[i] << ' ';
	}
	else out << "vector zerow";
	return out;
}

void main()
{
	vector a, b, c(3);
	cin >> a >> b;
	c = a + b;
	cout << c;
	system("pause");
}
