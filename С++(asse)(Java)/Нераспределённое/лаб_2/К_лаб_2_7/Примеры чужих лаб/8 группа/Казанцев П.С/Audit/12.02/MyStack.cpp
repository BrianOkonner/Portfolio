#include <iostream>
#include "stack.h"
#include <ctime>
using namespace std;

int main(void)
{
	MyStack st;
	srand(time(NULL));
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
	return 0;
}
