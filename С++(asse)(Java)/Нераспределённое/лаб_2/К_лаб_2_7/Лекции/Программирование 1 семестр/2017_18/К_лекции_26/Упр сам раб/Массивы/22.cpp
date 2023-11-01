#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
void main()
{
// сортировка трех чисел 
 
    int  a,b,c;
  
cout<<"input a b c";
cin >>a>>b>>c;
_asm
{
    // сравниваем a  и b
     mov  eax,a
     mov  ebx,b
     sub  eax,ebx
     JLE  m1          //a<=b
     mov  eax,a
     mov  a,ebx
     mov  b,eax
  // сравниваем b  и c
m1:  mov  eax,b
     mov  ebx,c
     sub  eax,ebx
     JLE  m2          //a<=b
     mov  eax,b
     xor  eax,ebx
     xor  ebx,eax
     xor  eax,ebx
     mov  c,ebx
     mov  b,eax
     // сравниваем a  и b
m2:   mov  eax,a
     mov  ebx,b
     sub  eax,ebx
     JLE  m3          //a<=b
     mov  eax,a
     mov  a,ebx
     mov  b,eax
m3:
};
cout<< a<<' '<<b<<" "<<c<<endl;

}
