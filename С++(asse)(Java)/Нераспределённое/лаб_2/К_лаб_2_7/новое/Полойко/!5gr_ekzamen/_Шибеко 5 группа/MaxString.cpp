#include "MaxString.h"
#include <string>

char MaxString(char *s, int &pos, int &maxl)
{
	int l = strlen(s);
	pos = 0; maxl = 1;
	int j;
	for (int i = 0; i < l-1; ++i)
	{
		j = i+1;
		while (s[i] == s[j] && j < l)
			++j;
		if (j - i > maxl)
		{
			maxl = j - i;
			pos = i;
		}
	}
	return s[pos];
}