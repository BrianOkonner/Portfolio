// position of put pointer

#include <fstream>
using namespace std;

int main ()
{
	long pos;
	
	ofstream outfile;
	outfile.open("test.txt");
	
	outfile.write("This is an apple", 16);
	pos = outfile.tellp();
	outfile.seekp(pos - 7);
	outfile.write(" sam", 4);
	
	outfile.close();
	
	return 1;
}
