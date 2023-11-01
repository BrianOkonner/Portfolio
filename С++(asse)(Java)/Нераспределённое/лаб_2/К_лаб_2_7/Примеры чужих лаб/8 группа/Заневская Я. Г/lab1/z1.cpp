Заневская Яна 8 группа постфикснкая запись




#include <iostream>
#include <fstream>
#include <stack>
#include <clocale>

using namespace std;

void main()
{setlocale(LC_ALL,"RUS");
	int i=0,k=0;
 char a[100],b[100]="",c='a';
 stack <char> s;
 ifstream fin("input.txt");
 fin.getline(a,100);
 s.push(c);
 while(i!=strlen(a))
 {if(isdigit(a[i]))
 {b[k]=a[i];
 k++;}
 else 
 if(a[i]=='(')
 s.push(a[i]);
 else 
	 if(a[i]=='+' || a[i]=='-')
{
 while(s.top()=='+'  || s.top()=='-' || s.top()=='*' || s.top()=='/' )
			 {b[k]=s.top();
              s.pop();
              k++;
             }
 if( s.top()=='(' || s.top()==c)
	 s.push(a[i]);}
 
	 
	 
	 else
	 if(a[i]=='*' || a[i]=='/')
	 {
	  while(s.top()=='*'  || s.top()=='/')
	 {
		 b[k]=s.top();
	     k++;
		 s.pop();
	 }
	 if(s.top()=='+'  || s.top()=='-' || s.top()=='(' || s.top()==c)
	 s.push(a[i]);
	 }
 
	 
	 
	 else
	 if(a[i]==')')
	 {
	 while(s.top()=='+'  || s.top()=='-' || s.top()=='*' || s.top()=='/' )
	 {b[k]=s.top();
	 k++;
	 s.pop();
	 }
	 if(s.top()=='(')
	 s.pop();
	 }

	 
	 




  
 
 
 i++;}
 ofstream fout("output.txt");
 fout<<b;
 



system ("pause");
}