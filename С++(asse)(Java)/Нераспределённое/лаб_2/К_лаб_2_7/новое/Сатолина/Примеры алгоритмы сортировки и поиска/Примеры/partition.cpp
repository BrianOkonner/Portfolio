#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <time.h>
using namespace std;
//Все элементы, для которых предикат равен true,
//помещаются перед элементами, для которых он равен false. 
//Сохранение относительного порядка обеспечивает алгоритм stable_partition.
int main ()
{
	srand(time(0));
	vector <int> v1 (10);
	for (int i = 0; i < v1.size (); i++)
	v1[i] = rand () % 20;
	ostream_iterator <int> iter (cout, " ");
	copy (v1.begin (), v1.end (), iter);
	cout << endl;
	partition (v1.begin (), v1.end (), bind2nd(less<int>(), 11));
	copy (v1.begin (), v1.end (), iter);
	cout << endl;
	return 0;
}