#include <math.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const double pi=3.14159265;

int sover(int a) // �������� �� �����������
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

double cosx(double x, double eps) // ���������� ��������
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

double sinx(double x, double eps)   // ���������� ������
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

double ex(double x, double n)   // ���������� �^x
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

int step(int x, int n)  // ���������� � �������
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

int prost(int x)    // �������� ����� �� ��������
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

int nod(int x,int y)    // ���������� ���
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

int cnm(int n, int m)   // ���������� C �� n �� m
{
    int s=1;
    for(int i=1;i<=m;i++)
        s=s*(n-i+1)/i;
    return s;
}

int sum_c(int x)    // ����� ����
{
    int s=0;
    while(x>0)
    {
        s+=x%10;
        x=x/10;
    }
    return s;
}

int *mas_int_rand(int *a, int n)    // ���������� ������������ ������� ���������� �������
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%10;
    }
}

void mas_out(int *a, int n)     // ����� �������
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void mas_out_not_0(int *a, int n)   // ����� ������� �� ���������� 0 ��� ����� �������
{
    int j=0;
    while(a[j]!=0 && j<n)
    {
        //if (b[j]>0)
        cout<<a[j]<<" ";
        j++;
    }
}

void serii(int *a,int *b, int n)    // ����� ����� ������ ������ ���������� ���������
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

int Max(int *a,int n)   // ����� ������������� �������� � �������
{
    int max_a=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max_a)
            max_a=a[i];
    }
    return max_a;
}

void Max_to_start(int *a, int n, int max_a) // ������������ ������������� �������� � ������
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
