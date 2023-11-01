//Саковец 5 группа
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

struct spisok{
char s[80];
spisok* next;
};

void main()
{ifstream in;
ofstream out;
out.open("result1.txt");

char m[1000][80];
int n=0,nomer;
char sym;
in.open("input.txt");
int sch=0,u=0;
spisok* head,*prev,*current;

//char hlpstr[80];
//in.getline(hlpstr,80);

char *str1=new char[80];
while(in.getline(str1,80))//разбиваем на лексемы
{
char *pdstrk=new char[7];
strcpy(pdstrk," -,.;:!");
char *str2=new char[80];
str2=strtok(str1,pdstrk);
	while (str2!=NULL )
	{
	/*for(int i=0;i<strlen(str2);i++)
	{
	m[n][i]=str2[i];
	}
	n++;	*/

k:	for(int i=0;i<strlen(str2);i++)
		{sch=1;nomer=i;u=i;
p:	if(str2[i]==str2[i+1])
			{sch++;;
			
			sym=str2[i];
			i++;
			goto p;
			out<<nomer+1<<" "<<str2<<" "<<sym<<" "<<sch<<" "<<u<<endl;}else

			{sym=str2[i];
				
				//out<<nomer+1<<" "<<str2<<" "<<sym<<" "<<sch<<" "<<u+1<<endl;
				}
			

		}
out<<nomer+1<<" "<<str2<<" "<<sym<<" "<<sch<<" "<<u+1<<endl;
	cout<<str2<<endl;
	str2=strtok(NULL,pdstrk); 
	}
}cout<<sch;






}