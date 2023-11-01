#include <iostream>
#include "Stack.h"
#include <string>
#include <fstream>
using namespace std;



int main()
{
	Stack text;
	ifstream in("input.txt");
	string line;
	while (getline(in,line))       //пока есть строка ложим в стек
    text.Push(new string(line));

	string *s;
/*	while (s = (string*)text.Pop())
	{
		cout << s << endl;
		delete s;
	}

*/
	system("pause");
	return 0;
}