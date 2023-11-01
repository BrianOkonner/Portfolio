#include <windows.h>
#include "sort.h"

void sort_asm(str* b, int n){
	_asm{   
		mov ebx,b //������� ����� �������
		mov ecx,n //������� �����������
		sub ecx,1 
	loop1:  push ecx //������ 1 �����
		mov esi,[ebx]//�������� 1
		mov eax,[ebx+4]//code 1
		mov edx,0//������ �������������
	lab2: push ecx//������ 2 �����
		mov edi,[ebx+edx+8]//�������� 2
		//����� strcmp
		pushad
		push edi
		push esi
		call strcmp
		add sp,8
		//��������� ��������
		cmp eax,0
		popad
		jmp lab_e//���� �����-���������� ����
    
		//���� ������-������ �������
	lab_g:  mov [ebx+edx],edi
		mov [ebx+edx+8],esi
		mov ecx,[ebx+edx+12]//code 2
		mov [ebx+edx+4],ecx
		mov [ebx+edx+12],eax
		add edx,8
		jmp lab3
		//���� ������-������ ������������
	lab_l:  mov esi,edi
		mov eax,[ebx+edx+12]
		add edx,8
		jmp lab3
	lab_e:  //��������� code(���� �������� �����)
		mov ecx,[ebx+edx+12]//code 2
		cmp eax,ecx
		jnl lab_l//���� ������ ��� �����-������ ������������
		jl lab_g//���� ������-������ �������
	lab3: pop ecx
		loop lab2//2 �������
		pop ecx
		loop loop1//1 �������
	}
}
