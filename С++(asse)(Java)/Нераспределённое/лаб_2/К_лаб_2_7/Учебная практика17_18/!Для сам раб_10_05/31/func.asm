


.386 
PUBLIC _PR1
.model flat 
.code 
_PR1        proc

			xor eax,eax
		
			xor ebx,ebx 
            mov   eax,dword ptr [esp+8]      ;первый параметр 
            mov   ebx, dword ptr [esp+4]       ;второй параметр 
            cdq 
            mul ecx 
           ; mov   eax,edx 
            ret 
_PR1       endp 
end 		