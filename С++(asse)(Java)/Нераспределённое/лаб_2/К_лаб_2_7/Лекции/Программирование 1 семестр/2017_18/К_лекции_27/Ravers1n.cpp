#include <stdio.h>
#include <stdlib.h>
//#include <iostream.h>
#include <stdio.h>
void RevZ()
// меняем 1 и последнюю цифры числа
{ 
	int d1= 100000000; 
	int  a=123456789,d; 
    int z=a%d1/10;
    int z1=a/d1;
    int z2=a%10;
    a=(z*10)+z1+z2*d1;
	printf("fggg%d",a);
}
void AsmIRev()
// меняем 1 и последнюю цифры числа
{	int  a=123456789,d,d10=10; 
_asm
{
mov  ecx, 10
imul ecx,ecx
imul ecx,ecx
imul ecx,ecx
mov eax, a    
cdq
div ecx   // eax=1 edx=23456789
mov d, eax   // z1=1

mov eax, edx   // eax=23456789
cdq
div d10         // edx  =9  eax=2345678
imul edx,ecx    // edx=900000000

imul eax,10      // eax =  23456780
add d,eax      //  d =  23456781

add d, edx   // eax=923456781

} 
printf("%d = %d\n",a,d); 
}

void AsmRev()
// меняем 1 и последнюю цифры числа
{	const  int d10=10;
    int  a=123456789,z1,z2,d; 
_asm
{
mov eax, d10
mul eax
mul eax
mul eax
mov ecx, eax   //10 8
mov eax, a    
cdq
idiv ecx  
mov z1, eax   // z1=1
mov d, edx   // d=  23456789
mov eax, d   // eax=23456789
cdq
div d10
mov z2,edx   // z2=9
mov d, eax   // d =  2345678
mul d10      // eax =  23456780
add z1,eax   // z1 =  23456781

mov eax, z2   // eax=9
mul ecx       // eax=900000000
add eax, z1   // eax=923456781
mov d,eax 
}
printf("%d = %d\n",a,d); 
}

void AsmCdq()
{ 
_asm
{ 
mov eax,-100
cdq
mov ebx,15
idiv  ebx  // EAX =  FFFA
   // EDX =  FFF6
}
}

void AsmCwd()
{ 
_asm
{ 
mov ax,-100
cwd
mov bx,15
idiv  bx
}
}

void AsmXchg()
{
 int f;
 _asm
{ 
mov eax , 7D7h 
mov ecx, 2007 
xchg eax, ecx 
mov edx , 100 
mov f, 978h 
xchg edx, f 
}
}

void asm1()
{
_asm
{ 
mov al,100
cbw
mov bl,15
div  bl
}
}
void ma1()
{int f;
	_asm
	{ 
mov eax , 7D7h 
mov ecx, 2007 
xchg eax, ecx 
mov edx , 100 
mov f, 978h 
xchg edx, f 
//в результате: 
//eax = 978h 
//ecx = 237h
}
}
void main()
{
AsmIRev();
AsmCdq();
AsmCwd();
ma1();	
asm1();

	int fl;
_asm
{   mov ax,-1
	mov bx,40000
	cmp ax,bx
	jz aeqb
    jg amax
	jl bmax
	aeqb: mov fl,0
	jmp ecmp
	amax: mov fl,1
	jmp ecmp
	bmax: mov fl,-1
ecmp:

}
printf("%d\n",fl);

}
 
//printf("input a b ");
//scanf("%d%d",&a,&b);

    
 