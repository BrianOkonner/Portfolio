#include <stdio.h>
#include <stdlib.h>
//#include <iostream.h>
#include <stdio.h>

int Intlen(int x)
{int i;
	//for (int i=0; x!=0; i++, x>>=1);
_asm
{   xor eax,eax
loop1:cmp x,0
    je  end
	inc eax
	shr x,1
	jmp loop1
end:mov i,eax
}
return i;
}

int what_is_1(int n)

{ int i,s;

//for (i=0,s=0; i < sizeof(int) * 8; i++)
  //   { if (n & 1) s++; n >>=1; }  
_asm
{   mov ecx,4*8
	mov s,0
	xor eax,eax
loop1:
	shr n,1
	jnc else_
	inc s
else_:	
	loop loop1
}
return s; 
}
int revers_bit(int n)
//переворачивание младших бит
{ int i;
	// ci++?????
_asm
{ 	xor ebx,ebx
  
  clc
loop1:
    xor eax,eax
	clc
	cmp n,0
    je  end
	shr n,1
	rcl eax,1
	shl ebx,1
	add ebx,eax
	
  	inc ecx
	jmp loop1
	
	sub ecx,32
	neg ecx
	shr eax,cl
end:	
	mov i,ebx
}
return i;
}
 void dump16с_с(int n)
//
{ int i; char s[17];
_asm
{	xor esi,esi
	mov ecx,8
 loop1:
    xor eax,eax
	mov eax,n
	and  eax,0f0000000h
	shr eax,28
	add al,30h
	mov  byte ptr s[esi],al
	inc esi 
	shl n,4
	loop loop1
end:	mov s[esi],0
		mov i,ebx
}
	printf("%s",s);
}

void main ()

{
	int  x=100;//0x11110000;
	int d,d10=10; 
   // d=Intlen(x);
	//d= what_is_1(x);
	//d=revers_bit( x);
	dump16с_с(x);

//printf("%d = %d\n",x,d); 
}