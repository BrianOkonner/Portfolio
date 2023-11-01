/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: B11.	Найти номера столбцов матрицы A=(aij) ,  i=1..n, j=1..m, (n,m<=100),
которые содержат наибольшее количество четных элементов.

Тесты:

n=7, m=4            Matrix:

                    6    1    5    2
                    9    5    2    4
                    1    8    2    1
                    2    2    5    9
                    8    8    0    9
                    3    8    8    4
                    0    0    8    5

                    Columns numbers:
                    2 3
*/
#include "functions_h.h"
#include "functions.cpp"


int main(void)
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    in.open("input_b8.txt");
    int n,m,i,j;
    in>>n>>m;
    int **a;
    int *c;
    c=new int[m];
    matr_empty(a,n,m);
    matr_int_rand(a,n,m);
    cout<<"Matrix:"<<endl<<endl;
    matr_out(a,n,m);
    max_even_in_columns(a,c,n,m);
    int max_e=Max(c,m);
    cout<<"Columns numbers:"<<endl;
    for(j=0;j<m;j++)
    {
        if(c[j]==max_e)
            cout<<j+1<<" ";
    }
    cout<<endl;
    matr_free(a,n);
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
