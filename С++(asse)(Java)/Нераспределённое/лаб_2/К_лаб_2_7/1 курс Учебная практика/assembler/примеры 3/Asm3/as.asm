.486
.model flat
;.data
; d10 dw 10
;.stack 20h
.code
Public _SubInt
_SubInt proc
        push ebp
        mov ebp,esp
             mov esi, [ebp+16];&k1 
        mov edi, [ebp+20];&k2
        mov eax,[ebp+8] ;x
        add eax,[ebp+12];y 
	    mov [esi],eax
	    mov eax,[ebp+8] ;x
        mov ebx,[ebp+12];y 
        mul ebx
		mov [edi],eax
		mov eax,[ebp+8] ;x
        sub eax,[ebp+12];y 
	    pop ebp
        ret 
_SubInt endp
Public _SumAInt
_SumAInt proc
        push ebp
        mov ebp,esp
        mov esi,[ebp+8] ;&array 
        mov ecx,[ebp+12];n
        xor eax,eax
 for1:   add eax,[esi]
        add esi,4
        loop for1
	    mov edi,[ebp+16];&k
	    mov [edi],eax
	    pop ebp
        ret 
_SumAInt endp
         end