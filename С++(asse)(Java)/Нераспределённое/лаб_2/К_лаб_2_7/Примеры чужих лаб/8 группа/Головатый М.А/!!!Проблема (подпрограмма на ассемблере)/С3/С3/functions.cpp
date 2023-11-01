#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "functions.h"
const double pi = 3.14159265;



void ShellSort(int n, int mass[])
{
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = mass[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < mass[j - step])
					mass[j] = mass[j - step];
				else
					break;
			}
			mass[j] = tmp;
		}
}
int binary_search(int array[], int key, int left, int right,int &count)
{
	int middle;
	while (key <= left)
	{
		count++;
		middle = (key + left) / 2;
		if (right == array[middle])
			return array[middle];
		else
			if (right > array[middle])
				key = middle + 1;
			else left = middle - 1;
	}
	return -1;
}
int BinarySearch_Iter(int array[], int key,int left,int right,int &count)
{
	int mid = 0;

	while (!(left >= right))
	{
		count++;
		mid = left + (right - left) / 2;

		if (array[mid] == key)
			return array[mid];

		if (array[mid] > key)
			right = mid;
		else
			left = mid + 1;
	}

	return -(1 + left);
}
int binary_search_rec(int array[], int key, int left, int right,int &count)
{
	count++;
	int mid = left + (right - left) / 2;

	if (left >= right)
		return -(1 + left);

	if (array[mid] == key)
		return array[mid];

	else if (array[mid] > key)
		return binary_search_rec(array, key, left, mid,count);
	else
		return binary_search_rec(array, key, mid + 1, right,count);
}

void random_numbers_in_file(void) // создаёт файл input.txt и заполняет его случайными числами
{
	using namespace std;
	setlocale(0, "");
	ofstream out;
	out.open("input.txt");
	srand(time(NULL));
	for (int i = 0; i < 200; i++)
	{
		out << setw(5) << rand() % 100 << "  ";
		if (i % 6 == 5) out << endl;
	}
	out.close();
}
void random_numbers_in_file_by_age(void) // создаёт файл input.txt и заполняет его случайными числами по возрастанию
{
	using namespace std;
	setlocale(0, "");
	ofstream out;
	out.open("input.txt");
	srand(time(NULL));
	int a = 1, b = 1;
	for (int i = 0; i < 100; i++)
	{
		a = rand() % ((b += 10) - a) + a; // если а-левая граница, b-правая (+правая граница на каждом шагу увеличивается на 10)
										  //out << "Правая граница " << b << endl;
										  //out << "Левая граница " << a << endl;
		out << setw(5) << a;
		if (i % 6 == 5) out << endl;
	}
	out.close();
}
int sover(int a)//совершенное число
{
	int s = 1, i;
	for (i = 2; i <= a / 2; i++)
		if (a%i == 0)
			s += i;
	if (a == s && a != 1)
		return 1;
	else
		return 0;
}
bool is_perfect(int num) // совершенное число
{
	int sum = 0;

	for (int d = num / 2; d >= 1; d--)
		if (num % d == 0)
			sum += d;

	return sum == num && sum != 0;
}

double cosx(double x, double eps)
{
	int n = 1;
	double c, t, i = 1;
	while (x>2 * pi)
		x -= 2 * pi;
	while (x<0)
		x += 2 * pi;
	t = 1; c = t;
	while (fabs(t) >= eps)
	{
		t = (-1 * t*x*x) / (2 * n*(2 * n - 1));
		c += t;
		n++;
	}
	return c;
}

double sinx(double x, double eps)
{
	int n = 1;
	double c, t, i = 1;
	while (x>2 * pi)
		x -= 2 * pi;
	while (x<0)
		x += 2 * pi;
	t = x; c = t;
	while (fabs(t) >= eps)
	{
		t = (-1 * t*x*x) / (2 * n*(2 * n + 1));
		c += t;
		n++;
	}
	return c;
}

double ex(double x, double n)
{
	double c, t, i = 1;
	t = 1; c = t;
	while (i <= n)
	{
		t = t*x / i;
		c += t;
		i++;
	}
	return c;
}

double step(double x, unsigned n)
{
	double r = 1;
	while (n != 0)
	{
		if (n % 2 == 1)
			r = r*x;
		x = x*x;
		n = n / 2;
	}
	return r;
}

int prost(int x)
{
	int flag, d;
	if (x == 2 || x == 3)
		flag = 1;
	else
	{
		d = 2; flag = 1;
		while ((d <= x / 2) && (flag))
			if (!(x%d))
				flag = 0;
			else
				d++;
	}
	return flag;
}

int nod(int x, int y)
{
	int r;
	while (y != 0)
	{
		r = x%y;
		x = y;
		y = r;
	}
	return x;
}

int cnm(int n, int m) // число комбинаций из n по m
{
	int s = 1;
	for (int i = 1; i <= m; i++)
		s = s*(n - i + 1) / i;
	return s;
}

int sum_c(int x)
{
	int s = 0;
	while (x>0)
	{
		s += x % 10;
		x = x / 10;
	}
	return s;
}