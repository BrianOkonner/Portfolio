/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: A4.	Зaдана матрица A=(aij) ,  i=1..n, j=1..m, (n,m<=100).
Упорядочить элементы верхнего левого треугольника  матрицы включая диагональ,  по возрастанию.

Тесты:
Условие         Полученый вывод
n=3;m=3         Initial matrix:

                1   9   1
                5   7   0
                1   9   9

                New matrix:

                1   1   1
                5   7   0
                9   9   9

                Vremya vipolneniya: 0.015


n=3; m=5        Initial matrix:

                7   5   5   6   4
                9   0   8   2   8
                1   9   6   2   1

                New matrix:

                0   1   5   6   4
                5   7   8   2   8
                9   9   6   2   1

                Vremya vipolneniya: 0.031

*/

#include "functions.cpp"


int main(void)
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    in.open("input_a4.txt");
    int n,m,i,j,min_nm,t=0,p=0,f,tmp;
    in>>n>>m;
    n >= m ? min_nm=m : min_nm=n;
    int **a;
    a=new int*[n];
    for(i=0;i<n;i++)
        a[i]=new int[m];
    matr_int_rand(a,n,m);
    cout<<"Initial matrix:"<<endl<<endl;
    matr_out(a,n,m);
    int *c;
    t=min_nm*(min_nm+1)/2;
    c=new int[t];
    for(i=0;i<min_nm;i++)
        for(j=0;j<min_nm-i;j++)
            c[p++]=a[i][j];

    for(i=0;i<p-1;i++)
    {
        f=0;
        for(j=0;j<p-i-1;j++)
            if(c[j]>c[j+1])
            {
                tmp=c[j];
                c[j]=c[j+1];
                c[j+1]=tmp;
                f=1;
            }
        if(f==0)
            break;
    }

    i=0;t=0;
    while(t<p)
    {
        for(j=0;j<min_nm-i;j++)
            a[i][j]=c[t++];
        i++;
    }

    cout<<"New matrix:"<<endl<<endl;
    matr_out(a,n,m);

    for(i=0;i<n;i++)
        delete[] a[i];
    delete[] a;
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
