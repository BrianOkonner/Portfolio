// using fill character

#include <iostream>
using namespace std;

int main ()
{
	char prev;

	cout.width (10);
	cout << 40 << endl;

	prev = cout.fill ('x');
	cout.width (10);
	cout << 40 << endl;

	cout.fill(prev);

	return 1;
}
