.386
.model flat
.code
Public _vsprost
	_vsprost proc
		mov eax,[esp+4]
		mov	ebx,[esp+8]
		mov edi,1
cycl:
		test eax,1
		jz even1
r1:
		test ebx,1
		jz even2
		cmp eax,ebx
		jl leatest
		jg greatest
		jmp _equal
even1:
		shr eax,1
		test ebx,1
		jz evenboth
		jmp cycl
evenboth:
		shr ebx,1
		shl edi,1
		jmp cycl
even2: 
		shr ebx,1
		jmp cycl

leatest:
		sub ebx,eax 
		jmp r1
greatest:
		sub eax,ebx
		jmp cycl
_equal:
		imul edi,eax
		
	xor ebx,ebx
	inc ebx
	cmp edi,ebx
	je endyes
	jmp endno
	
endyes:
	xor eax,eax
	inc eax
	ret
endno:
	xor eax,eax
	ret
	_vsprost endp
end