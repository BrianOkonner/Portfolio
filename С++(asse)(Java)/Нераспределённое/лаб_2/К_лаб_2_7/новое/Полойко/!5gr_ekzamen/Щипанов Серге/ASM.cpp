void bsort(int *a,int n)
{
	_asm{
	xor eax,eax
	xor ebx,ebx
	xor edx,edx

	mov ecx,n
m1:
	push ecx
		mov ecx,n
		dec ecx
		mov esi,a
m2:
	mov eax,[esi]
	mov ebx,[esi+1]
	cmp eax,ebx
		jb m3
	mov [esi+1],eax
	mov [esi],ebx
m3:
	add esi,4
		loop m2
		pop ecx
		loop m1
}
}

