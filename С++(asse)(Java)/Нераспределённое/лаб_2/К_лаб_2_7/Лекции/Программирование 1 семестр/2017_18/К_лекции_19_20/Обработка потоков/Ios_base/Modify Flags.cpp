// modify flags

#include <iostream>
using namespace std;

int main ()
{
	cout.flags (ios_base::right | ios_base::hex | ios_base::showbase);
	cout.width (10);
	cout << 100 << endl;

	return 1;
}
