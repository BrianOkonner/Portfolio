/*Русакова Дарья 5 группа*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

void main()
{
int end;
ifstream in;
in.open("input.txt");
ofstream out;
out.open("Result1.txt");
setlocale( LC_ALL, ".1251" );
cout<<"Выделенные слова"<<endl;
	
    char* str;
	str= new char[100];
	
	int s=0;
		
	while(in.getline(str,100))
	{
		char *p;
		p = strtok(str, " -.;,:!");
	while (p)
	{
		cout<<p<<endl;
		out<<p<<endl;
		s++;
		p = strtok(NULL," -;,:.!");
	}
	
	}
in.close();
out.close();


  
int a[100];//нахождение числа,которое чаще всего встречается в массиве
int cifz;
int n;
cout<<"Введите кол-во чисел массива"<<endl;
cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
int mcount=0;
for(int i=0; i<n; i++)
{
	int count=0;
	for(int j=0; j<n; j++)
		if (a[i]==a[j]&&i!=j)
			count++;
	if(mcount<count)
	{
		mcount=count;
		cifz=a[i];
		
	}
}
cout<<"Число,встречающееся чаще всего"<<endl;	
cout<<cifz<<" ";





ofstream out3;
out3.open("output3.txt",ios::app);
out3<<" Номер слова"<<"   "<<"Слово"<<endl;
for(int i=1;i<=s;i++)
out3<<i<<endl;

out3.close();


cin>>end;

}














;