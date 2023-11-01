#include <stdio.h>
//using namespace std;
//Функция вывода числа  

void  _cdecl print(int a)
{
	printf(" %d=",a);
 }

//Функция разности чисел  
 int  _cdecl sub1(int a,int b)
{  int c=a-b; 
	return  c;}

//Функция разности чисел  
 int  sub11(int a,int b)
{  int c;
    c=a-b; 
	return  c;}

//	Функция разности чисел  
 void _stdcall sub2(int a,int b, int *x)
{   *x= a-b;  }
 
//Функция разности чисел  
 void _fastcall sub3(int a,int b)
 {      int c;
	   c= a-b;
 } 
 
 int __pascal sub4(int a,int b)
 {      int c;
	   c= a-b;
	   return c;
 } 

void main()
{
	int a,b,c;
	//scanf("%d%d",&a,&b);
	a=10;
	b=7;
	c=sub1(a,b);
_asm
{  push b	
   push a	
   call sub1	
   pop edx
   pop edx
   mov c,eax
   push eax
   call print
}


c=	sub1(a,b); 
printf("%d\n",c); c=0;

_asm
{  lea eax,c   // &c
   push  eax
   push b	
   push a	
   call sub2
   push eax
    call print
   pop edx
} 
sub2(a,b,&c);	
printf("%d\n",c); c=0;

_asm
{
   mov edx,b	
   mov ecx,a	
   call sub3	
   push eax
    call print
   pop edx
}
	printf("%d\n",c); c=0;
		sub3(a,b);
		printf("%d\n",c); 


		
}


