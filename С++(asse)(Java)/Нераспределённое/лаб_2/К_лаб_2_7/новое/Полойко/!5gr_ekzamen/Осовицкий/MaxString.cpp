#include <cstring>

int find_max(int* a)
{
	int max = 0;
	for (int i = 0; i < 256; i++)
		if (a[i] > a[max])
			max = i;
	return max;
}

void parse_word(char* str, char &c, int &l, int &k)
{
	c = 0;
	l = 0;
	k = 0;
	int* counts = new int[256];
	for (int i = 0; i < 256; i++)
		counts[i] = 0;
	int strl = strlen(str);
	for (int i = 0; i < strl; i++)
		counts[str[i]]++;
	c = (char)find_max(counts);
	int l_tmp = 0;
	for (int i = 0; i < strl; i++)
		if (str[i] == c)
		{
			l_tmp++;
			if (l_tmp > l)
			{
				l = l_tmp;
				k = i - l_tmp + 2;
			}
		}
		else
		{
			l_tmp = 0;
		}
}

