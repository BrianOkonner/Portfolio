#include <iostream>
#include <cstdlib>
 using namespace std;
int main(void)
{
	setlocale(LC_ALL,".1251");
	double buf=0,p=0,o=0,r=0,i=0,e=0.00001;
	cout<<"Введите начальное и конечное значения аргумента отрезка поиска корня через \"Enter\": "<<endl;
	cin>>o>>p;
	r=p-(p-o)/2;
	for(i=0;abs(r-o)>e;i++)
	{
		o=r;
		r=sqrt(log(1+r)+3);
	}
	o=5;//Посчитано отдельно
	cout<<"Найденный корень с заданной точностью: "<<r<<endl;
	cout<<"Числа итераций 1)Априорная оценка: "<<o<<endl<<"2)Последняя постериорная оценка: "<<i<<endl;
	system("pause");
}