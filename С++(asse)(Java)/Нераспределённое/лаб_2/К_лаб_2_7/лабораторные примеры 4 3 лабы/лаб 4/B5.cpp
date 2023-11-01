/*
�������� ����� ���������
1 ����
������ ��-8

�������: B5.
�������� ������� A=(aij),  i,j=1..n,  n<=100, ����������   ������� �������� ���
�����������  �����,  �����������  ������� �� ������ ������������ ������� ���������, ����
1   2    6   7
3   5    8   13
4   9    12  14
10  11   15  16


�����:

4      Matrix:

           1   2    6   7
           3   5    8  13
           4   9   12  14
          10  11   15  16

7       Matrix:

           1   2   6   7  15  16  28
           3   5   8  14  17  27  29
           4   9  13  18  26  30  39
          10  12  19  25  31  38  40
          11  20  24  32  37  41  46
          21  23  33  36  42  45  47
          22  34  35  43  44  48  49
*/
#include "functions_h.h"
#include "functions.cpp"


int main(void)
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    in.open("input.txt");
    int n,i;
    in>>n;
    int **a;
    matr_empty(a,n,n);
    zmeika(a,n);
    cout<<"Matrix:"<<endl<<endl;
    matr_out(a,n,n);
    matr_free(a,n);
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
