/* �������� ������    �� 8

�8. ��������� �������� ���� S=sum((1+arctanh(x))/(1+n^3)*cos(2*n*x), n=1..m )
��� �������� m, ���� x ���������� �� a �� b
c ����� h. ���������� �������� � ���� �������.
                     
					  �������
 ������� ������ ����� ����� ���������:
 1) ������� � ��������������� ���������� ����������� ����� ��� �������.
 2) ��������� ������� ��  ���������� �math

�����  ���������� ����� ����������� �� ������.

�����:
m		a		b		h			sum					sum
50      -0.5     0.9     0.2        
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include "header.h"
using namespace std;
//long double Cos_asm(long double);
//long double Arctanh(long double);
int main()
{
long double x,y=0,y1=0,y2=0,a,b,h,atanh;
int m,n;
ifstream in; ofstream out;
in.open("input.txt"); 
out.open("output.txt");
setlocale(LC_ALL,"rus");
in>>m>>a>>b>>h;
int start = clock();
x=a;
out<<endl<<"                 x"<<"                 y"<<y1<<"                 y_asm"<<"                 y2_fcos"<<endl;


while (b>=x)
 {y1=0; y=0; y2=0;
   if (fabs(x)>=1) 
      {
		  out<<"��� �� ���������� �.�. |x|>=1"<<endl;
        x+=h; 
        continue;
                    } 
   for (n=1; n<=m;n++)
    {  y+=(1+ Arctanh_asm(x)) / (1+n*n*n)+Cos_asm(2*n*x);
       atanh=0.5*log((1+x)/(1-x));
       y1+= (1+atanh) / (1+n*n*n)  +cos(2*n*x);
       y2+=(1+farctanh_asm(x) ) / (1+n*n*n)+fcos_asm(2*n*x);
     }
  out<<setw(20)<<x<<setw(20)<<y1<<setw(20)<<y<<setw(20)<<y2<<endl;
  x+=h;
  
 }

int end = clock();
int time = end - start;
		out << "����� ����������� ���������� �� ������: " << time / 1000. << " ������" << endl;
		out.close();
system("pause");
return 0;
}