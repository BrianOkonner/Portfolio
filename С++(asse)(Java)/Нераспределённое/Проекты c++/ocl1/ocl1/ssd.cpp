#include <windows.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h> 
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "fun_h.h"
using namespace std;
struct employee 
{
	int    num; // идентификационный номер сотрудника
	char   name[10]; // имя сотрудника    
	double hours; // количество отработанных часов  
};
int main() 
{
	setlocale(LC_ALL,"1251");
	int	inc = 10;
	char g[33];
	char namef[1024]="",l[1024];
	strcat_s(namef,"ifa.bin");
	const int h=atoi("1");
	employee* empl=new employee[h];
	setlocale(LC_ALL,"1251");
	ofstream out(namef,ios::binary);
//	out<<" "<< empl[i].num<<" "<< empl[i].hours<<" "<< empl[i].hours<<endl;
	for (int i = 0; i < h; i++)
	{
		_cputs("Enter data of the worker N");
		_cputs(itoa(i+1,l,1000));
		_cputs(" threw \"Enter\":\n");
		cin>> empl[i].num>> empl[i].name>> empl[i].hours;
		_itoa(empl[i].num,g,10);
		out.write(itoa(strLength(g),g,10),sizeof itoa(strLength(g),g,10));
		out.write(" ", 1); 
		out.write(itoa(strLength(empl[i].name),g,10), strLength(itoa(strLength(empl[i].name),g,10))); 
		out.write(" ",1); 
		_ltoa(empl[i].hours,g,10);
		out.write(itoa(strLength(g),g,10), strLength(itoa(strLength(g),g,10))); 
		out.write(" ",1); 
		_itoa(empl[i].num,g,10);
		out.write(g,strLength(g)); 
		out.write(empl[i].name, strLength(empl[i].name)); 
		_ltoa(empl[i].hours,g,10);
		out.write(g,strLength(g)); 
	}
	out.close();
	system("pause");
	return 0;
}
	