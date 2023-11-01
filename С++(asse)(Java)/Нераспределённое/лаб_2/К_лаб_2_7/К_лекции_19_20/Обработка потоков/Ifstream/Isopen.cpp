// ifstream::is_open

#include <iostream>
#include <fstream>
using namespace std;

int main () 
{
	ifstream infile;

	infile.open ("test.txt");
	if (infile.is_open())
	{
		while (infile.good())
			cout << (char) infile.get();
		infile.close();
	}
	else
	{
		cout << "Error opening file";
	}
	cout << endl;
	
	return 1;
}
