#include "Header.h"
#include <fstream>
#include <queue>

using namespace std;

void main()
{
	queue <int> B;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	List A(100);
	int buff;
	while (!fin.eof())
	{
		fin >> buff;
		A.Push_Front(buff);
	}
	A.Print();
	A.Insert();
	while (A.Size())
	{
		B.push(A.Top());
		A.Pop_Front();
	}
	while (!B.empty())
	{
		fout << B.front() << endl;
		B.pop();
	}
	system("pause");
}