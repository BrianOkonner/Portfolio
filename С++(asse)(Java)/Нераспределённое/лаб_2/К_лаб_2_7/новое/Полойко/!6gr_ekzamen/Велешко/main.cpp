/*
   Контрольная работа по программированию

                           Велешко Алексей, 1 курс, 6 группа
						                                       */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Spisok.h"
#include "Array.h"
#define MAXLTH 80
#pragma warning(disable: 4996)

list nums;
long *Matr[500];
size_t allnums = 0, usenums = 0;

list build_list(void);

void first_row(void);
void second_row(void);
void third_row(void);

void other_rows(void);
void destroy_all(void);
void output_answer(void);

int main()
{
	nums = build_list();

	first_row();
	second_row();
	third_row();
	other_rows();

	output_answer();

	destroy_all();
}

list build_list(void)
{
	FILE *in;
	char buf[MAXLTH + 1];
	static const char delims[] = " ,.;:\xA\xD";
	list result;

	in = fopen("Input.txt", "r");
	create_list(&result);
	
	while(fgets(buf, MAXLTH, in))
	{
		char *cur = strtok(buf, delims);

		if (cur)
		{
			do {
				char *endp;
				long n = strtol(cur, &endp, 10);
					
				if (*endp == '\0'){
					++allnums;
					insert(&result, n);
					if (n % 3 == 0) ++usenums;
				}
			} while (cur = strtok(NULL, delims));
		}
	}

	fclose(in);
	return result;
}

void first_row(void)
{
	long cur;
	size_t i = 0;

	start_traverse(&nums);
	Matr[0] = (long *) malloc(allnums * sizeof(long));

	while (go_next(&nums, &cur))
		Matr[0][i++] = cur;
}

void second_row(void)
{
	long cur;
	size_t i = 0;

	start_traverse(&nums);
	Matr[1] = (long *) malloc(usenums * sizeof(long));

	while (go_next(&nums, &cur))
		if (cur % 3 == 0)
			Matr[1][i++] = cur;
}

int compare_digit(const void *a, const void *b)
{
	const long *pa = (const long *) a;
	const long *pb = (const long *) b;

	return (*pa % 10) - (*pb % 10);
}

void third_row(void)
{
	Matr[2] = (long *) malloc(usenums * sizeof(long));
	memcpy(Matr[2], Matr[1], usenums * sizeof(long));
	qsort(Matr[2], usenums, sizeof(long), compare_digit);
}

void output_answer(void)
{
	FILE *out = fopen("Out.txt", "w");
	size_t i, j;

	fprintf(out, "Матрица Matr состоит из %u строк\n", usenums + 3);
	
	for (i = 0; i < allnums; ++i)
		fprintf(out, "%ld ", Matr[0][i]);

	fputs("\n", out);

	for (i = 0; i < usenums; ++i)
		fprintf(out, "%ld ", Matr[1][i]);

	fputs("\n", out);

	for (i = 0; i < usenums; ++i)
		fprintf(out, "%ld ", Matr[2][i]);

	fputs("\n", out);

	for (i = 0; i < usenums; ++i)
	{
		fprintf(out, "%ld %ld ", Matr[i + 3][0], Matr[i + 3][1]);

		for (j = 0; j < (size_t) Matr[i + 3][0]; ++j)
			fprintf(out, "%ld ", Matr[i + 3][2 + j]);

		fputs("\n", out);
	}

	fclose(out);
}

void destroy_all(void)
{
	size_t i;

	destroy_list(&nums);

	for (i = 0; i < usenums + 3; ++i)
		free(Matr[i]);
}

void other_rows(void)
{
	size_t i;

	for (i = 0; i < usenums; ++i)
		Matr[i + 3] = seq(Matr[2][i]);
}

/* Велешко Алексей */