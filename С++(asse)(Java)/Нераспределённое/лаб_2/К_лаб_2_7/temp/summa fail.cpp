#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int a,s;
	ofstream out;
	ifstream in;
	in.open("1.txt");
	out.open("2.txt");
	while(!in.eof());
	{
		in>>a;
		s=s+a;
	}
	out<<s;
	out.close();
}