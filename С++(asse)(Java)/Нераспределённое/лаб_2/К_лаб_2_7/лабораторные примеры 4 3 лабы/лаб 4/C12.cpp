/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: 12.	Характеристикой строки целочисленной матрицы назовем сумму ее положительных четных элементов.
Переставляя строки заданной матрицы, расположить их в соответствии с ростом характеристик.

Тесты:

Matrix:

    7    4    0    8    8    3    3
    3    9    7    3    5    8    3
    2    8    2    9    4    8    4
    8    6    4    8    5    8    0

New matrix:
    3    9    7    3    5    8    3
    7    4    0    8    8    3    3
    2    8    2    9    4    8    4
    8    6    4    8    5    8    0
*/
#include "functions_h.h"
#include "functions.cpp"


int main(void)
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    in.open("input_c12.txt");
    int n,m,i,j;
    in>>n>>m;
    int **a;
    int **c;
    int *tmp;
    matr_empty(c,2,n);
    for(i=0;i<n;i++)
    {
        c[0][i]=0;
        c[1][i]=i;
    }
    matr_empty(a,n,m);
    matr_int_rand(a,n,m);
    cout<<"Matrix:"<<endl<<endl;
    matr_out(a,n,m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]>0)
                if(a[i][j]%2==0)
                    c[0][i]+=a[i][j];

        }
        //cout<<"~";
    }
    for(int k=n-1;k>0;k--)
    {
        int f=0;
        for( i=0;i<k;i++)
        {
            if(c[0][i]>c[0][i+1])
            {
                    c[0][i]=c[0][i]^c[0][i+1];
                    c[0][i+1]=c[0][i]^c[0][i+1];
                    c[0][i]=c[0][i]^c[0][i+1];
                    c[1][i]=c[1][i]^c[1][i+1];
                    c[1][i+1]=c[1][i]^c[1][i+1];
                    c[1][i]=c[1][i]^c[1][i+1];
                    tmp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=tmp;
                f=1;
            }
        }
        if(f==0)
            break;
    }

    /*cout<<endl<<"c:"<<endl;
    for(i=0;i<2;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/

    cout<<"New matrix:"<<endl<<endl;
    matr_out(a,n,m);
    matr_free(a,n);
    free(c);
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
