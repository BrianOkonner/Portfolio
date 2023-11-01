/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: А5.	Для заданной матрицы А размерности N*M построить матрицу В такого же размера,
элементы которой обладают следующим свойством: элемент  В[i,j] равен максимальному из элементов матрицы А,
расположенных  левее и выше позиции (i,j), включая позицию (i,j). При этом считается, что позиция(1,1) - верхняя левая позиция матрицы.
Например:
5  8  9   8         5  8  9  9
6  7  10  7    =>   6  8  10 10
3  9  1   5         6  9  10 10

Тесты:

n=5, m=7

Initial matrix

    2    2    8    9    6    4    8
    3    8    5    6    3    3    5
    2    9    7    9    6    7    7
    3    5    0    5    6    9    4
    8    6    0    6    7    6    6

New matrix

    2    2    8    9    9    9    9
    3    8    8    9    9    9    9
    3    9    9    9    9    9    9
    3    9    9    9    9    9    9
    8    9    9    9    9    9    9

Vremya vipolneniya: 0.031
*/

#include "functions.cpp"


int main(void)
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    in.open("input_a5.txt");
    int n,i,j,m;
    in>>n>>m;
    int **a;
    int **b;
    matr_empty(a,n,m);
    matr_empty(b,n,m);
    matr_int_rand(a,n,m);
    cout<<"Initial matrix"<<endl<<endl;
    matr_out(a,n,m);
    b[0][0]=a[0][0];
    for(i=1;i<n;i++)
    {
        b[i][0]=max_2(b[i-1][0],a[i][0]);
    }
    for(j=1;j<m;j++)
    {
        b[0][j]=max_2(b[0][j-1],a[0][j]);
    }
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
            b[i][j]=max_3(a[i][j],b[i-1][j],b[i][j-1]);
    cout<<"New matrix"<<endl<<endl;
    matr_out(b,n,m);
    matr_free(a,n);
    matr_free(b,n);
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
