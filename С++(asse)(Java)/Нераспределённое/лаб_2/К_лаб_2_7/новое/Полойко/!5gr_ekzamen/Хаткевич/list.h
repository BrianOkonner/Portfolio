#include <iostream>
using namespace std;
struct words
{
	char word[80];
	char ch;
	int len;
	int number;
	words* next;
};
void cut ( char* s, words* &marker );