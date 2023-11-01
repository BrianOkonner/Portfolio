#include <math.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
using namespace std;
const double pi=3.14159265;

int sover(int a) // Проверка на совершенные
{
    int s=1,i;
    for(i=2;i<=a/2;i++)
        if(a%i==0)
            s+=i;
    if(a==s && a!=1)
        return 1;
    else
        return 0;
}

double cosx(double x, double eps) // Вычисление косинуса
{
    int n=1;
double c,t,i=1;
while(x>2*pi)
    x-=2*pi;
while(x<0)
    x+=2*pi;
t=1;c=t;
while(fabs(t)>=eps)
{
    t=(-1*t*x*x)/(2*n*(2*n-1));
    c+=t;
    n++;
}
return c;
}

double sinx(double x, double eps)   // Вычисление синуса
{
    int n=1;
double c,t,i=1;
while(x>2*pi)
    x-=2*pi;
while(x<0)
    x+=2*pi;
t=x;c=t;
while(fabs(t)>=eps)
{
    t=(-1*t*x*x)/(2*n*(2*n+1));
    c+=t;
    n++;
}
return c;
}

double ex(double x, double n)   // Вычисление е^x
{
double c,t,i=1;
t=1;c=t;
while(i<=n)
{
    t=t*x/i;
    c+=t;
    i++;
}
return c;
}

int step(int x, int n)  // Возведение в степень
{
    int r=1;
    while(n!=0)
        {
        if(n%2==1)
            r=r*x;
        x=x*x;
        n=n/2;
        }
        return r;
}

int prost(int x)    // Проверка числа на простоту
{
    int flag,d;
    if(x==2 || x==3)
        flag=1;
    else
    {
        d=2;flag=1;
        while((d<=x/2) &&  (flag))
            if(!(x%d))
                flag=0;
            else
                d++;
    }
    return flag;
}

int nod(int x,int y)    // Вычисление НОД
{
    int r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int cnm(int n, int m)   // Вычисление C из n по m
{
    int s=1;
    for(int i=1;i<=m;i++)
        s=s*(n-i+1)/i;
    return s;
}

int sum_c(int x)    // Сумма цифр
{
    int s=0;
    while(x>0)
    {
        s+=x%10;
        x=x/10;
    }
    return s;
}

void mas_int_rand(int *a, int n)    // Заполнение статического массива случайными числами
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%10;
    }
}

void mas_out(int *a, int n)     // Вывод массива
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void mas_out_not_0(int *a, int n)   // Вывод массива до достижения 0 или конца массива
{
    int j=0;
    while(a[j]!=0 && j<n)
    {
        //if (b[j]>0)
        cout<<a[j]<<" ";
        j++;
    }
}

void serii(int *a,int *b, int n)    // Поиск серий подряд идущих одинаковых элементов
{
    int i,j=0,c=1;
    for(i=1;i<n;i++)
    {
        b[j++]=c;
        if(a[i]==a[i-1])
            c++;
        else
            c=1;
    }
    b[j++]=c;
    b[j]=0;
}

int Max(int *a,int n)   // Поиск максимального элемента в массиве
{
    int max_a=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max_a)
            max_a=a[i];
    }
    return max_a;
}

void Max_to_start(int *a, int n, int max_a) // Перестановка максимального элемента в начало
{
    int tmp;
    for(int i=1;i<n;i++)
    {
        if(a[i]==max_a)
        {
            for(int j=i;j>0;j--)
            {
                tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
            }
        }
    }
}

int Line_search(int *a, int n, int x)   // Линейный поиск
{
    for(int i=0;i<n;i++)
        if(a[i]==x)
            return i;
    return -1;
}


void swap_ab(int *a, int *b)  // Обмен элементов
{
    *a=(*a)^(*b);
    *b=(*a)^(*b);
    *a=(*a)^(*b);
}

void swap_mas_ij(int *a, int i, int j)
{
    a[i]=a[i]^a[j];
    a[j]=a[i]^a[j];
    a[i]=a[i]^a[j];
}

void int_BubbleSort(int *a, int n)
{
    for(int i=n-1;i>0;i--)
    {
        int f=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap_mas_ij(a,j,j+1);
                f=1;
            }

        }
        if(f==0)
                break;
    }
}

int Binary_search(int *a, int x, int r, int l=0)     // Двоичный поиск
{
int m=(l+r)/2;
if (*(a+m) == x)
    return m;
if (m == l || m == r)
    return -1;
if (*(a+m) < x)
    Binary_search(a, x, r, m);
else
    Binary_search(a, x, m);
}

void matr_empty(int **& a, int n, int m)
{
    a=new int*[n];
    for(int i=0;i<n;i++)
        a[i]=new int[m];
}

void matr_free(int **a, int n)
{
    for(int i=0;i<n;i++)
        delete[] a[i];
    delete[] a;
}

void matr_int_rand(int **a, int n, int m)
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j]=rand()%10;
        }
    }
}

void matr_out(int **a, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<setw(5)<<a[i][j];
        }
       cout<<endl;
    }
    cout<<endl;
}

void zmeika(int **a, int n)
{
    int i=0,j=0,p=1,t;
    a[i][j]=p++;
    for(t=1;t<n;t++)
    {
        if(i==0)
        {
            j++;
            a[i][j]=p++;
            while(j!=0)
            {
                i++;
                j--;
                a[i][j]=p++;
            }
            continue;
        }
        if(j==0)
        {
            i++;
            a[i][j]=p++;
            while(i!=0)
            {
                j++;
                i--;
                a[i][j]=p++;
            }
            continue;
        }
    }

    for(t=1;t<n-1;t++)
    {
        if(i==(n-1))
        {
            j++;
            a[i][j]=p++;
            while(j!=(n-1))
            {
                i--;
                j++;
                a[i][j]=p++;
            }
            continue;
        }
        if(j==(n-1))
        {
            i++;
            a[i][j]=p++;
            while(i!=(n-1))
            {
                j--;
                i++;
                a[i][j]=p++;
            }
            continue;
        }
    }
    a[n-1][n-1]=p++;
}

void max_even_in_columns(int **a,int *c,int n, int m)
{
 for(int j=0;j<m;j++)
    {
        c[j]=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][j]%2==0)
            {
                c[j]++;
            }
        }
    }
}

int max_2(int a, int b)
{
    return a>=b ? a : b;
}
int max_3(int a,int b, int c)
{
    return max_2(max_2(a,b),c);
}
