/*
Казанцев Павел Сергеевич
1 курс
группа ПМ-8

Условие: 8.	Преобразовать последовательность A=(ai),i=1..n, n<=100,
расположив сначала все наибольшие, затем все остальные,
сохранив их порядок, не используя дополнительную память.

Алгоритм:
Находим максимальный элемент.Затем все элементы равные максимальному сдвигаем в начало массива.

Тесты:
Условие         Полученый вывод
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
    mas_int_rand(a,n); // Заполнение массива
    mas_out(a,n);   // Вывод массива
    cout<<endl<<"New massive:"<<endl;
    max_a=Max(a,n); // Нахождение максимально
    Max_to_start(a,n,max_a);    // Сдвиг максимального к началу массива
    mas_out(a,n);   // Вывод нового массива
    free(a);
    clk=clock();
    cout<<"Vremya vipolneniya: "<<clk/1000.0<<endl;
    return 0;
}
