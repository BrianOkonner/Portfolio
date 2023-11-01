#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Windows.h"
#include <stdio.h>
#include <time.h> 
#include <string>
#include <conio.h>
#include <vector>
using namespace std;
int main()
{
	setlocale(LC_ALL,"rus");
	ifstream in("Input.txt");
	ofstream out("Output.txt");
	int k;
	cout<<"¬ведите k:";
	cin>>k;
	string *l;
	l=new string [k];
	int s=0;
	while(!in.eof())
	{
		getline(in,l[s%k]);
		s++;
	}
	/* выводим элементы в пор€дке чтени€ */
	for (int i = 0; i < k; i++)
	{
		out << l[(s + i) % k] << endl;
	}
}