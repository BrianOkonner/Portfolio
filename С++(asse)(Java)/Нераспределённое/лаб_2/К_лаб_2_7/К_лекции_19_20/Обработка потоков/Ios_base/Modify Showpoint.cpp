// modify showpoint flag

#include <iostream>
using namespace std;

int main ()
{
	double d, pi;
	d=10.0;
	pi=3.1416;

	cout.precision (5);
	cout << hex << showpoint << d << '\t' << pi << endl;
	cout << hex << noshowpoint << d << '\t' << pi << endl;

	return 1;
}
