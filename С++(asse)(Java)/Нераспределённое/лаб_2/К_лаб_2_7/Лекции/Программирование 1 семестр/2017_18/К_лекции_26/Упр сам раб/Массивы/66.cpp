//	���������� �������� �� ��������  ����������� ����� �������.

#include <iostream.h>

int Prost( int x)
//{������� ���������� ������� x ��� ���������}
{ int r,y;                    //  1 ���� �������, 0 ���� ���������}
   y= x / 2;
_asm
{
   mov r,1
   mov eax,x      //x->eax
   xor edx,edx    //�������� edx
   cmp eax,1      //�������� eax c 1
   je _exit       //���� ea�=1 �� ������� ��  _exit
   mov ecx,2      //����� ecx:=2

   _while:
       cmp ecx,y   // �������� ecx c y
       jg _exit1   //���� ecx>y �� ������� �� _exit1
       xor edx,edx //�������� edx
       mov eax,x   //x->eax
       div ecx     //����� edx:eax �� ecx
       cmp edx,0   //���������� edx c 0
       je _exit    //���� edx=0 �� ������� �� _exit
       inc ecx     //ecx:=ecx+1
       jmp _while  //������� �� @while
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
