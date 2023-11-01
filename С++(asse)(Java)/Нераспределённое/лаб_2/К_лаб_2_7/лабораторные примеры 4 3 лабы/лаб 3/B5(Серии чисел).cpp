/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: 5.	Задана целочисленная последовательность A=(ai), i=1..n, n<=100.
Назовем серией группу подряд идущих одинаковых элементов,
а длиной серии — количество этих элементов (длина серии может быть равна 1).
Вывести массив, содержащий длины всех серий исходного массива.

Алгоритм:
Для каждого а[i] в b[i] записываем длину текущей серии.

Тесты:
Условие         Полученый вывод

Initial massive:
4 9 2 5 3 3 2 7 4 6 2 1 9 2 2
Massiv serii
1 1 1 1 1 2 1 1 1 1 1 1 1 1 2

*/

/*#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <math.h>*/
#include "functions.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL,".1251");
    unsigned int clk;
    ifstream in;
    //ofstream out;
    in.open("input.txt");
    //out.open("output.txt");
    int i,/*c=1,j=0,*/n;
    in>>n;
    cout<<"n = "<<n<<endl;
    int a[101],b[101];
    //srand(time(NULL));
    cout<<"Initial massive:"<<endl;;
    mas_int_rand(a,n);                                              //for(i=0;i<n;i++)
    mas_out(a,n);                                                   //{
                                                                    //a[i]=rand()%10;
                                                                    //out<<a[i]<<" ";
    cout<<endl<<"Massiv serii"<<endl;                               //}
    /*for(i=1;i<n;i++)
    {
        b[j++]=c;
        if(a[i]==a[i-1])
            c++;
        else
            c=1;
    }
    b[j++]=c;
    b[j]=0;*/
    serii(a,b,n);
    mas_out_not_0(b,n);//j=0;
    clk=clock();
    /*while(b[j]!=0 && j<n)
    {
        //if (b[j]>0)
        cout<<b[j]<<" ";
        j++;
    }*/


    //out.close();
    cout<<endl<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
