#include <iostream>
using namespace std;
class matr
{
	int **m;
	int n;
public:
	matr(int n)
	{
		m=new int*[n];
		for(int i=0;i<n;i++)
			m[i]=new int[n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				m[i][j]=0;
	}
	matr& operator = (matr& ma)
	{
	n = ma.n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			m[i][j] = ma.m[i][j];
	return *this;
	}
	matr& operator +=(matr& ma)
	{
		if( n == ma.n )
		{
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					m[i][j] += ma.m[i][j];
		}
		else cout << "Incorrect dimension" << endl;
		return *this;
	}
	matr& operator -=(matr& ma)
	{
		if( n == ma.n )
		{
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					m[i][j] -= ma.m[i][j];
		}
		else cout << "Incorrect dimension" << endl;
		return *this;
	}
	friend ostream& operator << (ostream &out,matr &ma)
	{
		for(int i = 0; i < ma.n; i++)
		{
			for(int j = 0; j < ma.n; j++)
				out << ma.m[i][j] << "  ";
			out <<endl;
		}
		return out;
	}
	friend istream& operator >> (istream &in,matr &ma)
	{  
		in >> ma.n;
		for(int i = 0; i < ma.n; i++)
		{
			for(int j = 0; j < ma.n; j++)
				in >> ma.m[i][j];
		}
		return in;
	}
	int* operator [] (int i)
	{   	
		return m[i];
	}
	int matdim()
	{
		return n;
	}
};