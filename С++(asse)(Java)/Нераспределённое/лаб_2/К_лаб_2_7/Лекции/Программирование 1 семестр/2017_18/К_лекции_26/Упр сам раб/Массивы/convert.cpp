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
 //  {���������� ������ �����}
nn1:    shl eax,1
   rcl edx,1
   inc ebx
   jnc nn1
//{�������� ������ �� ���� �����}
    mov ecx,12
nn2:    shr edx,1
    rcr eax,1
    loop nn2
//{ �������������� �� ���� ����� � ��������}
    mov esi,64
    sub esi,ebx
    add esi,03ffh
    mov cl,20  //{�������������� � 2-� ������}
    shl esi,cl
//   ����� � ����. ������  DX:AX
 //  � AX ��� ���� ������� ����� ��������
 // � DX ������� ��������������}
    or  edx, esi
//kon:
  mov dword ptr [edi],eax		// ������� ����� 8-��������� ����������
  mov dword ptr [edi+4],edx		// ������� ����� 8-��������� ����������
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
