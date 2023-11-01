.386
.model flat
.code
Public _get_number_of_digits_asm
	_get_number_of_digits_asm proc

	mov eax,[esp+4]
	mov ebx,2
	mov ecx,0
	mov edx,0
LS:	cmp eax,0
	je E
	div ebx
	cmp edx,0
	je CN
	inc ecx
	mov edx,0
CN:	jmp LS
E:	mov eax,ecx
	ret
	_get_number_of_digits_asm endp
end