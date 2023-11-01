// modify adjustfield using manipulators

#include <iostream>
using namespace std;

int main ()
{
	int n = 70;

	cout.width (10); cout << internal << n << endl;
	cout.width (10); cout << left << n << endl;
	cout.width (10); cout << right << n << endl;

	return 1;
}
