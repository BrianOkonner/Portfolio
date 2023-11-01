.386
.model flat
.code
Public _count_ones_asm
	_count_ones_asm proc

	mov eax,[esp+4]
	xor ebx,ebx
	mov ecx,2
m1:
	xor edx,edx
	div ecx
	cmp edx,0
	je m2
	inc ebx
m2:
	cmp eax,0
	jg m1
	mov eax,ebx		
	ret
	_count_ones_asm endp
end