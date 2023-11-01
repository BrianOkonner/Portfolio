#include "Array.h"
#include <stdlib.h>
/*
long gen_next(long val)
{
	long last;

	if (val == 0) return 0;

	last = val % 10;
	return last * last * last + gen_next(val / 10);
}	
*/
long *seq(long num)
{
	size_t N = 0, i;
	long cur = (long) num;
	long *row;

	while (cur != MAGIC)
	{
		++N;
		cur = gen_next(cur);
	}
	
	row = (long *) malloc((N + 2) * sizeof(long));
	row[0] = (long) N;
	cur = row[1] = num;

	for (i = 0; i < N; ++i)
	{
		cur = gen_next(cur);
		row[2 + i] = cur;
	}

	return row;
}
