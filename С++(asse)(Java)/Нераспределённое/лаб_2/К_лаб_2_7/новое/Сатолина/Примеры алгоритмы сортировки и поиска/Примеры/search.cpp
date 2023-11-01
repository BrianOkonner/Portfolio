#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <time.h>
using namespace std;
//Алгоритм проверяет, входит ли второй интервал в первый интервал 
//(при том же порядке следования элементов), и если входит — возвращает 
//итератор для начальной позиции первого вхождения второго интервала.

int main ()
{
	vector <int> v1 (10);
	for (int i = 0; i < v1.size (); i++)
		v1[i] = rand () % 20;
	vector <int> v2 (3);
	for (int i = 0; i < v2.size (); i++)
		v2[i] = rand () % 20;
	ostream_iterator <int> iter (cout, " ");

	cout << "v1: ";
	copy (v1.begin (), v1.end (), iter);
	cout << endl;
	cout << "v2: ";
	copy (v2.begin (), v2.end (), iter);
	cout << endl;

	vector <int>::iterator location;
	location = search (v1.begin (), v1.end (), v2.begin (), v2.end ());

	if (location == v1.end ())
		cout << "v2 not contained in v1" << endl;
	else
		cout << "Found v2 in v1 at offset: " << location - v1.begin () << endl;

	copy(v1.begin()+1,v1.begin()+4,v2.begin());
	cout << "v1: ";
	copy (v1.begin (), v1.end (), iter);
	cout << endl;
	cout << "v2: ";
	copy (v2.begin (), v2.end (), iter);
	cout << endl;

	location = search (v1.begin (), v1.end (), v2.begin (), v2.end ());

	if (location == v1.end ())
		cout << "v2 not contained in v1" << endl;
	else
		cout << "Found v2 in v1 at offset: " << location - v1.begin () << endl;

  return 0;
}
