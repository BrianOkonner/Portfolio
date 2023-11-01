.386
.model flat
.code

public Addints
addints proc 
		uses esi edi ebx edx ecx \
		val:dword

		mov ebx,[val]
		xor edi,edi
		mov esi,10
cycle:
		test ebx,eax
		jz break
		
break:
		mov eax,edi
		ret
addints endp
end 