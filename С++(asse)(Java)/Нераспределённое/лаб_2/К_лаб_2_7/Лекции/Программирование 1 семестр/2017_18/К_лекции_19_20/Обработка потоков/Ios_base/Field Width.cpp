// field width

#include <iostream>
using namespace std;

int main ()
{
	cout << 100 << endl;
	cout.width(10);
	cout << 100 << endl;
	cout.fill('x');
	cout.width(15);
	cout << left << 100 << endl;

	return 1;
}
