#include<iostream>
#include<fstream>
#include"LIST.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, ".1251");
    int n,m;
    List l;
 cin >> n >> m;
for(int i=1; i<=n; i++)
    l.push_back(i);
while(n!=1)
{
    for(int i=1; i<m; i++)
    {
        l.push_back(l.front());
        l.pop_front();
    }
    l.pop_front();
    n--;
}
cout << "vyzil " << l.front();
system("pause");
}
