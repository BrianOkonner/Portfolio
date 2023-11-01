#include "MyFunc.h"

using namespace std;

int strlen1(char* a)
{
	int len = 0;
	_asm
	{
		mov esi, a
		mov eax, 0
		cmp [esi], '\0'
		je end_
		start_ :
			 add esi, 1
			 add eax, 1
			 cmp [esi], '\0'
			 jne start_
			 mov len, eax

		end_:
	}
	return len;
}

void strcpy1(char *a, char *b)
{
	int len = strlen1(b);
	_asm
	{
		mov ecx, len
		inc ecx
		mov esi, b
		mov edi, a
		rep movsb
	}
}

void strcat1(char *a, char *b)
{
    int len = strlen1(b);
    int lena = strlen1(a);
    _asm
    {
        mov ecx, len
        inc ecx
        mov esi, b
        mov edi, a
        add edi, lena
        rep movsb
    }
}