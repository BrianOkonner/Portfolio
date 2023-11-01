#include <iostream.h>

int  main( )
{
	int  n, m;
	try
	{
		cout << "Input two integers: ";
		cin >> n >> m;
		if (!m)
			throw "Zero divide";
		cout << "n/m = " << (n/m) << endl;
	}
	catch(char*  str)
	{
		cout << str << endl;
	}
		cout << "OK" << endl;
		return 1;
}
