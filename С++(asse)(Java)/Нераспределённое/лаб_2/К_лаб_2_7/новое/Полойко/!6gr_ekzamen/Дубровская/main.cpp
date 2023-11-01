// main.cpp : Defines the entry point for the console application.
// Дубровская

#include "stdafx.h"
#include "stdio.h"
#include "fun.h"
#include "iostream"
using namespace std;



int main()
{
	int i, g, vr,j, n,k,l, stroka = 3, stolb1 = 0, stolb2 = 0;
	FILE *f;
	f = fopen ("input.txt", "r");
	FILE *out;
	out = fopen ("out.txt", "w");
	int *kol = (int*)malloc(100*sizeof(int));
	for ( i =0;  i<100; i++)
		kol[i] = 0;
	int **Matr;
		Matr = (int**)malloc(100*sizeof(int*));
		for ( i = 0; i<100; i++)
			Matr[i] = (int*)malloc(100*sizeof(int));
	int *buf = (int*)malloc(100*sizeof(int));
	/*
	int *arr = (int*)maloc(100*sizeof(int));
	int j =0;*/
	while(!feof(f))
	{
		spisok *my = new spisok;
		my->init();
		char *s = (char*)malloc(100*sizeof(char));
		fgets(s,100,f);
		
		i = 0;
		while (s[i]!='\0')
		{
			char *str;
			int tmp =0;
			str = (char*)malloc(100*sizeof(char));
			if (s[i]!=',' && s[i] !='.' && s[i]!=';' && s[i]!=':')
			{
				for (g=0; s[i] != ' ' && s[i] != '\0' && s[i]!=',' && s[i] !='.' && s[i]!=';' && s[i]!=':'; g++, i++)
				str[g] = s[i];
				str[g] = '\0';
			}
			if (poisk_ch(str))
			{	
						
				int *arr = (int*)malloc(100*sizeof(int));
				int j =0;
				vr = atoi(str);
				Matr [0][stolb1] = vr;
				stolb1++;
				if (vr%3 == 0)
				{
					Matr[1][stolb2] = vr;
					stolb2++;
					my->push_b(vr);
					tmp = vr;
					n = 0;
					k =2;
					Matr[stroka][1] = tmp;
					while (tmp != 153)
					{
						kol[stroka]++;
						n++;
						arr[j] = kuby(tmp);
						tmp = arr[j];
						Matr[stroka][k] = tmp;
						k++;
						j++;
						cout << tmp << ' ';
					}
					Matr[stroka][0] = n;
					stroka++;
					cout << n << endl;

				}


			}
			if (s[i] != '\0')
			{
	
				i++;
			}
			
		}
		
		/*
		while (my->head!= NULL)
			cout << my->pop_b()<< endl;*/

		/*cin >> j;
		cout << kuby(j);*/

	}
	
		//char *str = (char*)malloc

		/*cout << endl;
		for (i = 0; i<stolb1; i++)
			printf("%d ", Matr[0][i]);
		cout << endl;
		for (i = 0; i<stolb2; i++)
			printf("%d ", Matr[1][i]);
		for (i = 0; i<stolb2; i++)
			buf[i] = Matr[1][i];
		buf = sort_m(buf,stolb2);
		for (i = 0; i<stolb2; i++)
			Matr[2][i] = buf[i];
		cout << endl;
		for (i = 0; i<stolb2; i++)
			printf("%d ", Matr[2][i]);*/
		
		for (i = 0; i<stolb2; i++)
			buf[i] = Matr[1][i];
		buf = sort_m(buf,stolb2);
		for (i = 0; i<stolb2; i++)
			Matr[2][i] = buf[i];
		cout << endl;
		for (i = 3; i<stroka; i++)
		{
			for(j = 0; j < kol[i]+1;j++)
				printf("%d ", Matr[i][j]);
			cout << endl;
		}

		printf ("Matrica Matr sostoit iz %d strok", stroka);
		char sc[2] = " ";
		char nov[2] = "\n";
		for (i = 0; i<stolb1; i++)
		{
			char *d = (char*)malloc(10*sizeof(char));
			itoa(Matr[0][i],d,10);
			fprintf(out,d);
			fputs(sc,out);
		}
		fputs(nov, out);
		for (i = 0; i<stolb2; i++)
		{
			char *d = (char*)malloc(10*sizeof(char));
			itoa(Matr[1][i],d,10);
			fprintf(out,d);
			fputs(sc,out);
		}
		fputs(nov, out);
		for (i = 0; i<stolb2; i++)
		{
			char *d = (char*)malloc(10*sizeof(char));
			itoa(Matr[2][i],d,10);
			fprintf(out,d);
			fputs(sc,out);
		}
		fputs(nov, out);

		for (int y = 3; y<stroka; y++)
		{
			for(j = 0; j < kol[y];j++)
			{
				char *d = (char*)malloc(10*sizeof(char));
				itoa(Matr[y][j],d,10);
				fprintf(out,d);
				fputs(sc,out);
			}
			fputs(nov, out);

		}
			//printf("%d ", Matr[0][i]);

		/*for (i = 0; i<stolb2; i++)
			printf ("%d ", buf[i]);*/

		fclose (f);
		fclose(out);
	return 0;
}

