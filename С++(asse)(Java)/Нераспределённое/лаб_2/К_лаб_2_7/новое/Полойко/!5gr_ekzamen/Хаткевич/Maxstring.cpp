#include "maxstring.h"


void find_ch( words* &marker )
{
	int k,num;
	char c;
	while (marker->next)
	{
		marker->len=1;
		marker->number=0;
		marker->ch=marker->word[0];
		k=1;
		c=marker->word[0];
		num=0;
		for ( int i=1; i<=strlen(marker->word); ++i )
		{
			if (marker->word[i]==marker->word[i-1]) ++k;
			else {
				if (k>marker->len) 
				{
					marker->len=k;
					marker->ch=c;
					marker->number=num;
				}
				c=marker->word[i];
				num=i;
				k=1;
			}
		}
		marker=marker->next;
	}
}
