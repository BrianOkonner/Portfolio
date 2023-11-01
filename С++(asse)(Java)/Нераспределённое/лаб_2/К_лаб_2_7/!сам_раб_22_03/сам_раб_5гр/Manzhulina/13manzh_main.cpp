#include<iostream>
#include<fstream>
#include<stack>
#include"13manzhf.h"
using namespace std;
//Manzhulina
//13 variant
int main()
{
	stack<int> my;
	ifstream in("input.txt");
	ofstream out("output.txt");
	List a;
	char*s=new char[80];
char*str=new char[80];
	while(!in.eof())
	{in.getline(s,80);
	str=strtok(s," ");
	a.ins(atoi(str));
	char*p=(strtok(NULL," "));
	while(p)
	{a.ins(atoi(p));
	p=(strtok(NULL," "));}
	}
	a.change();
	while(!a.isEmpty())
		my.push(a.del());
	
	while(!my.empty())
	{out<<my.top()<<endl;
	my.pop();}
system("pause");
return 0;
}