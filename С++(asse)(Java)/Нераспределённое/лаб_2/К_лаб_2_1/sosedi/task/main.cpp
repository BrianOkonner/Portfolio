#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
#include <stack>
#include <vector>
#include <iostream>
using namespace std;
// Для простоты примера стек содержит целочисленные переменные

 
void main()
{ int a,b,c,count=0;
        stack<int> s;
 
        // Заполнение стека числами от 0 до 9
        for(int i = 0; i < 10; ++i)
		{  a=rand()%2;
                s.push(a);
		}

     a=s.top();
     s.pop();
     b=s.top();
     s.pop();
        // Для проверки выведем стек на экран
        while(!s.empty()) {
			c= s.top() ;
            s.pop();
			if (a==c) count++;
			a=b;
			b=c;

        }
 cout<<count;
       
}
