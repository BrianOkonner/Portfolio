.486                 
 .model flat,stdcall
 .data
 buf dd ?
 len2 dd ? 
 len dd ?

  
.code


LibMain proc 

   mov eax,1
   ret

LibMain Endp

	
sort proc 


	pop eax
	pop edi
	pop ecx
	mov len,ecx

	push eax
	sub esp,8

	xor ecx,ecx
	dec len
for1:
	mov ebx,len
	sub ebx,ecx
	xor edx,edx

	for2:
		
		mov eax,[edi+edx*4]
		cmp eax,[edi+edx*4+4]
		jle endif1
		mov eax,[edi+edx*4]
		mov buf,eax
		
		mov eax, [edi+edx*4+4]
		mov [edi+edx*4],eax
		mov eax,buf
		mov [edi+edx*4+4],eax

endif1:

		inc edx
		cmp edx,ebx
		jl for2
		


	inc ecx
	cmp ecx,len
	jl for1

	


ret  
sort Endp 


decToByn proc 


	pop ecx
	pop eax
	pop edi
	mov len,ecx

	push ecx
	sub esp,8


while1:
	
	xor edx,edx
	mov ebx,2
	div ebx
	
	mov [edi],edx

	add edi,4
	
	cmp eax,0
	jne while1
	
	xor eax,eax
	dec eax
	mov [edi],eax
ret  
decToByn Endp 


end LibMain
