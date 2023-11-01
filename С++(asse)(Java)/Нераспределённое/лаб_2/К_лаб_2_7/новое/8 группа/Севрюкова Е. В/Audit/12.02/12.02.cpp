#include <iostream>
#include "Stack.h"
using namespace std;

int main(void)
{
	Stack A;
	for (int i = 0; i < 10; i++)
	{
		A.Push(new int(rand() % 10));
	}
	while (!A.isEmpty())
	{
		int g = *(int*)A.Peek();
		A.Pop();
		cout << g << endl;
	}
	
	system("pause");
	return 0;
}
