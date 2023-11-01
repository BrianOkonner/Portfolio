// modify precision

#include <iostream>
using namespace std;

int main ()
{
	double pi = 3.14159;

	cout.precision(5);
	cout << pi << endl;

	cout.precision(10);
	cout << pi << endl;

	return 1;
}
