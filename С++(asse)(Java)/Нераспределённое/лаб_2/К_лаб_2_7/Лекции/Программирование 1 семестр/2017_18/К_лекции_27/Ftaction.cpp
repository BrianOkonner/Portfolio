#include <stdio.h>
#include <stdlib.h>
void SFraction (int a,int b,int c,int d,int *e,int*f)
{    int fr,gr;
	        //e:=a*d+c*b;
        //f:=b*d;
_asm
{
        mov eax, a
        mul   d
        mov ecx,eax        //a*d

        mov eax, c
        mul   b           //c*b;
        add ecx,eax    //a*d+c*b -> ecx;

        mov eax, b
        mul   d        //b*d -> eax;
	    
		mov esi, e  
		mov [esi],ecx
        
		mov esi, f  
		mov [esi],eax//           
    	}
}

int Nod (int g,int h)
{        do 
		{//  вычисление НОД
          if (g > h)
             g = g % h;
          else
             h = h % g;
		}
        while  (g*h != 0);
		return(g+h);
}
int AsmNod (int f,int e)
{ int r;
_asm
{
        mov ecx, e           
        mov ebx, f
  repeat:
  if_:
        cmp ecx, ebx
        jng else_
        mov eax, ecx
        cdq
        idiv ebx
        mov ecx, edx
        jmp end_else
  else_:
        mov eax, ebx
        cdq
        idiv ecx
        mov ebx, edx
  end_else:
        mov eax, ecx
        imul ebx
  until:
        test eax,eax
        jnz repeat
		mov r,ebx
		add r,ecx
}
return r;
}

void main()
{   int a,b,c,d;
        int e,f,g,h;
        scanf("%d%d",&a,&b);		// первая дробь a/b
        scanf("%d%d",&c,&d);		// вторая дробь a/b
       e=a*d+c*b;
     f=b*d;
//SFraction (a,b,c,d,&e,&f);
        int nod=AsmNod(e,f);
//		
//		e=e /nod;
//		f=f /nod;
_asm
{
        mov eax, e
        cdq
        idiv nod
        mov e, eax

        mov eax, f
        cdq
        idiv nod
        mov f, eax
}
printf ("%d %d ", e, f);
 int c1,i,n,m;
   scanf("%d%d",&n,&m);

_asm
{
   mov ecx,m		//{если m < n/2 то m:=n-m}
   mov ebx,2
if_:
   mov eax,n
   mov edx,0
   div ebx		//{ деление 2}
   cmp ecx,eax     
   jng endif_      //если m < n/2
   sub ecx,n       //m=n-m
   neg ecx
endif_:
   mov eax,1		//{C(n,0)=1}
   xor edx,edx
   mov ebx,1
for_:				//{C(n,k)=С(n,k-1)*(n-k+1)/k}
   mul n
   div ebx
   dec n
   inc ebx
   loop for_
   mov c,eax
}
printf("%d",c);
int *x,y=10,z=3;
int d1,d2,d3,d4;
 x=&z;
_asm
{
 mov  esi,x
	 mov edx,0
	 mov eax,y

	// mov edx,0
	div  [esi+2]
     mov d1,eax
     mov d2,edx
    

}

}







