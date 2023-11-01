#include <fstream>
#include <iostream>
#include <stack>
#include "List.h"

using namespace std;



void main()
{
	List l;
	ifstream is("input.txt");

	while (!is.eof())
	{
		int n;
		is >> n;
		l.Add(n);
	}
	is.close();
	for (int i = 0; i < l.Count(); i++)
		if ( i% 3 == 1)
			l.GetNode(i)->n++;
	
	stack<int> s;
	for (int i = 0; i< l.Count(); i++)
		s.push(l.GetNode(i)->n);

	ofstream os ("output.txt");
	while (!s.empty())
	{
		os << s.top() << endl;
		s.pop();
	}
	os.close();
}