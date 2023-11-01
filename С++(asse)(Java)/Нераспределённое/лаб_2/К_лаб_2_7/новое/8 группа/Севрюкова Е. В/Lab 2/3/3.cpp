/*
8 группа, 1 курс
Севрюкова Л.

3. Задача Иосифа. Вокруг считающего стоит N человек, из которых выделен первый,
а  остальные  занумерованы  по  часовой стрелке числами от 2 до N. 
Считающий,  начиная с кого-то, ведет счет до M. Человек, на котором остановился счет, выходит из круга.
Счет продолжается со следующего человека и так до тех пор, пока не останется один человек. 
Определить номер оставшегося человека, если известно M и то, что счет начинался с первого человека. 
Результат записать в текстовый  файл.

тесты:


*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include "List.h"
using namespace std;

void main()
{
setlocale(LC_ALL,"rus");
ofstream out;
out.open("Output.txt");
int N,M;
cout<<"Кол-во человек = "; cin>>N;
cout<<"Число до которого ведется счет = "; cin>>M;

//создание списка
List  s;
for(int i=1; i<=N; i++)
s.push_back(i);

int x;
while(!s.empty())
{ 
	for(int i=1; i<M; i++)
	{
		x = s.front();
		s.push_back(x);
		s.pop_front();
	}
	s.pop_front();
}
if( M==1 ) x = N;

cout<<"\nНомер оставшегося человека = "<< x <<"\n\n";
out<<"Номер оставшегося человека = "<< x <<"\n\n";
out.close();
system ("pause");
}

