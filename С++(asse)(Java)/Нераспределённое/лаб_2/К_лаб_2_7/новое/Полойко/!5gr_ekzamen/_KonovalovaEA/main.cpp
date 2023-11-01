//KonovalovaEA.......6группа
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <List.h>
#define MAXLTH 80

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
	static const char delims[] = " -,.;:!";
	list result;
	in = fopen("Input.txt", "r");
	create_list(&result);
	

void first_row(void)
{
	long cur;
	size_t i = 0;
	start_traverse(&nums);
	Matr[0] = (long *) malloc(allnums * sizeof(long));
	while (go_next(&nums, &cur))
		Matr[0][i++] = cur;
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
	FILE *out = fopen("Result1.txt", "w");
	size_t i, j;
	fprintf(out, "Номер слова Слово Символ Длина Номер символа\n");
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

	while(!feof(IN))
	{
		tmp2[0]='\0';
		fgets(str,99,IN);
		strcpy(tmp,str);
		sl=strtok(str,set);

		while(sl)
		{
			if(chislo(sl))
			{
				len=strlen(sl);
				fprintf(OUT,"%d ",len);
				Mas[n]=len;
//				cout<<Mas[n]<<" ";
				n=n+1;
			}
			sl=strtok(NULL,set);
		}
	}
//	cout<<endl;
void other_rows(void)
{
	size_t i;
	for (i = 0; i < usenums; ++i)
		Matr[i + 3] = seq(Matr[2][i]);
}