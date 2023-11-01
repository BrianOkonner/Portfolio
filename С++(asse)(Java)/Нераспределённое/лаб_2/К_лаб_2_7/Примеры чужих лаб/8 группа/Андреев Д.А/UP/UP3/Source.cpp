/*
ƒан A=(ai) ,  i=1..n,  (n<=10), массив  и число b. ѕереставить  числа  в массиве 
таким  образом, чтобы сначала шли  элементы,  меньшие или равные b, а лишь затем большие b.
*/

#include <iostream>
using namespace std;
extern "C" int* MAS_FUNC(int *, int *, int, int);

int main()
{
	setlocale(0, "rus");

	int *a, b, i, n, *k;
	cout << "¬ведите размер массива: ";
	cin >> n;
	cout << "Ёлемент b: ";
	cin >> b;
	
	a = new int[n];
	cout << "¬ведите элементы массива: ";

	for (i = 0; i<n; i++) cin >> a[i];
	
	for (i = 0; i<n; i++) cout << a[i];
	k = new int[n];
	//св€зь с ассемблером
	k = MAS_FUNC(a, k, n, b);



	for (i = 0; i<n; i++) cout << *(k + i) << ' ';

	system("pause");
	return 0;
}



