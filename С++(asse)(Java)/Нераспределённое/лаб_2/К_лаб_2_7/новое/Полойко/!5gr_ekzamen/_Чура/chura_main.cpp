/*Чура, 5 группа*/

#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

void main()
{ 
	  char **mas=new char*[40];
   for(int i=0; i<40; i++)
	  * mas=new char[40];

	char seps[]   = " -,.;:!";
	char *a=new char[80];
ofstream out("output.txt");
ifstream in("input.txt");
	char *take;
 while(in.getline(a,80))
 {
   take = strtok( a, seps ); 
  int i=0;

   while( take != NULL )
   {
	  i++;
     out<<take<<endl;
      take = strtok( NULL, seps ); 

   }
 }
   out.close();
   in.close();
 


   ofstream off("Result1.txt");
	   off<<"Номер слова  "<<"Слово         "<<"символ  "<<"номер "<<endl;
   ifstream inp("output.txt");
int i=1,j=0;
char b;
int mas1[10];
while(inp.getline(a,80))
{

int m=strlen(a);
char *mt=new char[m];
int c=0;
int k=0;
char simv;
_asm
{

	
	mov esi,a
		mov ecx,m
m1:
	mov al,[esi]
	inc esi
	cmp al, [esi]
		je n1
		jne n2
n1:
mov al,[esi]
cmp al,0
je b3
jne b1
b1:mov bl,[esi]
inc esi

cmp al, [esi]
je n1
jne n3
n3:

mov c,ecx
mov simv,bl


jmp n2
n2:loop m1
b3:
}
	c=m-c+1;
cout<<c<<"  "<<simv<<endl;
off<<i<<"             "<<a<<"        "<<simv<<"   "<<c<<endl;
i++;
}
	

   inp.close();
   off.close();

}

