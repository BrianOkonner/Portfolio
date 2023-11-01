//Шибеко, 5 группа
#include <fstream>
#include <iostream>
#include "list.h"
#include "MaxString.h"
#include <stdlib.h>
#include <search.h>

using namespace std;

char sep[] = "!.- ;:,";

list *root = new list;

extern "C" int _cdecl count_ones_asm(int);

bool is_sep(char c, char *sep)
{
	unsigned int l = strlen(sep);
	for (unsigned int i = 0; i < l; ++i)
		if (sep[i] == c) return true;
	return false;
}

void sep_to_words(char *s, char *sep)
{
	unsigned int i = 0;
	char *ns = new char[MAX];

	unsigned int l = strlen(s);
	unsigned int ls = strlen(sep);
	unsigned int tl = 0;

	while (i < l)
	{
		while (is_sep(s[i], sep) && i < l) ++i;
		if (i == l) break;

		list *nver = new list;
		while (!is_sep(s[i], sep) && i < l)
			nver->s[tl++] = s[i++];
		nver->s[tl] = '\0';

		push(root, nver);
		tl = 0;
	}

	delete [] ns;
}

int count_ones(int l)
{
	int ct = 0;
	while (l != 0)
	{
		if (l%2) ++ ct;
		l /= 2;
	}
	return ct;
}

int count_ones_rec(int l)
{
	if (l == 0) return 0;
	int ans = 0;
	if (l%2) ++ans;
	ans += count_ones_rec(l/2);
	return ans;
}

void my_sort(int *matr[3], int t)
{
	for (int i = 0; i < t; ++i)
		for (int j = i+1; j < t; ++j)
		{
			//int c1 = count_ones_asm(matr[i][2]);
			//int c2 = count_ones_asm(matr[j][2]);
			int c1 = count_ones_rec(matr[i][2]);
			int c2 = count_ones_rec(matr[j][2]);
			if (c1 > c2)
			{
				int t = matr[i][2];
				matr[i][2] = matr[j][2];
				matr[j][2] = t;
			}
		}
}

int my_comp(const void *a, const void *b)
{
	int *aa = (int*)a;
	int *bb = (int*)b;
	int c1 = count_ones_asm(*aa);
	int c2 = count_ones_asm(*bb);
	if (c1 < c2) return -1;
	if (c1 > c2) return 1;
	return 0;
}

int main()
{
	ifstream fin ("input.txt");
		char *s = new char[MAX];
		char *ccc = new char[10000];
		int **matr = new int *[10000];
		for (int i = 0; i < 10000; ++i)
			matr[i] = new int[3];
		int t = 0;

		root->next = NULL;
		while (fin.getline(s, MAX))
			sep_to_words(s, sep);
	ofstream fout1("Result1.txt");

	fout1 << "Номер слова	Слово	Символ		Длина последовательности	Номер символа" << endl;
		list *tmp = root;
		while (true)
		{
			if (tmp->next == NULL) break;
			int pos = 0; int maxl = 1;
			MaxString(tmp->s, pos, maxl);
			fout1 << t+1 << ' ' << tmp->s << ' ' << tmp->s[pos] << ' ' << maxl << ' ' << pos+1 << endl;
			matr[t][0] = t+1;
			matr[t][1] = pos+1;
			matr[t][2] = maxl;
			ccc[t] = tmp->s[pos];
			++t;
			tmp = tmp->next;
		}
	fout1.close();


	ofstream fout2("Result2.txt");

/*		int *tmatr = new int [10000];
		for (int i = 0; i < t; ++i)
			tmatr[i] = matr[i][2];

		qsort(tmatr, t, sizeof(int), my_comp);

		for (int i = 0; i < t; ++i)
			matr[i][2] = tmatr[i];
		delete [] tmatr;*/

		my_sort(matr, t);
		fout2 << "Номер слова	Символ		Длина последовательности	Номер символа" << endl;
		for (int i = 0; i < t; ++i)
			fout2 << matr[i][0] << '\t' << ccc[i] << '\t' << matr[i][2] << '\t' << matr[i][1] << endl;
	fout2.close();

	for (int i = 0; i < 3; ++i)
		delete [] matr[i];
	delete [] matr;
	delete [] s;
	delete [] ccc;

	fin.close();

	return 0;
}