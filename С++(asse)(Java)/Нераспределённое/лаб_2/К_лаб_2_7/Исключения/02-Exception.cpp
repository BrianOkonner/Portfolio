#include <iostream.h>

struct	Zero_divide {};

int  main( )
{
	int  n, m;
	try
	{
		cout << "Input two integers: ";
		cin >> n >> m;
		if (!m)
			throw Zero_divide();
		cout << "n/m = " << (n/m) << endl;
	}
	catch(Zero_divide)
	{
		cout << "Zero divide" << endl;
	}
	cout << "OK" << endl;
	return 1;
}
