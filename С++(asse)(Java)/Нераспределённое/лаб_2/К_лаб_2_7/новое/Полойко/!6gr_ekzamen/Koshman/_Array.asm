.486
.model flat
.code
Public _Array
_Array proc
		push 	ebp
		mov 	ebp, esp
		mov 	eax, [ebp+8]
		mov	ecx, 0
while1: 	cmp	eax, 0
		je 	endw
		cdq
		div	c10
		mov	t, eax
		mov	eax, 1
		mov	ebx, edx
		mul	ebx
		mul	ebx
		mul	ebx
		add	ecx, eax
		mov	eax, t
		jmp	while1
endw:		mov	eax, ecx
		pop ebp
ret
_Array endp
end