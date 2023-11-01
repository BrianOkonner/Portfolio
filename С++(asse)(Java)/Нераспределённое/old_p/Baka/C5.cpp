/*
�������� ����� ���������
1 ����
������ ��-8

�������: C5.	����  ���  ����������� ������� X=(xi),i=1..n, n<=10,  � Y=(yi),i=1..m, m<=10  �  ����� q.
����� ����� ���� (x(i)+y(j)), �������� ������� � ����� q.
(����� �������� ������� m+n, �������������� ������ - ������������� ����� ����� ����������, ���� ������� ������ �� �����������.)

��������:
���������� ����� x[i] � q-y[j], ������� ����������� ���������� ����� ������� ������ ���� - ����� ��� �������� ������� � q ����� ����� ��� ��� i,j ��� ���������� ����������.
��������� O(m+n)

�����:
�������
5 5 20 1 2 3 5 9 2 7 8 9 12 // n m q Xn Ym

��������� �����

1 2 3 5 9
2 7 8 9 12
Blizhaiwaya summa ravna 21
Vremya vipolneniya: 0.007

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int x[11],y[11];
    int n,m,q,i,j,s;
    in>>n>>m>>q;
    cout<<"n = "<<n<<"   m = "<<m<<"   q = "<<q<<endl;
    for(i=0;i<n;i++)
    {
        in>>x[i];
        cout<<x[i]<<" ";
    }
    cout<<endl;
    for(j=0;j<m;j++)
    {
        in>>y[j];
        cout<<y[j]<<" ";
    }
    cout<<endl;
    i=0;j=m-1;
    int min_dif=abs(q-y[j]-x[i]);
    s=x[i]+y[j];
    while (i<n && j>=0)
    {
        if((q-y[j]-x[i])==0)
        {
            cout<<"Blizhaiwaya summa ravna "<<q<<endl;break;
        }
        else
        {
            if(q-y[j]>x[i])
            {
                if(i!=n-1)
                    i++;
                else
                {
                    if(q-y[j]-x[i]<min_dif)
                        s=x[i]+y[j];
                    cout<<"Blizhaiwaya summa ravna "<<s<<endl;break;
                }
            }
            else                                    //q-y[j]<x[i]
            {
                if(j!=0)
                {
                    if(i==0)
                    {
                        if(abs(q-y[j]-x[i])<min_dif)
                            {s=x[i]+y[j];min_dif=abs(q-y[j]-x[i]);}
                        j--;
                    }
                    else
                    {
                        if(abs(q-y[j]-x[i-1])<min_dif)
                            {s=x[i-1]+y[j];min_dif=abs(q-y[j]-x[i-1]);}
                        if(abs(q-y[j]-x[i])<min_dif)
                            {s=x[i]+y[j];min_dif=abs(q-y[j]-x[i]);}
                        j--;
                    }
                }
                else                                //j==0
                {
                    if(abs(q-y[j]-x[i-1])<min_dif)
                            {s=x[i-1]+y[j];min_dif=abs(q-y[j]-x[i-1]);}
                    if(abs(q-y[j]-x[i])<min_dif)
                            {s=x[i]+y[j];min_dif=abs(q-y[j]-x[i]);}
                    cout<<"Blizhaiwaya summa ravna "<<s<<endl;break;
                }
            }
        }
    }
    clk=clock();
    out.close();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
