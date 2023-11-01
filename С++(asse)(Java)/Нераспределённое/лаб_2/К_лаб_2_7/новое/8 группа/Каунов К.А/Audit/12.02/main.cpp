#include <iostream>
#include "Stack.h"
#include <ctime>

using namespace std;

int main()
{
	Stack st;
	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		st.Push(new int(rand() % 10));
	}
	while (!st.isEmpty())
	{
		int g = *(int*)st.Top();
		st.Pop();
		cout << g << endl;
	}
	system("pause");
	return 0;
}
