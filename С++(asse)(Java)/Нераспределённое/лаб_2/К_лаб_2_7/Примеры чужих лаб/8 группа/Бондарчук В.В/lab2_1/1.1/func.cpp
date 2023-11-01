#include"Header.h"
bool cifra(char s)
{
	if (s >= '0'&&s <= '9')
		return true;
	return false;
}
int prior(char c) 
{
	switch (c) 
	{
	case '(': return 1;
	case '+': case '-': return 2;
	case '*': case '/': return 3;
	default: return 0;
	}
}
int operation(int tmp1,int tmp2,char o)
{
	switch (o)
	{
	case '-': return tmp2-tmp1;
	case '+':  return tmp2 + tmp1;
	case '*': return tmp2 * tmp1;
	case '/':return tmp2 / tmp1;
	default: return 0;
	}
}
int Matoi(char c)
{
	if (c == '0') return 0;
	if (c == '1') return 1;
	if (c == '2') return 2;
	if (c == '3') return 3;
	if (c == '4') return 4;
	if (c == '5') return 5;
	if (c == '6') return 6;
	if (c == '7') return 7;
	if (c == '8') return 8;
	if (c == '9') return 9;
}
