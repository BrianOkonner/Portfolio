/*
�������� ����� ���������
1 ����
������ ��-8

�������: C8.	��� A=(ai) ,  i=1..n,  (n<=10),������  � ����� b.
�����������  �����  � �������  �����  �������, ����� ������� ���  ��������,  �������  b, ����� ������ b, � ���� ����� ������� b.

��������:
��� ���������� �������(��� ��� ������ ������� �� �������) ������� ���������� ��������� �������, ������ � ������� b.
����� ��� ������� �� ������� ����������� ����� �� ��������� ������.

�����:

n = 9   b = 6
Initial massive :
-1 -2 -3 6 -9 -6 6 -9 9

New massive :
-1 -2 -3 -9 -9 -6 6 6 9


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
    int a[11];
    int n,b,i,count_more=0,count_less=0,count_equal=0,tmp,j,k;
    in>>n>>b;
    out<<"n = "<<n<<"   b = "<<b<<endl<<"Initial massive :"<<endl;
    for(i=0;i<n;i++)
    {
        in>>a[i];
        if(a[i]>b)
            count_more++;
        if(a[i]==b)
            count_equal++;
        if(a[i]<b)
            count_less++;
        out<<a[i]<<" ";
    }
    out<<endl<<endl;
    i=0;j=count_less;k=j+count_equal;
    while(i<count_less+count_equal)
    {
        if(i<count_less)
        {
            if(a[i]<b)
                i++;
            else
            {
                if(a[i]==b)
                {
                    tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                    j++;
                }
                else
                {
                    tmp=a[i];
                    a[i]=a[k];
                    a[k]=tmp;
                    k++;
                }
            }
        }
        else
        {
            if(a[i]==b)
                i++;
            else                    //a[i]>b
            {
                tmp=a[i];
                    a[i]=a[k];
                    a[k]=tmp;
                    k++;
            }
        }
    }
    out<<"New massive :"<<endl;
    for(i=0;i<n;i++)
    {
        out<<a[i]<<" ";
    }
    clk=clock();
    out.close();
    cout<<endl<<endl<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
