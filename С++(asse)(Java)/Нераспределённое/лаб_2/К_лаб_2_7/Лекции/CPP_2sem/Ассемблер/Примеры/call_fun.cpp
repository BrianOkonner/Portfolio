#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *x;
	char  h[200]="Hello";
//	x=(char*) malloc(100);
//	strcpy(x,h);
// --- демонстрация вызова функций malloc и strcpy
// ----особенности адресации локальных переменных(h) и адреса динамически выделенной памяти(x)
	_asm
	{	
		mov edx,100				; размер выделенной памяти
		push edx				; загоняем параметр в стек
		call dword ptr malloc	; вызов malloc
		pop edx					; освобождение стека
		mov x,eax				; адрес выделенной памяти -> x

		lea edx, h				; адрес локальной переменной (по сегменту ds)
		push edx				
		mov edx,x				; адрес в системной куче, который хранится в x
		push edx
		call strcpy				; копирование из h в x
		pop edx					; освобождение стека
		pop edx

	}
	printf("%s\n",x);
	delete[]x;
	return 0;
}