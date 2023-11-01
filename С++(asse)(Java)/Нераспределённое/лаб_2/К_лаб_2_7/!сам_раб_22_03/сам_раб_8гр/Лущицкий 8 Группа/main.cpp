//Лущицкий Максим Группа №8
//Вариант 20


#include <fstream>
#include <iostream>
#include <list>
#include "Queue.h"

using namespace std;


void main()
{
	Queue q;
	ifstream is("input.txt");

	while (!is.eof())
	{
		int n;
		is >> n;
		q.Add(n);
	}
	is.close();

	int min = INT_MAX;
	for (int i = 0; i< q.Count(); i++)
		if (q.Get(i)->n < min)
			min = q.Get(i)->n;

	

	list<int> l;
	for (int i = 0; i< q.Count(); i++)
	{
		l.push_back(q.Get(i)->n);
		if (q.Get(i)-> n == min)
			l.push_back(q.Get(i)->n);
	}


	ofstream os ("output.txt");
	while (!l.empty())
	{
		os << l.front() << endl;
		l.pop_front();
	}
	os.close();
}