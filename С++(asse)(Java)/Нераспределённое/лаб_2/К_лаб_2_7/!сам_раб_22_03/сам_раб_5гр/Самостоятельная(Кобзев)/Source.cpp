//��������: ������ �������,5 ������ ,2 �������
#include <iostream>
#include <fstream>
#include<time.h>
#include<queue>
#include "Header.h"
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	List  b;
	queue <int> a;
	int tmp,c;
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("Output.txt");
	while (!fin.eof())
	{
		fin >> tmp;
		b.ins�ead(tmp);
	}
	b.del_nech();
	while (!b.isEmpty()) 
	{
		 c=b.delTail();
		a.push(c);
	}
	while (a.size())
	{
		fout << a.front() << " ";
		a.pop();
	}
	system("pause");
}