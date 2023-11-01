#include "stdafx.h"
#include "iostream"

bool poisk_ch (char *s)
{
	int i, j, k;
	i = 0;
	while (s[i]!='\0')
	{
		if (s[i]>='0'&&s[i]<='9')
		i++;
		else 
			return false;
		if (s[i] == '\0') return true;
	}
	return true;
}
int kuby (int a)
{
	if (a>9)
	{
		int k = a%10;
		int kv = k*k;
		return (kv*k + kuby(a/10));
	}
	else 
	{
		int b = a*a;
		return a*b;
	}
}

int *sort_m(int *a, int n)
{
	int i, j, m1,  m2, buf;
	
	for(i=0;i<n;i++)
			for (j=i+1;j<n;j++)
			{
				m1 = a[i]%10;
				m2 = a[j]%10;
					
				if(m1>m2)
				{
					buf=a[i];
					a[i]=a[j];
					a[j]=buf;
				}

			}

	return a;
}