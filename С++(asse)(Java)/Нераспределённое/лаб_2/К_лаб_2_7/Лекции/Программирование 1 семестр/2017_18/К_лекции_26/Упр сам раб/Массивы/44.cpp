//����� � ���-�� ����
#include <iostream.h>
void main()
{
   int D10=10; 
 
    int  sum,n;
    int count; 


cout<<"n=";
cin>>n;
//����� � ���-�� ����
_asm
{
        mov eax,n
        xor ecx,ecx       //�����
        xor ebx,ebx       //���-��
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
