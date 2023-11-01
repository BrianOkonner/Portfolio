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
const double pi=3.14159265,e=2.71828182846;
double celayastep(double a,int b)//Возведение числа в целую степень
{
	double r=1,i;
	for(i=1;i<=b;i++)
		r=r*a;
	return r;
}
double tanH(int x) //Вычислить гиперболический тангенс через pow
{
	double h=1,k;
	h=pow(e,x);
	k=(h-(1/h))/(h+(1/h));
	return k;
}
unsigned _int64 facial(int n)//Вычислить факториал
{
	int a,b=1;
	if (n==0)
		return 0;
	for (a=1;a<=n;a++)
		b=b*a;
	return b;
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
	j=1/h;
	k=(h-(j))/(h+(j));
	return k;
}
long double tanH(double x,unsigned _int64 o)//Вычислить гиперболический тангенс (максимум лонг дабл)
{
	double h=1,k,j;
	h=estepx(x,o);
	j=1/h;
	k=(h-(j))/(h+(j));
	return k;
}
void mass_from_file(int *a,int n)//Ввод массива через файл
{
	int i;
	char h[40];
	ifstream in;
	setlocale(LC_ALL,".1251");
	cout<<"Введите имя считываемого файла: ";
	cin>>h;
	in.open(h);
	for(i=0;i<n;i++)

	{
		in>>a[i];
	}
	in.close();
}
void mass_cel_rand_mil(int *f, int n)//Заполнить массив целых случайным образом(Меняет последовательность с течением миллисекунды)   
{
	SYSTEMTIME st;
	Sleep(1);
	GetLocalTime(&st);
    srand(st.wMilliseconds);
    for(int i=0;i<n;i++)
    {
        f[i]=rand()%100;
    }
}
void change(int *a,int*b)
{
	*a=(*b)+(*a);
	*b=(*a)-(*b);
	*a=(*a)-(*b);
}
void bubble_srt(int *a,int n)//Сортировка улучшенным пузырьком
{
	int i,j,d=0,t=1;              
	i=1;
	while(i<=n && t!=0)
    {
		t=0;
		for (j=0;j<n-1;j++)
		{
		  if (a[j]>a[j+1]) 
		  {
			change(&a[j],&a[j+1]);
		    t=1;
		  }
		}
    i++;
	}
}
void bubble_srt_mtr2(int **a,int n,int m)//Сортировка улучшенным пузырьком
{
	int i,j,d=0,t=1,k;              
	i=1;
	while(i<=n )//&& t!=0)
    {
		t=0;
		for (k=0;k<n-1;k++)
			for (j=0;j<n-1;j++)
			{
			  if (a[j][k]>a[j+1][k]) 
			  {
				change(&a[j+1][k],&a[j][k]);
				a[j+1][k]=a[j][k]+a[j+1][k];
				a[j][k]=a[j+1][k]-a[j][k];
				a[j+1][k]=a[j+1][k]-a[j][k];
			    t=1;
				
			  }
			}
		i++;
	}
}
void mass_cel_rand(int *f, int n)//Заполнить массив целых случайным образом(Меняет последовательность с течением миллисекунды)   
{
    srand(time(NULL));
	Sleep(1000);
    for(int i=0;i<n;i++)
    {
        f[i]=rand()%10;
    }
}
void mass_cel_rand2(int *f, int n)//Заполнить массив целых случайным образом  
{
    srand(time(NULL));
	Sleep(1000);
    for(int i=0;i<n;i++)
    {
        f[i]=rand()%100;
    }
}
void frm_2ndcrs_to_ncrs(int* a,int *b,int n,int *h)//Из 2 неубывающих сделать возрастающий(функция большая, но по моему быстрая)
{
	int i=0,j=0,k=0;
	if (a[i]>b[j])//1.Если эл-т из 1-го массива больше эл-та 2-го массива присваиваем эл-ту 3-го массива наименьший из 2-ух.
	{
		h[k]=b[j];
		j++;//переходим к другому номеру только там откуда присвоили(далее так же кроме 3.,8., 9., 10. ).
	}
	else//Если нет
	{	
		if (a[i]<b[j])//2.Если эл-т из 1-го массива меньше эл-та 2-го массива присваиваем эл-ту 3-го массива наименьший из 2-ух.
		{
			h[k]=a[i];
			i++;
		}
		else
			if(a[i]==b[j])//3.Если эл-т из 1-го массива равен эл-ту 2-го массива присваиваем эл-ту 3-го массива любой из 2-ух.
			{
				h[k]=b[j];
				i++;
				j++;//переходим к другому номеру и во 2-ом и в 1-ом массивах т.к сработало равно
			}
	}
	for(;i<n|j<n;)//Далее работаем по циклу пока не проверим все эл-ты в 2-ух массивах
	{
		if(j>=n)//Условие для выхода из цикла если i уже не меньше n
		{
			if(a[i]>h[k])//4.Если эл-т из 1-го массива больше эл-та 3-го массива присваиваем эл-ту 3-го массива эл-т 1-го
			{
				k++;
				h[k]=a[i];
				i++;
			}
			else
			i++;//для выхода из цикла
		}
		else
		{
			if(i>=n)
			{
				if(b[j]>h[k])//5.Если эл-т из 2-го массива больше эл-та 3-го массива присваиваем эл-ту 3-го массива эл-т 2-го
				{
					k++;
					h[k]=b[j];
					j++;
				}
				else
				j++;
			}
			if(a[i]<b[j]&&a[i]>h[k])//6.Если эл-т из 1-го массива меньше эл-та 2-го массива и больше эл-та 3-го эл-ту 3-го массива присваиваем эл-т из 1-го.
			{
				k++;
				h[k]=a[i];
				i++;
			}
			else
			{
				if(b[j]<a[i]&&b[j]>h[k])//7.Если эл-т из 2-го массива меньше эл-та 1-го массива и больше эл-та 3-го эл-ту 3-го массива присваиваем эл-т из 2-го.
				{
					k++;
					h[k]=b[j];
					j++;
				}
				else
				{
					if(a[i]<b[j]&&a[i]==h[k])//8.Если эл-т из 1-го массива меньше эл-та 2-го массива и равен эл-ту 3-го переходим к следующему из 1-го
					i++;
					else
					{
						if(a[i]>b[j]&&b[j]==h[k])//9.Если эл-т из 2-го массива меньше эл-та 1-го массива и равен эл-ту 3-го переходим к следующему из 2-го
						j++;
						else
						{
							if(a[i]==b[j]&&b[j]==h[k])//10.Если эл-ты массивов равны переходим ко следующим эл-там во 2-ом и 1-ом массивах
							{
								i++;
								j++;
							}
							else//Если условия не сработали эл-ту 3-го массива присваиваем любой из двух
							{
								k++;
								h[k]=a[i];
								i++;
								j++;//Переходим сразу в 2-ух массивах
							}
						}
					}
				}
			}
		}
	}
}
void vvd_L3B9(int *a,int *b,int *h,int n)//Вывод значений массивов для задачи L3(B9)(Не работает не в майне нарушает права доступа)
{
	int i=0;
	cout<<"     Массивы: "<<endl;
	cout<<left<<setw(20)<<"1-ый Неубывающий"<<left<<setw(20)<<"2-ой Неубывающий"<<left<<setw(20)<<"Возрастающий массив"<<endl;
	while (a[i]>=0&&h[i]>=0&&b[i]>=0)
	{
		cout<<left<<setw(20)<<a[i]<<left<<setw(20)<<b[i]<<left<<setw(20)<<h[i]<<endl;
		i++;
	}
	if(a[i]<0)
	{
	while (h[i]>=0)
		{
			cout<<left<<setw(40)<<" "<<h[i]<<endl;
			i++;
		}
	}
	else
	{
		while (a[i]>=0)
		{
			cout<<left<<setw(20)<<a[i]<<left<<setw(20)<<b[i]<<endl;
			i++;
		}
	}
}
void MoveRight(int *a,int *n,int num)
{
	for(int i=*n;i>=(num);i--)
		a[i]=a[i-1];	
	(*n)++;
}
void DeleteCh(int *a, int *n, int item)// Удаление   из массива элементов = item
 { 	
  int i=0; 
  while (i<*n) 
  {   
   if (a[i]==item) 
       MoveLeft(a, n, i);
 //Сдвигаем и удаляем элемент
   else		
   i++;  } 
  }
