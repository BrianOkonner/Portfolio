.586
.MODEL FLAT, C
.CODE
MAS_FUNC PROC C a:dword, a1:dword, n:dword, b:dword
      mov ecx,n	
       mov esi,a
	   mov edi,a1
nach1: 
       mov eax,[esi]
	   cmp eax,b
       jge next1
       mov [edi],eax
	   add edi,4
next1:     
       add esi,4
       loop nach1


       mov ecx,n	
       mov esi,a
nach2: 
       mov eax,[esi]
	   cmp eax,b
       jne next2
       mov [edi],eax
	   add edi,4
next2:     
       add esi,4
       loop nach2




       mov ecx,n	
       mov esi,a
nach3: 
       mov eax,[esi]
	   cmp eax,b
       jle next3
       mov [edi],eax
	   add edi,4
next3:     
       add esi,4
       loop nach3

       mov eax,a1       
ret
MAS_FUNC ENDP
END
