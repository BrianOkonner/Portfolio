#include <iostream.h>
#include <math.h>
int a[100];
int n,p,f;   
//����� ��� �������  �������� ��������� ������������ �����.
  //��������� ���� � ������� �� ����� ������� �������� �����
  void prost(int n)
  //n-��� �����, � �������� �� ���� ������� ��������. ���������� �� ��������
  {  int k,t;
  _asm
	{
		mov eax,n
     mov ebx,a                           //�������� ����� ������ �������
     mov ecx,2                           //������ ��������� ������� ��������
     mov esi,0                           //������� ��� ��������� ��-�� �������
     //������� ������������� ����� while
     _for: //���� �������� ������, ��� �������, �� ������� �� �����
           cmp ecx,eax
           jg _end
           cdq
           push eax
           idiv ecx
           pop eax
           //���� ������� ��� ������� �� �������� = 0, �� ������� ��� � ������
           cmp edx,0
           je _add
           // ���� ������� <> 0, ����������� ������� � ���� � ������ �����
           inc ecx
           jmp _for
     //���������� � ������ ������� ���������
     _add: mov [ebx][esi*4],ecx
     //������� � ����� ��������, ������� �������� �������� ��������
     _del:  mov t,eax
            idiv ecx
            cmp edx,0
            je _del
            inc esi
            inc ecx
            mov eax,t
            jmp _for                   //������������ � ������ �����
     _end: mov f,esi                   //��������� ���-�� ��-�� � �������
	};
}
void main()
{
int a[100];
int n,p,f;   
cout<<"Enter the number, simple dividers:";
cin>>n;
p= n / 2;
  prost(n);
cout<<"Simple dividers of the number"<<n<<" are:";
      //������� �� ����� ��������
  for (int k=0;k<f;k++}
        cout<<a[k]<<' ';
} 
