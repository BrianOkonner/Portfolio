#include "Stack.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	Stack A; // создаётся объект класса Stack
	for (int i = 0; i < 10; i++)
	{
		A.Push((void*)(rand() % 10));
		cout << A.Top() << "\n";
	}
	system("pause");
	return 0;
}