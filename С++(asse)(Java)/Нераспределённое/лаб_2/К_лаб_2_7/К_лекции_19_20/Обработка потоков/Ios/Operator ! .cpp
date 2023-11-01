// evaluating ios object

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	ifstream is;
	
	is.open ("test.txt");
	if (!is)
		cerr << "Error opening 'test.txt'\n";

	return 1;
}
