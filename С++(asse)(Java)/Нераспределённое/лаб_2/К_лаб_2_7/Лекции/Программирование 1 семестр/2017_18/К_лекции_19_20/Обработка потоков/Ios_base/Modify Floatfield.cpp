// modify floatfield using manipulators

#include <iostream>
using namespace std;

int main ()
{
	float f = 365.25;
	
	cout << fixed << f << endl;
	cout << scientific << f << endl;

	return 1;
}
