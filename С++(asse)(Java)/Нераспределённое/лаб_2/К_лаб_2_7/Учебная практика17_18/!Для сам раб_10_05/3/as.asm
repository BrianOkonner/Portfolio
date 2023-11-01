.486
.model flat
;.data
; d10 dw 10
;.stack 20h
.code

Public _Calc
_Calc proc
		push ebp
		mov ebp,esp
		
		xor ecx, ecx
		push    edi
		xor eax, eax
		cld
		dec ecx
		mov edi,[ebp+8]
		repne   scasb
		not ecx
		pop edi
		lea eax, [ecx - 1]
		
		//Умножение

		mov esi,[ebp+12]
		mul edx
		ret 
_Calc endp
end