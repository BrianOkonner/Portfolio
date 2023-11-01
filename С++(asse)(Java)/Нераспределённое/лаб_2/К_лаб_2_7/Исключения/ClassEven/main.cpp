#include <iostream>

#include "even.h"
using namespace std;

int  main( )
{
	even a(2), b(0), c(0);

	cout << "a = " << a << endl;

	b = a.next( );		// b = 4
	c = a + b;			// c = 6
	cout << "c = " << c << endl;

	cout << "Input even number: ";
	cin >> b;
	cout << "b = " << b << endl;

	c += b;
	cout << "c = " << c << endl;

	cout << "a > b = " << (a > b) << endl;

	return 1;
}