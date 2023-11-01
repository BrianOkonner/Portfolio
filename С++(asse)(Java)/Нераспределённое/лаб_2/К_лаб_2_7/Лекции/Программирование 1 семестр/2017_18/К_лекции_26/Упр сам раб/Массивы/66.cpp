//	Определить является ли заданное  натуральное число простым.

#include <iostream.h>

int Prost( int x)
//{Функция определяет простое x или составное}
{ int r,y;                    //  1 если простое, 0 если составное}
   y= x / 2;
_asm
{
   mov r,1
   mov eax,x      //x->eax
   xor edx,edx    //очистить edx
   cmp eax,1      //сравнить eax c 1
   je _exit       //если eaх=1 то перейти на  _exit
   mov ecx,2      //иначе ecx:=2

   _while:
       cmp ecx,y   // сравнить ecx c y
       jg _exit1   //если ecx>y то перейти на _exit1
       xor edx,edx //очистить edx
       mov eax,x   //x->eax
       div ecx     //делим edx:eax на ecx
       cmp edx,0   //сравниваем edx c 0
       je _exit    //если edx=0 то перейти на _exit
       inc ecx     //ecx:=ecx+1
       jmp _while  //перейти на @while
     _exit:
       mov r,0   //result:=0
     _exit1:
;
};
return(r);
}
void main()
{
int k,a;
cout<<"a=";
cin>>a;
  k=Prost(a);
  if (k>0) 
		cout<<"Prostoe"; else cout<<"Sostavnoe";
}
