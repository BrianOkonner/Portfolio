#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <clocale>
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	double a;
	int c;
	a=9999999999999999999999999999999999999999999999999999999999999999999999999999999999999997.;
	double y=a/2;
    bool isEven=(fabs(y-round(y)) < EPS);
	system("pause");
	return 0;
}