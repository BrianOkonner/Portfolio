.486
.model flat
.data
a dd ?
n dd ?
.code
Public _Step
_Step proc
     push ebp
        mov ebp,esp
          mov eax,[ebp+8]
		mov ecx,[ebp+12]
		dec ecx
		mov a,eax
for1:   imul a
		loop for1
		pop ebp
		ret
		_Step endp
         end