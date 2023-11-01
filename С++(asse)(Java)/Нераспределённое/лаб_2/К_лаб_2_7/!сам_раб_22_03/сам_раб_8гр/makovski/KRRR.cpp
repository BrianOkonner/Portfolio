// вариант 15 
// Маковский Владислав
#include <iostream>
#include <fstream>
#include "stak.h"
#include <queue>

using namespace std;
void main()
{
	Stack stack;

	ifstream Fin("input.txt");
	ofstream Fout("Output.txt");
	queue <int> Poradok;
	int a,b;
	while (!Fin.eof())
	{
		Fin >> a;
		stack.push(a);
	}
	Fin.close();
	while (!stack.Empty())
	{
		b=stack.Top();
		Poradok.push(b);
		stack.pop();
	}
	
	while (!Poradok.empty())
	{
		Fout << Poradok.front() <<" ";
		Poradok.pop();
	
	}
	Fout.close();
	system("pause");
}