void MoveLeft(int * a,int *n, int num)//сдвигаем все  элементы на 1 позицию влево после номера num
{  
for (int i=num-1;  i<*n-1;   i++)                 
   a[i]=a[i+1]; 
   *n=*n-1;
} 
void delreusage(int *a,int *n)
{
	int i=0;
	while(i<*n)
	if(a[i]=a[i+1])
		DeleteCh(a,n,a[i]);
}
void delrowreusage(int *a,int *n)
{
	int i=0;
	while(i<*n-1)
	{
		if(a[i]==a[i+1])
			MoveLeft(a,n,i+1);
		else
			i++;
	}
}
int BinarySearch_L3nomatr (int *a,int n,int x)
{
	int m,i,j,b=0;
	if(n%2==1)
		m=(n/2)+1;
	m=n/2;
	i=m;
	j=m;
	while(j!=-12)
	{	
		if(x<a[m-1]&&m==0)
		{
			return m-1;
			break;
		}
		else
			if(x<a[m-1]&&x>=a[m-2])
			{
				return m-1;
				break;
			}
			else
				if(x>a[m-1])
				{
					if(j%2==1)
						j++;
					b=b+j;
					j=j/2;
					m=b+j;
					cout<<"a"<<m-1<<endl;
				}
				else
				{
					if(j%2==1)
						j++;
					j=j/2;
					m=b+j;
					cout<<"b"<<m-1<<endl;
				}
	}
	return -1;
}
int BinarySearch_L3 (int **a,int n,int x, int k)
{
	int m,i,j,b=0;
	if(n%2==1)
		m=(n/2)+1;
	m=n/2;
	i=m;
	j=m;
	while(j!=-12)
	{	
		if(x<a[m-1][k]&&m==0)
		{
			return m-1;
			break;
		}
		else
			if(x<a[m-1][k]&&x>=a[m-2][k])
			{
				return m-1;
				break;
			}
			else
				if(x>a[m-1][k])
				{
					if(j%2==1)
						j++;
					b=b+j;
					j=j/2;
					m=b+j;
					cout<<"a"<<m-1<<endl;
				}
				else
				{
					if(j%2==1)
						j++;
					j=j/2;
					m=b+j;
					cout<<"b"<<m-1<<endl;
				}
	}
	return -1;
}
void input_matr_rand2(int **a, int n,int m)
{
	int i,j;
	srand(time(NULL));
	Sleep(1000);
	for(j=0;j<n;j++)
		for(i=0;i<m;i++)
			a[i][j]=rand()%100;
}
void input_matr_zer(int **a, int n,int m)
{
	int i,j;
	for(j=0;j<n;j++)
		for(i=0;i<m;i++)
			a[i][j]=0;
}
void vivodmass(int *a,int n)
{
	int i=0;
		while (i<n)
	{
		cout<<a[i]<<" ";
		i++;
	}
	cout<<endl;
}
/*void Ungamatr(int *a,int **b,int n)
{
	int j=0,i=0,k=0,o=0,p;
	b[i][j]=a[k];
	k++;
	i++;
	if (b[i][j]<1000&&b[i][j]>-1)
	{
		if (a[k]>b[i][j])
		{
			b[i][j]=a[k];
			k++;
			i++;
			o++;
		}
		else
		{
			p=BinarySearch_L3 (**b,o,a[k],j);
			
	}
}*/



