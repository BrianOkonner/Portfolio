/*													Задача №b9
		Программу написал Владислав Владимирович Перевязчиков.( Специальность: прикладная матнмематика. Группа 8)
		Условие : Вычислить:  S  при  заданном m, если  х изменяется от a до b с шагом h. Результаты получить в виде таблицы. 
		Кратктий алгоритм : Данные берем через ввод с клавиатуры определяем что больше из а и b и взависимости от этого идем вверх(+)
		либо вниз(-) выполняя тангенс a которое мы меняем до b отнимая или прибавляя h.
		Тесты:
Введите число m: 14
Введите шаг h по которому будет менятся значение аргумента: 1
Введите число а (начальное значение аргумента): 8
Введдите чило b (конечное значение аргумента): 0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               *               Искомая Сумма                 *
*      Значения аргумента х     * * * * * * * * * * * * * * * * * * * * * * * *
*                               *      Через tanH      *      через th        *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* 8                             * 0.5006385696040868   * 0.5006385696040868   *
* 7                             * 0.5006385696040868   * 0.5006385696040868   *
* 6                             * 0.5006385696040868   * 0.5006385696040868   *
* 5                             * 0.5006385696040868   * 0.5006385696040868   *
* 4                             * 0.5006385696040868   * 0.5006385696040868   *
* 3                             * 0.5006385696040868   * 0.5006385696040868   *
* 2                             * 0.5006385695919098   * 0.5006385695919098   *
* 1                             * 0.5006350778200358   * 0.5006350778200358   *
* 0                             * 0                    * 0                    *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *                                                       */
const double pi=3.14159265;
double facial(int n)//Вычислить факториал
{
	double b=1,a;
	if (n==0)
		return 0;
	for (a=1;a<=n;a++)
	{
		_asm
		{
			finit
			fld b
			fld a
			fmul
			fst b
		}
	}
	return b;
}
double celayastep(double a,int b)//Возведение числа в целую степень
{
	double r=1,i;
	if(b==0)
		return 1;
	else
	{
		for(i=1;i<=b;i++)
		{
			_asm
			{
				finit
				fld r
				fld a
				fmul
				fst r
			}	
		}
		return r;
	}
}
double estepx(double x,int o)//Вычислить е в степени х
{
	double h=1,s=1; int k;
	for(k=1;k<=o;k++)
		s=s+(celayastep(x,k)/facial(k));
	return s;
}
double tanH(double x,int o)//Вычислить гиперболический тангенс 
{
	double h=1,k,j;
	h=estepx(x,o);
	_asm
	{
		finit 
		fld1
		fld h
		fdiv
		fst j
		finit
		fld h
		fld j
		fadd 
		fst k
		fld j
		fsub
		fld j 
		fsub
		fld k
		fdiv
		fst k
	}
	//k=(h-(j))/(h+(j));
	return k;
}
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	double s=0,m,j,c,b,h,a,p; const double pi=3.14159265; unsigned _int64 v;long double o;
	setlocale(LC_ALL,".1251");
	cout<<"Введите число m: ";
	cin>>m;
	cout<<"Введите шаг h по которому будет менятся значение аргумента: ";
	cin>>h;
	if (h<=0)
	{
	cout<<"Ошибка h только положителен, введите h повторно";
	cin>>p;
	h=p;
	}
	cout<<"Введите число а (начальное значение аргумента): ";
	cin>>a;
	cout<<"Введдите чило b (конечное значение аргумента): ";
	cin>>b;
	cout<<"Введите точность гиперболического тангенса(больше 12 работает неправильно): ";
	cin>>v;
	for(j=1;j!=(m+1);j++)
	{
		double d1=1, d2=2,zn,nz;
//		s=s+((2*m)/((2*m+1)*(2*m-1)));
		_asm
		{
			finit
			fld m
			fld d2
			fmul //s0=2m
			fst nz
			fld d1
			fadd //s0=2m+1
			fst zn
			fld d2
			fsub
			fld zn
			fmul//s0=(2m+1)(2m-1)
			fst zn
			finit
			fld nz
			fld zn
			fdiv
			fld s
			fadd
			fst s
		}
	}
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	cout<<"* "<<left<<setw(30)<<""<<"* "<<left<<setw(43)<<"              Искомая Сумма"<<" *"<<endl;
	cout<<"* "<<left<<setw(30)<<"     Значения аргумента х"<<left<<"* * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<"* "<<left<<setw(30)<<""<<"* "<<left<<setw(21)<<"     Через tanH"<<"* "<<left<<setw(20)<<"    через tanh"<<" *"<<endl;
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	if (a<b)
	{
		while (a<b)
		{
			o=tanh(2*pi*a);
			c=tanH(2*pi*a,v);
			cout<<setprecision(16)<<"* "<<left<<setw(30)<<a<<"* "<<left<<setw(21)<<c*s<<"* "<<left<<setw(20)<<o*s<<" *"<<endl;
			a+=h;
		}
	} 
	else
	{
		while(a>b)
		{
			o=tanh(2*pi*a);
			c=tanH(2*pi*a,v);
			cout<<setprecision(16)<<"* "<<left<<setw(30)<<a<<"* "<<left<<setw(21)<<c*s<<"* "<<left<<setw(20)<<o*s<<" *"<<endl;
			a-=h;
		}
	}
	o=tanh(2*pi*b);
	c=tanH(2*pi*b,v);
	cout<<setprecision(16)<<"* "<<left<<setw(30)<<b<<"* "<<left<<setw(21)<<c*s<<"* "<<left<<setw(20)<<o*s<<" *"<<endl;
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	system("pause");
}
