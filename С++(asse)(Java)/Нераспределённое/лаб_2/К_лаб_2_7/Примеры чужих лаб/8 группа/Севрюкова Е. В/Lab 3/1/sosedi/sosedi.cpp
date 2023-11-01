//	Описать процедуру, которая подсчитывает количество элементов стека, у которых равные "соседи".
#include <iostream>
#include <fstream>
#include "stack.h"
#include <string.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	ifstream in;		in.open("input.txt");
	if (!in.is_open())	{ cout << "File is not found"; return 0; }
	ofstream out;		out.open("Output.txt");
	
	ArrayStack a(100);
	int l, g, x1, x2, x3, n;
	char tmp[100];
	char* c = new char[100];

	n = 0;
	while (!in.eof())
	{
		in.getline(tmp, 100);
		c = strtok(tmp, " ");

		while (c)
		{
			n++;
			g = atoi(c);
			a.push(g);
			c = strtok(NULL, " ");
		}
	}
	in.close();

	l = 0;
	if (n <= 2) return 0;

	x1 = a.pop();
	x2 = a.pop();
	while ( !a.isEmpty() )
	{
		x3 = a.pop();
		if (x1 == x3) l++;
		x1 = x2;
		x2 = x3;
	}
	cout << "Количество элементов стека, у которых равные \"соседи\" = " << l <<"\n";
	out<<"Количество элементов стека, у которых равные \"соседи\" = "<<l;
	out.close();
	system("pause");
	return 0;
}
