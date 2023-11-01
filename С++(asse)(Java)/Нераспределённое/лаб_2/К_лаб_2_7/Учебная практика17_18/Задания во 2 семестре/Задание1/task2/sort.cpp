#include <windows.h>
#include "sort.h"

void sort_asm(str* b, int n){
	_asm{   
		mov ebx,b //заносим адрес массива
		mov ecx,n //заносим размерность
		sub ecx,1 
	loop1:  push ecx //начало 1 цикла
		mov esi,[ebx]//название 1
		mov eax,[ebx+4]//code 1
		mov edx,0//индекс максимального
	lab2: push ecx//начало 2 цикла
		mov edi,[ebx+edx+8]//название 2
		//вызов strcmp
		pushad
		push edi
		push esi
		call strcmp
		add sp,8
		//сравнение названий
		cmp eax,0
		popad
		jmp lab_e//если равны-сравниваем коды
    
		//если больше-меняем местами
	lab_g:  mov [ebx+edx],edi
		mov [ebx+edx+8],esi
		mov ecx,[ebx+edx+12]//code 2
		mov [ebx+edx+4],ecx
		mov [ebx+edx+12],eax
		add edx,8
		jmp lab3
		//если меньше-меняем максимальный
	lab_l:  mov esi,edi
		mov eax,[ebx+edx+12]
		add edx,8
		jmp lab3
	lab_e:  //сравнение code(если названия равны)
		mov ecx,[ebx+edx+12]//code 2
		cmp eax,ecx
		jnl lab_l//если меньше или равно-меняем максимальный
		jl lab_g//если больше-меняем местами
	lab3: pop ecx
		loop lab2//2 счётчик
		pop ecx
		loop loop1//1 счётчик
	}
}
