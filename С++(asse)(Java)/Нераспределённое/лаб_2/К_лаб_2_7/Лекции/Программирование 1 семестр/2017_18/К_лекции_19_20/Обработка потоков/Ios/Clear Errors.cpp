// clearing errors

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	char buffer [80];
	fstream myfile;

	myfile.open ("test.txt", fstream::in);

	myfile << "test";
	if (myfile.fail())
	{
		cout << "Error writing to test.txt\n";
		myfile.clear();
	}

	myfile.getline (buffer,80);
	cout << buffer << endl 
		<<" Successfully read from file.\n";

	return 1;
}
