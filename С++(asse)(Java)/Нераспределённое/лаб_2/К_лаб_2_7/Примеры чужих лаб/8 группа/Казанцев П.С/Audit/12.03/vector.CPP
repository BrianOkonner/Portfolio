//класс вектор 
// Казанцев Павел Сергеевич
// 1 курс 8 группа
#include <cstdlib>
#include <iostream>
using namespace std;
struct bad_index
{
	int ind;
	bad_index(int i) :ind(i) {}
};

class Vect
{
	int size;
	int *vektor;
public:
	Vect(int size1) :size(size1), vektor(new int[size1]) {}
	~Vect() { delete[]vektor; }
	int& operator[](int index)
	{
		if (index<0 || index >= size)
			throw bad_index(index);
		return vektor[index];
	}
	friend  ostream&  operator<<(ostream& out, Vect& V)
	{
		for (int i = 0; i<V.size; i++)
			out << V[i] << " ";
		out << endl;
		return out;
	}
};
int main()
{
	Vect V1(3);
	try
	{
		V1[0] = 5;
		V1[1] = 6;
		V1[2] = 7;
		cout << V1;
		V1[0] = V1[2] + V1[1];
		cout << V1;
		V1[3] = 100;
	}
	catch (bad_index b)
	{
		cout << "bad_index = " << b.ind << endl;
	}
	system("PAUSE");
	return 0;
}