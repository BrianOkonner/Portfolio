
#include <iostream.h>
void main()
{
    int ed=1, two=2;

    int  m;
    int  sumz;
   
// C���������� �����
cout<<"m=";
cin>>m;
_asm
{
	   mov eax,m
     mul ed
     div two
     mov ecx,eax
     xor esi,esi
m31:
     inc esi
     mov eax, m
     mov edx, 0
     div esi
     cmp edx, 0
     jne m32       // ���� <>
     add sumz, esi
m32:
     loop m31    // ������� �����
};
if (sumz=m) 
cout<<"Sover "<<sumz<<endl;
}
