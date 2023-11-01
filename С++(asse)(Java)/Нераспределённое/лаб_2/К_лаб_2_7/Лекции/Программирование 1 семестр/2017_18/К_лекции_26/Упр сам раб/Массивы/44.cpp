//Сумма и кол-во цифр
#include <iostream.h>
void main()
{
   int D10=10; 
 
    int  sum,n;
    int count; 


cout<<"n=";
cin>>n;
//Сумма и кол-во цифр
_asm
{
        mov eax,n
        xor ecx,ecx       //сумма
        xor ebx,ebx       //кол-во
m21:    cmp eax,0
        je m22
        xor   edx,edx
        div  D10
        add ecx,edx
        inc  ebx
        jmp  m21
m22:    mov count,ebx
        mov sum, ecx
};
//sum:=sum+count;
cout<<"sum="<<sum<<" count="<<count;
}
