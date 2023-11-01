// modify showbase flag

#include <iostream>
using namespace std;

int main ()
{
	int n = 100;

	cout << hex << showbase << n << endl;
	cout << hex << noshowbase << n << endl;

	return 1;
}
