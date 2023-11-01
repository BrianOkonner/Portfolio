#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <search.h>
#include <string>
using namespace std;

struct tSpisok
{
	char surname[20];
	int group;
	int record_book_number;
	int mark_man;
	int mark_geo;
	int mark_prog;
};

double average_mark(int a, int b, int c)
{
	return (a + b + c) / 3.;
}

double average_mark_all(tSpisok *spis, int k)
{
	int s = 0;
	for (int i = 0; i < k; i++)
	{
		s += spis[i].mark_geo + spis[i].mark_prog + spis[i].mark_man;
	}
	return s / (3. * k);
}

bool isHighAchiever(tSpisok *spis, int k)
{
	if (spis[k].mark_geo >= 4 && spis[k].mark_man >= 4 && spis[k].mark_prog >= 4)
		return true;
	else
		return false;
}

bool isNegative(tSpisok *spis, int k)
{
	if (spis[k].mark_geo <= 2 || spis[k].mark_man <= 2 || spis[k].mark_prog <= 2)
		return true;
	else
		return false;
}

int tSpisok_compare(const void *student_1, const void *student_2)
{
	tSpisok *std1, *std2;
	std1 = (tSpisok *)student_1;
	std2 = (tSpisok *)student_2;
	if (std1->group > std2->group)
		return 1;
	else
		if (std1->group < std2->group)
			return -1;
		else
			return strcmp(std1->surname, std2->surname);
}