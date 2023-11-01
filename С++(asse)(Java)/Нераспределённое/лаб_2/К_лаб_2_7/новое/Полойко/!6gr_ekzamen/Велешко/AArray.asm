.486
.MODEL FLAT

.CODE

PUBLIC gen_next
gen_next PROC C \
		USES ESI EDI EBX EDX ECX \
		val:DWORD

		MOV EBX,[val]
		XOR EDI,EDI
		MOV ESI,10
cycle:
		TEST EBX,EBX
		JZ break
		
		MOV EAX,EBX
		XOR EDX,EDX
		DIV ESI
		
		MOV EBX,EAX
		MOV EAX,EDX
		MOV ECX,EAX
		MUL ECX
		MUL ECX
		ADD EDI,EAX
		JMP cycle
		
break:
		MOV EAX,EDI
		RET
gen_next ENDP

END