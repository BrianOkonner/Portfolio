#include <fstream>
#include <string>
#include <iostream>
#include <stack>
#include "StackL.h"
using namespace std;
int main()
{
	StackL textline;
	ifstream in("in.txt");
string line;
while(getline(in,line))
{
	textline.push(new string(line));
}
string *S;
while((S=(string *)textline.pop())!=0)
{
	cout<<*S<<endl;
	delete S;
}
system("pause");
}

