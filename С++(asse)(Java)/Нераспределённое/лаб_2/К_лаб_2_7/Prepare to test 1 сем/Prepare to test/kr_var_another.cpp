struct Employees
{
	char sname[20];
	char fname[3];
	char thname[3];
	int cop;
	char perevoz[20];
};
struct Carrier
{
	char perevoz[20];
	int cen;
};
struct SortEmp
{
	char sname[20];
	char fname[3];
	char thname[3];
	int cop;
	int km;
};
struct CorSort1
{
	char sname[20];
	char fname[3];
	char thname[3];
	int cop;
	int km;
	int newsum;
	int decr;
};
struct CorSort2
{
	char sname[20];
	char fname[3];
	char thname[3];
	int cop;
	int km;
	int newsum;
	int prem;
};
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
using namespace std;
void main()
{
setlocale(LC_ALL,".1251");
ifstream carrier("Carrier.txt"), employees("Employees.txt");
ofstream corsort("CorSort.txt"), sortemp("SortEmp.txt");
Employees tmp1, *empoy;
Carrier tmp2, *carr;
SortEmp *sortE;
CorSort1 *corS1;
CorSort2 *corS2;
int t,j,b;
char a[20],num1[]="234567890";
carrier.seekg(0,carrier.end);
t=carrier.tellg();
carrier.seekg(0,carrier.beg);
b=carrier.tellg();
carrier>>b;
carr=new Carrier[b];
if(t!=0)
{
	for(j=0;j<b;j++)
	{
		carr[j].perevoz[0]='\0';
		carrier>>a;
		strcat(a," ");
		//carrier.getline(tmp2.perevoz,17,'\n');
		for(int i=0;strchr(num1,a[0])==0&&strchr(num1,a[1])==0;i++)
		{
			strcat(carr[j].perevoz,a);
			carrier>>a;
			strcat(a," ");
		}
		carr[j].cen=atoi(a);
		//	carrier>>tmp2.perevoz[i];
	}
}
fcloseall();
}