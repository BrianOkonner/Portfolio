/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: A3.	Заполнить квадратную  матриу А размерности N*N (N<=100) натуральными числами
по  свертывающейся спирали.

Тесты:

n=8

Matrix

    1    2    3    4    5    6    7    8
   28   29   30   31   32   33   34    9
   27   48   49   50   51   52   35   10
   26   47   60   61   62   53   36   11
   25   46   59   64   63   54   37   12
   24   45   58   57   56   55   38   13
   23   44   43   42   41   40   39   14
   22   21   20   19   18   17   16   15

Vremya vipolneniya: 0.022

n=5

Matrix

    1    2    3    4    5
   16   17   18   19    6
   15   24   25   20    7
   14   23   22   21    8
   13   12   11   10    9

Vremya vipolneniya: 0.021
*/

#include "functions.cpp"


int main(void)
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    in.open("input_a3.txt");
    int n,i,j,k,c=1;
    in>>n;
    int **a;
    matr_empty(a,n,n);
    i=0;
    while(i<n/2)
    {
        k=i;
        for(j=i;j<n-i;j++)
            a[k][j]=c++;
        j=n-i-1;
        for(k=i+1;k<n-i-1;k++)
            a[k][j]=c++;
        k=n-i-1;
        for(j=n-i-1;j>=i;j--)
            a[k][j]=c++;
        j=i;
        for(k=n-i-2;k>=i+1;k--)
            a[k][j]=c++;
        i++;
    }
    if(n%2!=0)
    {
        a[(n/2)][n/2]=c++;
    }
    cout<<"Matrix"<<endl<<endl;
    matr_out(a,n,n);
    matr_free(a,n);
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
