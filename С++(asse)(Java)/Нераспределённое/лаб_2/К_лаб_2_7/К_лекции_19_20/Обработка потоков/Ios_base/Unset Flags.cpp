// unset flags

#include <iostream>
using namespace std;

int main ()
{
		// set hex as the basefield
	cout.setf ( ios_base::hex, ios_base::basefield );
		// activate showbase
	cout.setf ( ios_base::showbase );
	cout << 100 << endl;

		// deactivate showbase
	cout.unsetf ( ios_base::showbase );
	cout << 100 << endl;

	return 1;
}
