//7. Программа разбора строки на слова с подсчетом количества
// неповторяющихся слов и вывода их на экран.


#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>

const char* sep=" ,./?!;:\}{][()+-=\n\t";
char str1[80];
int comp(void* x,void* y)
{
	return strcmp(*(char **)x,*(char**)y);
}


		int main()
	{
	
	char** slova;
	cout<<"Input string"<<endl;
	gets(str1);

//  Выделеніе и печать лексем из строки str1 с множеством разделителей в sep с
//	помещением их в массив slova
	int N=0;
		slova=(char**)malloc(sizeof(char*));
	slova[0]=(char*)malloc(sizeof(char*));
	slova[0] = strtok ( str1, sep );
			while (slova[N])
		{	slova=(char**)realloc( slova , (++N+1)*sizeof(char*));
		    slova[N] = strtok ( NULL, sep );
			}
	qsort(slova,N,sizeof(char*),(int (*)(const void*, const void*))comp);

		int Count=0;		
	if (strcmp(slova[0],slova[1]))
	{ Count++;
		puts(slova[0]);
	}
		
			for (int i=1;i<N-1;i++)
			if (strcmp(slova[i],slova[i+1])&&strcmp(slova[i],slova[i-1]))
			{
				Count++;
				puts(slova[i]);

			}
				if (strcmp(slova[N-1],slova[N-2]))
	{ Count++;
		puts(slova[N-1]);
	}
		
	cout<<"Count of such words is "<<Count<<endl;

		}