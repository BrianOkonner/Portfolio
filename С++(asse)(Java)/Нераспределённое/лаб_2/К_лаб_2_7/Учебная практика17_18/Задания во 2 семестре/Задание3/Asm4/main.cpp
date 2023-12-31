﻿/*Якушев Семён 1 курс 8 группа
12.	Вычислить значения функции У=10sin(x)/(1+log(x^2)) , 
если  х изменяется от a до b с шагом h.
Результаты получить в виде таблицы.
создаю свою функцию синусов
для проверки использую стандартные функции
логарифм использую из стандартной библиотеки так как его разложение в ряд Тэйлора
только для x меньшего 1
(используя арифметический сопроцессор)
тесты
vvedite granicy izmenenia x (a, b a<b)
1
9
vvedite shag (h)
1
╒══════════╦══════════════════════╦══════════════════════╕
│  x:      ║           answer:    ║my answer             │
╞══════════╬══════════════════════╬══════════════════════╡
│      2   ║             8.41471  ║     8.415            │
│      3   ║              5.6758  ║     5.676            │
│      4   ║            0.722121  ║    0.7221            │
│      5   ║            -3.43358  ║    -3.434            │
│      6   ║            -3.99895  ║    -3.999            │
│      7   ║            -1.09305  ║    -1.093            │
│      8   ║             2.44215  ║     2.442            │
│      9   ║             3.52564  ║     3.526            │
╘══════════╩══════════════════════╩══════════════════════╛
Для продолжения нажмите любую клавишу . . .


vvedite granicy izmenenia x (a, b a<b)
1
2
vvedite shag (h)
0.1
╒══════════╦══════════════════════╦══════════════════════╕
│  x:      ║           answer:    ║my answer             │
╞══════════╬══════════════════════╬══════════════════════╡
│    1.1   ║             8.41471  ║     8.415            │
│    1.2   ║             8.23069  ║     8.231            │
│    1.3   ║             8.04618  ║     8.046            │
│    1.4   ║             7.84729  ║     7.847            │
│    1.5   ║             7.62581  ║     7.626            │
│    1.6   ║             7.37693  ║     7.377            │
│    1.7   ║             7.09803  ║     7.098            │
│    1.8   ║             6.78805  ║     6.788            │
│    1.9   ║               6.447  ║     6.447            │
│      2   ║             6.07573  ║     6.076            │
╘══════════╩══════════════════════╩══════════════════════╛
Для продолжения нажмите любую клавишу . . .
	
*/
#include <iostream>
#include <math.h>
#include <iomanip>
#include "func.h"
using namespace std;

extern "C" double  __cdecl Mysin(double);
extern "C" double  __cdecl Result(double);

void main()
{
	double x,
		a,b,h,//границы и шаг
		y,rez;//результаты
	
	cout<<"vvedite granicy izmenenia x (a, b a<b)"<<endl;
	cin>>a>>b;
	cout<<"vvedite shag (h)"<<endl;
	cin>>h;
	cout << char(213) << setfill(char(205)) << setw(11) << char(203) << setw(23) << char(203) << setw(23) << char(184)<< "\n"; // начало таблицы
	cout << char(179) << setfill(' ') << setw(4) << "x:" << setw(7) << char(186) << setw(18) << "answer:" << setw(5) << char(186) << setw(9) << "my answer"<< setw(14) << char(179) << "\n";
	cout << char(198) << setfill(char(205)) << setw(11) << char(206) << setw(23) << char(206) << setw(23) << char(181) << "\n";
	cout << setfill(' ');
	x=a;
	while(x<=b)//считает для каждого x значение функции
	{
		//double q=Mysin(x);
		//rez=10*q/(1+mylog(x*x));
		rez = Result(x);
		y=10*sin(x)/(1+log10(x*x));
		x+=h;
		cout << char(179) << setw(7) << setprecision(3) << x-h << setw(4) << char(186) << setw(20) << setprecision(6) << y << setw(3) << char(186) << setw(10) << setprecision(6) << rez << setw(13) << char(179) << "\n";
	}//дальше конец таблицы
	cout << char(212) << setfill(char(205)) << setw(11) << char(202) << setw(23) << char(202) << setw(23) << char(190)<<"\n";
	

	system("pause");
}