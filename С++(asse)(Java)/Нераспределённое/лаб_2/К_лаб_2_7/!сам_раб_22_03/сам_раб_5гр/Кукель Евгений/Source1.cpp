//5 Кукель Евгений
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "List.h"
using namespace std;


void main()
{
	ifstream InPut("InPut.txt");
	ofstream OutPut("Output.txt");
	List *list = new List();
	List *list1 = new List();
	int a = 0, count = 0;
	int one, two;

	while (!InPut.eof())
	{		
		InPut >> a;
		list1->ins(a);
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		list->ins(list1->del());
	}
	for (int i = 0; i < count/2; i++)
	{
		one = list->del();
		two = list->del();
		if (one % 2==1 && two % 2 == 1)
		{
			OutPut << two << " ";
			OutPut << one << " ";
		}
		else
		{
			OutPut << one << " ";
			OutPut << two << " ";
		}
	}
	if (count%2==1)
	{
		one = list->del();
		OutPut << one << " ";
	}
	OutPut.close();
	system("pause");
}