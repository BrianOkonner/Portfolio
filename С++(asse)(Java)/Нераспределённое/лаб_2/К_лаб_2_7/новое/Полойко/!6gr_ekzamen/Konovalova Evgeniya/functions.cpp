#include <iostream>
#include <functionsnames.h>
using namespace std;
int comp(const void *x,const void *y)
{
	return (*(int*)x-*(int*)y);
}
int NOD(int a,int b)
{
	if(a==0)
		return b;
	if(b==0)
		return a;
	if(a>b)
		return NOD(a%b,b);
	else
		return NOD(a,b%a);
}
void prov(int **matr,int q ,int x)
{	
	for (int i=1;i<x;i++)
	{
		for(int j=1;j<x-i;j++)
		{
			int a=vsprost(i,j);
			int b=vsprost(i,x-i-j);
			int c=vsprost(j,x-i-j);
			int t=NOD(i,j);
			int d=vsprost(t,x-i-j);
			if (a!=1&&b!=1&&c!=1&&d==1)
			{
				matr[q][1]=i;
				matr[q][2]=j;
				matr[q][3]=x-i-j;
				return;
			}
		}
	}
	matr[q][1]=0;
	matr[q][2]=0;
	matr[q][3]=0;
	return;	
}
/*int Node(int x,int y,int z)
{
	int p=NOD(x,y);
	int t=NOD(z,p);
	return t;
}*/
/*int nod(int a,int b)
{
	int d=1;
	_asm
	{  
		mov eax,a
		mov	ebx,b
		mov edi,1
cycl:
		test eax,1
		jz even1
r1:
		test ebx,1
		jz even2
		cmp eax,ebx
		jl leatest
		jg greatest
		jmp _equal
even1:
		shr eax,1
		test ebx,1
		jz evenboth
		jmp cycl
evenboth:
		shr ebx,1
		shl edi,1
		jmp cycl
even2: 
		shr ebx,1
		jmp cycl

leatest:
		sub ebx,eax 
		jmp r1
greatest:
		sub eax,ebx
		jmp cycl
_equal:
		imul edi,eax
		mov d,edi
	}
	return d;
}*/

