// Anikovich V_18;
#include <iostream>
#include <list>
#include <fstream>
#include "DeqOnArray.h"

using namespace std;

void main()
{
	ifstream fin("input.txt");
	ofstream fout("Output.txt");
	list<int> lstOut;
	DeqOnArray deq;
	int numeric;
	while (!fin.eof())
	{
		fin >> numeric;
		deq.pushBack(numeric);
	}
	deq.sortAboveCompare();
	while (!deq.isEmpty())
	{
		int num = deq.popFront();
		lstOut.push_back(num);
	}
	while (!lstOut.empty())
	{
		int value = lstOut.front();
		fout << value << ' ';
		lstOut.pop_front();
	}
}