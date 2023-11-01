/*Колчанов Никита Сергеевич
7ая группа
Лаборотораня работа №2
Задание 9
Вывести в таблице результаты уравнения
Алгоритм:создал функцию считающую гип. тангенс через ряд тейлора,
считаем по формуле от n до m, и так для каждого икса с шагом h, от а, до b.*/
#include "stdafx.h"
#include <iostream>
#include <windows.h> 
using namespace std;
int Tanh(float y)
{ 
float a1,b1,c1,d1,sum,z1,z2, sum1;
c1=1;
a1=0;
sum=0;
d1=1;
for(b1=1;b1<=10;b1++)
{
c1=y*c1;
d1=b1*d1;
a1=c1/d1;
sum=sum+a1;
}
z1=sum-1/sum;
z2=sum+1/sum;
sum1=z1/z2;
return sum1;
}
int main()
{ 
double a,b,h,m,s,S,x,c,d,e,n,z=0;
HANDLE consoleOutput;
consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(consoleOutput,FOREGROUND_INTENSITY); 
cout<<"Vesti shag:";
cin>>h;
SetConsoleTextAttribute(consoleOutput,FOREGROUND_GREEN); 
cout<<"VVesti m:";
cin>>m;
SetConsoleTextAttribute(consoleOutput,FOREGROUND_INTENSITY); 
cout<<"Ot:";
cin>>a;
SetConsoleTextAttribute(consoleOutput,FOREGROUND_GREEN); 
cout<<"do:";
cin>>b;
 
SetConsoleTextAttribute(consoleOutput,FOREGROUND_GREEN|FOREGROUND_RED); 
cout<<"#| x| results \n";

for(x=a;x<=b;x=x+h)
{SetConsoleTextAttribute(consoleOutput,FOREGROUND_GREEN);
	z++;
	cout<<z<<"| ";
SetConsoleTextAttribute(consoleOutput,FOREGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	cout<<x<<"|";
SetConsoleTextAttribute(consoleOutput,FOREGROUND_BLUE|FOREGROUND_INTENSITY|FOREGROUND_RED);
	S=0;
   for(n=1;n<=m;n++)
    {c=2*n;
     d=c/(c-1);
     e=d/(c+1);
     s=e*Tanh(2*n*x);
     S=S+s;
     }
cout<<" "<<S<<"\n";
}
}


