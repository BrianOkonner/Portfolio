/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: A2. Построить магический квадрат любого порядка,
использовать любой алгоритм.
Порядок n=2m+1, m=0,1,2...
Вправо-вверх, иначе вниз.
Тесты:

n=3

Magic Square:

    8    1    6
    3    5    7
    4    9    2

Vremya vipolneniya: 0.006

n=5

Magic Square:

   17   24    1    8   15
   23    5    7   14   16
    4    6   13   20   22
   10   12   19   21    3
   11   18   25    2    9

Vremya vipolneniya: 0.027

*/

#include "functions.cpp"


int main(void)
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    in.open("input_a2.txt");
    int n,i,j,c=1;
    in>>n;
    int **a;
    matr_empty(a,n,n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=0;
    i=0;j=(n-1)/2;
    while(c<=n*n)
    {
        a[i][j]=c++;
        if(i==0 || j==n-1){
            if(i==0){
                if(j==n-1)
                    i++;
                else
                {
                    j++;
                    i=n-1;
                    if(a[i][j]!=0)
                    {
                        j--;
                        i=1;
                    }
                }
            }
            else{
                i--;
                j=0;
                if(a[i][j]!=0)
                {
                    i=i+2;
                    j=n-1;
                }
            }
        }
        else
        {
            j++;
            i--;
            if(a[i][j]!=0)
                {
                    i=i+2;
                    j--;
                }
        }

    }
    cout<<"Magic Square:"<<endl<<endl;
    matr_out(a,n,n);
    matr_free(a,n);
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
