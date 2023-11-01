

#include <iostream>
#include "stack.h"
#include <ctime>
using namespace std;

int main(void)
{
	MyStack Stack1;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Stack1.Push(new int(rand() % 10));
	}

	while (!Stack1.isEmpty())
	{
		int a = *(int*)Stack1.Top();
		Stack1.Pop();
		cout << a << endl;
	}

	system("pause");
	return 0;
}
