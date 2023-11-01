#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int KUB(int a)
{
		a = KUB(a/10) + (a/10)*(a/10)*(a/10);
	return a;
}
void Sort(int *M, int n)
{
	for(int i =0; i < n; i++)
		for(int j = 0; j < n - 1; j++)
			if ((M[j] % 10) > (M[j + 1] % 10))
			{
				int t = M[j];
				M[j] = M[j + 1];
				M[j + 1] = t;
			}
}
int **Matr;
int main()
{
	FILE *in;
	int n = 0;
	in = fopen("Input.txt", "r+");
	if (in == NULL)
		printf("FILE not opened!");
	else
	{
		int i = 0;
		char str[81], c1[]={' ',';',',','.',':'};
		int M[100];
		char *b;
		while(!feof(in))
		{
			fgets(str, 80, in);
			char *str1 = str;
			char *str2;
			int C = 0;
			char *a = strtok(str1, c1);
			while(a)
			{
				str2 = a - 1;
				str2 = 0;
				if(itoa(C, str1, 10))
					n++;
				str1 = a;
				a = strtok(str1, c1);
			}
			if (itoa(C, str1, 10))
				n++;
			Matr = (int**)malloc(n*sizeof(int));
			while(a)
			{
				str2 = a - 1;
				str2 = 0;
				if(itoa(C, str1, 10))
					n++;
				str1 = a;
				a = strtok(str1, c1);
			}
		}
		for(int i = 0; i < 100; i++)
		{
				if (Matr[0][i] == 153)
				{
					Matr[i + 1][0] = 0;
					Matr[i + 1][1] = 153;
				}
				else
				{
					int j = i;
					int a = 142;
					int m = 0;
					while(a != 153)
					{
						Matr[j + 1][1] = KUB(a);
						a = Matr[j + 1][1];
						j++;
						m++;
					}
					Matr[0][j] = m;
				}
		}
	}
	return 0;
}
//не выделены числа!!!Просто показано как строить матрицу.
//Дорофеев