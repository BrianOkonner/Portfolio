//Осовицкий Олег, Группа №5
//get_number_of_digits - рекурсивная
//get_number_of_digits_asm - внешняя на ассемблере
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "List.h"
#include "MaxString.h"

extern "C" int __cdecl get_number_of_digits_asm(int);

struct num
{
	int value;
	int number;
};

int compare(const void* lhs, const void* rhs)
{
	num *l = (num*)lhs, *r = (num*)rhs;
	return (l->value == r->value) ? ((l->number == r->number) ? 0 : ((l->number > r->number) ? 1 : -1)) : ((l->value > r->value) ? 1 : -1);
}

int get_number_of_digits(int a)
{
	if (a == 1)
		return 1;
	return get_number_of_digits(a / 2) + ((a % 2 == 1) ? 1 : 0);
}

int main()
{
	list_item* pHead = get_input();
	char* tmp = new char[128];
	int i = 0;
	char c;
	int l, k;
	int** matr = new int*[1024];
	for (int i = 0; i < 1024; i++)
		matr[i] = new int[3];
	FILE* f1 = fopen("Result1.txt", "w");
	FILE* f2 = fopen("Result2.txt", "w");
	fprintf(f1, "Номер слова   Слово                   Символ  Длина   Номер символа\n");
	fprintf(f2, "Номер слова   Символ  Длина   Номер символа\n");
	while (pHead)
	{
		pHead = remove(pHead, tmp);
		parse_word(tmp, ((char*)matr[i])[0], matr[i][1], matr[i][2]);
		fprintf(f1, "%-14d%-24s%-8c%-8d%-d\n", i + 1, tmp, matr[i][0], matr[i][1], matr[i][2]);
		i++;
	}
	num* arrl = new num[i];
	for (int j = 0; j < i; j++)
	{
		//arrl[j].value = get_number_of_digits(matr[j][1]);
		arrl[j].value = get_number_of_digits_asm(matr[j][1]);
		arrl[j].number = matr[j][1];
	}
	qsort(arrl, i, sizeof(num), compare);
	for (int j = 0; j < i; j++)
		matr[j][1] = arrl[j].number;
	for (int j = 0; j < i; j++)
	{
		fprintf(f2, "%-14d%-8c%-8d%d\n", j + 1, matr[j][0], matr[j][1], matr[j][2]);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
