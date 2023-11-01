.586P
.MODEL FLAT, C
PUBLIC PER
_TEXT SEGMENT
PER PROC C, ARR1:DWORD,ARR2:DWORD,Result:DWORD,len1:DWORD,len2:DWORD,level:DWORD
	.data
	count dword 0
	.code
		mov eax,len1
		add eax,len2
		mov len1,eax


		xor eax,eax
		xor esi, esi
		xor edi, edi
		xor ecx, ecx
		mov ebx, ARR1
		mov edx, ARR2
		mov esi, Result
		add ecx, len1

again:	
		mov eax,[ebx]
		inc level
		cmp eax,[edx]

		je point1
		jl point2
		jg point3

point1: 
		add ebx,4
		add edx,4
		mov [esi],eax
		add esi,4
		sub ecx,2
		inc count
		cmp ecx,0

		je finish
		jmp again

point2: 
		add ebx,4
		dec ecx
		cmp ecx,0

		je finish
		jmp again

point3: 
		add edx,4
		dec ecx
		cmp ecx,0

		je finish
		jmp again
finish:		
		mov eax,count
LEAVE
RET
PER ENDP
_TEXT ENDS
END