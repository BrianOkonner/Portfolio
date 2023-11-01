/*
Каунов Кирилл
1 курс
8 группа

Условие: 2.1	Задан текстовый файл Input.txt, в котором есть некоторые числа, каждое число в отдельной строке.
Создать  две очереди,  в первой – простые числа, во второй _ палиндромы. Построить новую очередь, включив в нее по одному  разу элементы, 
которые входят хотя бы в одну из очередей Queue1 или Queue2. Результат записать в текстовый  файл.
*/

#include <iostream>
#include <fstream>
#include <queue>
#include "funkh.h"

 using namespace std;


 int main()
 {
     queue <int> q1;
     queue <int> q2;

     ifstream fin;
     fin.open("input.txt");


     while (!fin.eof())
     {
         int a;
         fin >> a;
         if (Prost(a)) q1.push(a);
         if (Palind(a)) q2.push(a);
     }

     queue <int> r;

     while(!q1.empty())
     {
         r.push(q1.front());
         cout << q1.front() << " ";
         q1.pop();
     }

     cout << endl;

     while(!q2.empty())
     {
         r.push(q2.front());
         cout << q2.front() << " ";
         q2.pop();
     }

     cout << endl;

     queue <int> rt=r;
     queue <int> s=r;
     queue <int> rez;

     int t = 0;
     rt.pop();
     while (!r.empty())
     {
         t = 0;
         while(!rt.empty() && t == 0)
         {
             cout << r.front() << "    " << rt.front() << endl;
             if (r.front() == rt.front())
             {
                 t = 1;
             }
             rt.pop();
         }
         if (t == 0) rez.push(r.front());
         r.pop();
         rt = r;
         rt.pop();
     }

     while (!rez.empty())
     {
         cout << endl << rez.front();
         rez.pop();
     }
}

    {
        cout << Pr1.front() << " ";
        Pr1.pop();
    }

    Pr1 = Pr;

    cout << endl;
    cout << "Палиндромы: \n";

    while (!Pal1.empty())
    {
        cout << Pal1.front() << " ";
        Pal1.pop();
    }

    Pal1 = Pal;

    cout << endl;

    while (!Pr1.empty())
    {
        int sr = Pal1.front();
        Pal1.pop();

        if (sr == Pr1.front())
            {
                res.push(sr);
                Pr1.pop();
                Pal1 = Pal;
                cout << sr << " ";
            }

        if (Pal1.empty())
        {
            Pr1.pop();
            Pal1 = Pal;
        }
    }

    cout << endl;
    cout << "Полученная очередь: \n";
    while (!res.empty())
    {
        cout << res.front() << " ";
        res.pop();
    }
}
