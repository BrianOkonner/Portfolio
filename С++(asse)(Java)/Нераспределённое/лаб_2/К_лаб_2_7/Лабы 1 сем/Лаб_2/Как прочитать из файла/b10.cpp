/*{Филисьев Антон 1 курс 7 группа}
{10.	Найти квадратный корень  , используя рекуррентное
соотношение: Xi=Xi-1/2 + A/(2*Xi-1 ), где Х0 =А,
с точностью 0.0001. если  А изменяется от d до b с шагом h.
Результаты получить в виде таблицы.}

{Используем функцию нахождения корня,основанную на
данном реккурентном соотношении. Выводим результат
с точностью до 0.0001. Рядом выводим значение посчитанное
через Функцию SQRT}*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

 using namespace std;
const  double eps=0.0001;

double koren(int a)
{
	double s,s1=a;
	double n=1;
	while (n>eps)
	{s=s1/2+a/(2*s1);
	n=fabs(s1-s);
	s1=s;}
	return(s);
}

/*int epsn(double n)
{
double x;
int k=0;
x=1/n;
while (x>1)
{x=x/10;
k++;}
return(k);
}*/

void main()
{
int a,b,d,h,l;
ofstream f2;
ifstream f1;

	f1.open("input.txt");
	if (!f1.is_open())
	{
		cerr << "Open file failed." << endl;
	//	return 0;
	}
	f2.open("output.txt");
	while (!f1.eof())
	{
		f1>>d>>b>>h;
        f2<<"a izmen ot d="<<d<<" do b="<<b<<" s shagom h="<<h<<endl; 
    a=d;
	l=epsn(eps);
	while (a<b) 
	{
     f2<<setprecision(10)<<setw(20)<<a<<setprecision(10)<<setw(20)<<koren(a)<<setprecision(10)<<setw(20)<<sqrt(a);
	a+=h;
	f2<<endl;
	}
}

}