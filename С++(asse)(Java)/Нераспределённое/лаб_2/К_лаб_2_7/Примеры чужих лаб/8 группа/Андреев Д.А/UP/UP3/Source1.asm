.586
.MODEL FLAT, C
.CODE
MAS_FUNC PROC C a:dword, k:dword, n:dword, b:dword

       mov ecx,n	;���������� ������
       mov esi,a	;������ � (����)
	   mov edi,k	;������ k (�����)
	   ;=====���� <= ��������� � �����������=========
point1: 
       mov eax,[esi]	
	   cmp eax,b
       jg point2
       mov [edi],eax
	   add edi,4
point2:     
       add esi,4
       loop point1

	;===================================================

	;===============����, ��������� �������=============

       mov ecx,n	; ����������
       mov esi,a
point3: 
       mov eax,[esi]
	   cmp eax,b
       jle point4
       mov [edi],eax
	   add edi,4
point4:     
       add esi,4
       loop point3

       mov eax,k   
	   
	   ;�����
ret
MAS_FUNC ENDP
END
