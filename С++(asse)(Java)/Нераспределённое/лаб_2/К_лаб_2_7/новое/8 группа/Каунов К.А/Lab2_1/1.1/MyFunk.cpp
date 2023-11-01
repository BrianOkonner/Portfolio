#include"MyFunc.h"
bool IfCif(char sc)
{
	if (sc >= '0'&&sc <= '9')
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
int oper(int tmp1,int tmp2,char o)
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
int toi(char c)
{
	switch(c)
	{
	    case '0': return 0;
	    case '1': return 1;
	    case '2': return 2;
	    case '3': return 3;
	    case '4': return 4;
	    case '5': return 5;
	    case '6': return 6;
	    case '7': return 7;
	    case '8': return 8;
	    case '9': return 9;
	}
}
