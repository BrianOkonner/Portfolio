// ostringstream::str

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main () 
{
	ostringstream oss;
	string mystr;
	
	oss << "Sample string";
	mystr = oss.str();
	
	cout << mystr << endl;
	
	return 1;
}
