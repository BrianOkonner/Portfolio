#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *x;
	char  h[200]="Hello";
//	x=(char*) malloc(100);
//	strcpy(x,h);
// --- ������������ ������ ������� malloc � strcpy
// ----����������� ��������� ��������� ����������(h) � ������ ����������� ���������� ������(x)
	_asm
	{	
		mov edx,100				; ������ ���������� ������
		push edx				; �������� �������� � ����
		call dword ptr malloc	; ����� malloc
		pop edx					; ������������ �����
		mov x,eax				; ����� ���������� ������ -> x

		lea edx, h				; ����� ��������� ���������� (�� �������� ds)
		push edx				
		mov edx,x				; ����� � ��������� ����, ������� �������� � x
		push edx
		call strcpy				; ����������� �� h � x
		pop edx					; ������������ �����
		pop edx

	}
	printf("%s\n",x);
	delete[]x;
	return 0;
}