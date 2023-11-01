#include <stdio.h>
#include <string.h>
double conv( int x)
{	double y;
_asm
{
   lea edi,y
   xor ebx,ebx
   mov ecx,8
   mov eax,x
   cdq
 //  {количество незнач нулей}
nn1:    shl eax,1
   rcl edx,1
   inc ebx
   jnc nn1
//{мантиссу вправо на свое место}
    mov ecx,12
nn2:    shr edx,1
    rcr eax,1
    loop nn2
//{ характеристику на свое место в регистре}
    mov esi,64
    sub esi,ebx
    add esi,03ffh
    mov cl,20  //{характеристика в 2-х байтах}
    shl esi,cl
//   число с плав. точкой  DX:AX
 //  в AX уже есть младшая часть мантиссы
 // к DX добавим характеристику}
    or  edx, esi
//kon:
  mov dword ptr [edi],eax		// младшая часть 8-байтового результата
  mov dword ptr [edi+4],edx		// старшая часть 8-байтового результата
}
return y;
}

void main()
{
  int a;
   double b;
  a=2000000000;
  b=conv(a);

 printf("%d  %f\n",a,b); 

}
