// istream get

#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
	char c, str[256];
	ifstream is;

	cout << "Enter the name of an existing text file: ";  
	cin.get (str,256);
	is.open (str);		// open file

	while (is.good())	// loop while extraction from file is possible
	{
		c = is.get();	// get character from file
		cout << c;
	}
  
	is.close();			// close file  
	
	return 1;
}