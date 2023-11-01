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
         q1.pop();
     }

     cout << endl;

     while(!q2.empty())
     {
         r.push(q2.front());
         q2.pop();
     }

     queue <int> rt=r;
     queue <int> s=r;
     queue <int> rez;

     int t = 0;
     rt.pop();
     while (!r.empty() && !rt.empty())
     {
         t = 0;
         while(!rt.empty() && t == 0)
         {
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
