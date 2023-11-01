#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cstdlib>
#include "fun_h.h"
#include <ctime>
#include "Windows.h"
#include <stdio.h>
#include <time.h> 
#include "theater.h"
using namespace std;
int main()
{
	theaters <int> (5);
	char s[80];
	int n;
	ofstream out("Output.txt");
	ifstream in("Input.txt");
	in>>n;
	cout<<"Vvedite spektakl: ";
	gets(s);
}