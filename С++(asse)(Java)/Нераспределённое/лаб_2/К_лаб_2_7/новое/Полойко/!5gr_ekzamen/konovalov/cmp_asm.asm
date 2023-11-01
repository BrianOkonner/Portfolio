.386
.model flat
.code
Public _cmp_asm
	_cmp_asm proc 
	
	mov eax,[esp+4]
	mov ebx,0
	mov esi,2
e1:
		xor edx,edx
		div esi
		add ebx,edx
	cmp eax,0
	jnz e1
	
	mov eax,[esp+8]
	mov ecx,0
e2:
		xor edx,edx
		div esi
		add ecx,edx
	cmp eax,0
	jnz e2
	
	cmp ebx,ecx
	jnle e3
	jmp endprg
e3:
	mov eax,0
	mov [esp+12],eax
endprg:

	ret
	_cmp_asm endp
end