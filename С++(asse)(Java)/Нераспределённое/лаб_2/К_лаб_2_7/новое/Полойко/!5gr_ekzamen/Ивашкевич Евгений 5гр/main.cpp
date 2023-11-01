// Ивашкевич Евгений 5 группа

#include <fstream>
using namespace std;

void main()
{
	ifstream fin("input.txt");
	ofstream fout("result1.txt");
	
	char*b=new char[256];
	while (!fin.eof())

	{
		fin.getline(b,256);
		fout<<b;
		fout<<endl;
	}

	int q;

	
}