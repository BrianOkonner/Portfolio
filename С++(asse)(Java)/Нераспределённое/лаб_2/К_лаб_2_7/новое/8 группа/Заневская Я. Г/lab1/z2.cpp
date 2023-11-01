Заневская ЯНа 8 группа очередь



#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
int prost(int a)
{
int i=2,k=0;
if(a>1)
{while(i!=a)
	{if(a%i==0)
	k++;
i++;}}

if(k>0)
	return 0;
else 
	return 1;

}


int palindrom(int a)
{int i=0,b,c,k=0,n=0;
b=a;
while(b!=0)
{c=b%10;
n=n*10+c;
b=b/10;}
if(a==n)
return 1;
else
return 0;}


void main()
{int a;
queue <int> s1;
queue <int> s2;
queue <int> s3;


ifstream fin("input.txt");
while(!fin.eof())
{fin>>a;
if(prost(a)==1)
	s1.push(a);
else
if(palindrom(a)==1)
	s2.push(a);

}

while(!s1.empty())
	{s3.push(s1.front());
     s1.pop();}
while(!s2.empty())
	{s3.push(s2.front());
     s2.pop();}
ofstream fout("output.txt");
while(!s3.empty())
	{fout<<s3.front()<<" ";
s3.pop();}


system ("pause");
}