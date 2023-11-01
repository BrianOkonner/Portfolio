/*
8 группа, 1 курс
Севрюкова Л.

1.	Использование (динамического) стека.
Задано выражение (инфиксная форма, например (5+45)*(55-5).... )содержащее числа (любого типа), 
знаки операций, круглые скобки.
Записать его в виде обратной польской записи (постфиксная форма) и вычислить его значение. 

тесты:

 Исходное выражение: 

(5+45)*(55-5)

 Постфиксная запись: 

5 45 + 55 5 - * 

 Результат:

2500



*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <stack>
using namespace std;


bool chislo(char* sl)
{
char *er;
strtol(sl,&er,0);
if(*er==0)
return true;
else
return false;
}



void main()
{
setlocale(LC_ALL,"rus");
ifstream in;
in.open("Input.txt");
if(!in.is_open())cout<<"File is not found";
cout<<" Исходное выражение: "<<"\n\n";
char str[100];
in>>str;
cout<<str<<endl;
in.close();

stack <char> s;

char *res = new char[strlen(str)];
res[0]='\0';

int j,n;
for(int i=0, j=0; i <= strlen(str); i++)
	if( str[i]>='0' && str[i]<='9' )
	{
		res[j]= str[i];
		j++;
	}
	else
	{
		if(res[j-1]!=' ')
		{res[j]=' '; j++;}

		if(s.empty()) s.push(str[i]);
		else

		switch(str[i])
		{
		case '(':
			
			s.push(str[i]); break;

		case ')':
			while(s.top()!='(')
			{
				res[j]=s.top();
				s.pop();
				j++;
				res[j]=' '; j++;
			}
			s.pop();
			break;


		case '+':
		case '-':
			while(!s.empty())
			{
			if( s.top() =='-' || s.top() =='*' || s.top() =='/'|| s.top() =='+' )
				{res[j]=s.top();  s.pop(); j++;
					res[j]=' '; j++;}

			else break;
			}

			s.push(str[i]);
			break;

		case '*':
		case '/':

			while( !s.empty())
			{
			if( s.top() == '*'||  s.top() == '/')
				{res[j]=s.top();  s.pop(); j++;
					res[j]=' '; j++;}
			else break;
			}

			s.push(str[i]);
			break;
		}
		n=j;
	}

	while(!s.empty())
{
	res[n]= s.top();  s.pop();
	n++;
	res[n]=' '; n++;
}

res[n]='\0';

cout<<"\n Постфиксная запись: \n";
cout<<"\n"<<res<<"\n\n";


stack <int> s2;
n=0;
char *er;
char *sl=strtok(res," ");

while(sl)
{
if(chislo(sl))
{
n=strtol(sl,&er,0);
s2.push(n);
}

else
{
	switch(sl[0])
		{

		case '+':
			
			n = s2.top(); s2.pop();
			n+= s2.top(); s2.pop();
			s2.push(n);

		break;
		case '-':
			n = s2.top()*(-1); s2.pop();
			n += s2.top(); s2.pop();
			s2.push(n);
		break;
		case '*':
			n = s2.top(); s2.pop();
			n *= s2.top(); s2.pop();
			s2.push(n);

		break;
		case '/':
			int c = s2.top(); s2.pop();
			n = s2.top()/c; s2.pop();
			s2.push(n);

		break;
		}

}

sl = strtok(0," ");
}

cout<<" Результат:\n\n";
while(!s2.empty())
{
	cout<<s2.top();
	s2.pop();
}
cout<<"\n\n";

system ("pause");
}

