// typewriter

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	
	char ch;
	ofstream outfile("test.txt");
	cout << "Input any text with a point." << endl;
	
	do
	{
		ch = cin.get();
		outfile.put(ch);
	}
	while (ch != '.');
	
	return 1;
}
