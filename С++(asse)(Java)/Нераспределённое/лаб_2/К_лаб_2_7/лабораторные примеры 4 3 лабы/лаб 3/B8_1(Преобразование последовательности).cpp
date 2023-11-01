/*
�������� ����� ���������
1 ����
������ ��-8

�������: 8.	������������� ������������������ A=(ai),i=1..n, n<=100,
���������� ������� ��� ����������, ����� ��� ���������,
�������� �� �������, �� ��������� �������������� ������.

��������:
������� ������������ �������.����� ��� �������� ������ ������������� �������� � ������ �������.

�����:
�������         ��������� �����
n = 15
Initial massive:
4 6 5 9 6 5 6 2 5 3 4 3 9 0 7
New massive:
9 9 4 6 5 6 5 6 2 5 3 4 3 0 7

*/

/*#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;*/
#include "functions.cpp"


int main(void)
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    in.open("input.txt");
    int n,max_a;
    in>>n;
    int *a;
    a=new int[n];
    cout<<"n = "<<n<<endl<<"Initial massive:"<<endl;;
    mas_int_rand(a,n); // ���������� �������
    mas_out(a,n);   // ����� �������
    cout<<endl<<"New massive:"<<endl;
    max_a=Max(a,n); // ���������� �����������
    Max_to_start(a,n,max_a);    // ����� ������������� � ������ �������
    mas_out(a,n);   // ����� ������ �������
    free(a);
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
