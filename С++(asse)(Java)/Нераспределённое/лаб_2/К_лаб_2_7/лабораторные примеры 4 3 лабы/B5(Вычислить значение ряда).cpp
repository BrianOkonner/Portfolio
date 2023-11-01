/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие:5.	Вычислить значение ряда:  S+=(x^(2*n+1))*cos2nx/(2*n+2)
при заданном m, если  х изменяется от a до b с шагом h. Результат получить в виде таблицы.

Тесты:
Условие
Начальные данные:
m=5; a=3; b=7; h=0.5;

Полученый вывод
┌────────┬───────────────┐
│       x│              S│
├────────┼───────────────┤
│       3│        3332.87│
├────────┼───────────────┤
│     3.5│       -80716.1│
├────────┼───────────────┤
│       4│        -210540│
├────────┼───────────────┤
│     4.5│         659918│
├────────┼───────────────┤
│       5│   3.79786e+006│
├────────┼───────────────┤
│     5.5│         716106│
├────────┼───────────────┤
│       6│  -2.94439e+007│
├────────┼───────────────┤
│     6.5│  -4.13358e+007│
├────────┼───────────────┤
│       7│   1.07756e+008│
└────────┴───────────────┘


*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <ctime>
#include <math.h>
#include "functions_h.h"
#include "functions.cpp"

using namespace std;

int main(void)
{
    setlocale(LC_ALL,".1251");
    ifstream in;
    ofstream out;
    unsigned int clk;
    int m,n;
    out.precision(12);
    double a,b,h,x,s,s2,t,cos_x,cos_x2,tmp;
    in.open("input.txt");
    out.open("output.txt");
    in>>m>>a>>b>>h;

    out<<"Начальные данные: m="<<m<<"; a="<<a<<"; b="<<b<<"; h="<<h<<";"<<endl;
    out<<"┌────────┬───────────────┬───────────────┐"<<endl;
    out<<"│"<<setw(8)<<"x"<<"│"<<setw(15)<<"S"<<"│"<<setw(15)<<"S(standart)"<<"│"<<endl;
    if(a>b)
    {
        tmp=a;a=b;b=tmp;
    }
    for(x=a;x<=b;x+=h)
    {
        s=0;t=x;s2=2;
        for(n=1;n<=m;n++)
        {
            t=t*x*x;
            cos_x=cosx(2*x*n,0.0005);
            cos_x2=cos(2*x*n);
            //cout<<"!!"<<cos_x<<"!! ";
            s+=t*cos_x/(2*n+2);
            s2+=t*cos_x2/(2*n+2);
        }
        out<<"├────────┼───────────────┼───────────────┤"<<endl;
        out<<"│"<<setw(8)<<x<<"│"<<setw(15)<<s<<"│"<<setw(15)<<s2<<"│"<<endl;
    }
    out<<"└────────┴───────────────┴───────────────┘"<<endl;
    out<<endl;
    clk=clock();
    out<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    out.close();
    return 0;
}
