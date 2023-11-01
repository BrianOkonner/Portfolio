#include <iostream>
#include <time.h>

// матрица 
// вектор
// умножить матрицу на вектор


using namespace std;

struct bad_index
{
	int ind;
	bad_index(int i) :ind(i){};
};


class vect
{
	int n, *a;
public:
	vect(int n);
	~vect();
	friend int mul(vect&v1, vect&v2);
	int gets();
	void out();
	void set(int i, int x);
	void set(int *a);
};

vect::vect(int m)
{
	a = new int[m];
	n = m;
}

vect::~vect()
{
	delete[]a;
}

int vect::gets()
{
	return n;
}

int mul(vect &v1, vect &v2)
{
	int res = 0;
	if (v1.n != v2.n) throw 2;

	for (int i = 0; i< v1.n; i++)

	{
		res += v1.a[i]*v2.a[i];
	}
	return res;
}

void vect::out()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void vect::set(int i, int x)
{
	a[i] = x;
}


class matrix
{
	int row, col;
	int **a;
public:
	matrix(int n, int m) :row(n), col(m)
	{
		a = new int*[n];
		for (int i = 0; i < n; i++)
			a[i] = new int[m];

	}
	~matrix()
	{
		for (int i = 0; i < row; i++)
			delete[] a[i];
		delete[] a;
	}

	void set(int i, int j, int x)
	{
		a[i][j] = x;
	}

	vect& getRow(int num)
	{
		vect *element;
		element = new vect(col);
		for (int i = 0; i < col; i++)
			element->set(i, a[num][i]);
		return *element;
	}
	friend vect mul(matrix&, vect&);


};

vect mul(matrix& Ma, vect& V)
{
	if (Ma.col != V.gets()) throw 2;
	vect *el;
	el = new vect(V.gets());

	for (int i = 0; i < Ma.col; i++)
	{
		el->set(i, mul(Ma.getRow(i), V));
	}
	return *el;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int n, m, x;
	cout << "¬ведите размер матрицы: ";
	cin >> n >> m;

	matrix Ma(n, m);
	cout << "¬ведите матрицу: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			Ma.set(i, j, x);
		}
	}

	cout << "¬ведите размер вектора: ";
	cin >> n;

	vect V(n);
	cout << "¬ведите вектор: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		V.set(i, x);
	}

	try{
		mul(Ma, V).out();
	}
	catch (...)
	{
		cout << "Error!" << endl;
	}
}
