COMMENT*
���������:
	- �������������� ������ �������� � �����:
		Cnv_Str_Num
	- �������������� ����a � ������ ��������:	
		Cnv_Num_Str
� ��������� ������� ���������:	2h,8h,0a,10h
*
.286
.model small
.stack 100h
.data			;����� ���� � ����������� �� ������� ���������
			;(��� ����������� �����)
Field_Length	db	0,0,16,5 dup (0),6,0,5,5 dup(0),5
Digits		db	'0123456789ABCDEFabcdef'

.code
public Cnv_Str_Num, Cnv_Num_Str

COMMENT*
-------------------------  Cnv_Str_Num --------------------
INFO  : �������������� ������ �������� � ����� � ��������� �������
	���������. ����������� (0..65535), �������� (-32768..32767)
INPUT : ������������������ ���������� ���������� � �����:
	-�������,
	-�������� ������,
	-��� ����� (�������� =0 /����������� =1):BYTE
	-������� ��������� (2,8,10,16):BYTE
		����.:000Ah - �����������, 10 �\�
		      0110h - �������� 16 �\�
		      0002h - ����������� 2 �\�	
	������ � ������� ��� (0Ah) 21h	
OUTPUT: ����: ��������� ���������
		CF = 0 - ����� (WORD)
		CF = 1 - ��� ������
	 ��� ������:
	 	1 - ������������ ������
	 	2 - ������� ������� �����
SAVE  :	ALL
*

Cnv_Str_Num	proc	far
	pusha
	mov	bp,sp
	add	bp,20			;����� �� ���������� ��������� + ����� ��������
	mov	ds,word ptr[bp+4]
	mov	si,word ptr[bp+2]
	call	Check_Format		;�������� ������������ ������
	jc	Format_Error		;
	
	xor	ax,ax
	xor	bx,bx
	xor	di,di			;�������� �� ��������� �����
	mov	bl,byte ptr [bp]	;�\�
	mov	cs:Basis,bx
C_S_U_Loop:
	mul	cs:Basis
	adc	di,0
	add	di,dx
	mov	bl,byte ptr [si]
	cmp	bl,'a'
	jb	C_S_Upper_Case
	and	bl,11011111b		;��������� ��������
C_S_Upper_Case:	
	cmp	bl,'A'
	jb	C_S_Not_Hex
	sub	bl,55			;��������� ��� ��������. �����
	jmp short C_S_Hex_Done
C_S_Not_Hex:	
	and	bl,0fh
C_S_Hex_Done:	
	add	ax,bx
	adc	di,0
	inc	si
	loop	C_S_U_Loop
	cmp	di,0
	jne	Big_Number
	call	Check_Sign		;��������� ����� � �������� �������� (�
					;������ ��������� �����)
	jc	Big_Number			
	mov	word ptr [bp+4],ax	;��������� ���������
	popa
	clc				;��� ������
	ret	4
Format_Error:
	mov	word ptr [bp+4],1	;�������� ������
	popa
	stc
	ret	4
Big_Number:
	mov	word ptr [bp+4],2	;������� ������� �����
	popa
	stc
	ret	4			;����� ���������
	
;- - - SUBR- - - Check_Format - - - - - - - -
;INFO  : �������� ������������ ������� ������
;INPUT : DS,SI - ������� � �������� ������,
;	 BP   - ������� ��������� :(BYTE)
;	 BP+1 - ��� ����� (�������� = 1/ ����������� = 0):(BYTE)
;OUTOUT: CF = 0 - OK, CF = 1 - ������
;	 SI - �������� �����
;	 CX - ���������� ���� � �����
;SAVE  : ALL

Check_Format	proc
	push	ax bx dx bp es ds di ;[si cx] - ����� ��������� �����
	xor	cx,cx
	mov	cl,byte ptr [si+1]	;����� ������
	cmp	byte ptr [bp+1],1
	jne	C_F_Check_Plus
	cmp	byte ptr[si+2],'-'
	jne	C_F_Check_Plus
	inc	si
	dec	cx
C_F_Check_Plus:	
	cmp	byte ptr[si+2],'+'
	jne	C_F_Unsigned
	inc	si
	dec	cx
	
C_F_Unsigned:
	mov	ax,seg Digits		;������ ���������
	mov	es,ax
	lea	di,Digits
	add	si,2
	push	si cx			;��������� �������� ����� + ���-�� ����
	xor	bx,bx
	mov	bl,byte ptr [bp]	;c\c
	cmp	bl,8			;��������� ��� 8 �\�
	jne	Not_8
	inc	bx
	jmp short C_F_Scan_Loop
Not_8:	
	cmp	bl,16			;��������� ��� 16 �\�
	jne	Not_16
	add	bx,6
Not_16:	
	cld
C_F_Scan_Loop:
	push	cx
	lodsb
	mov	cx,bx
	push	di
	xor	dx,dx			;�������
	repne	scasb			;������� ������ � ��������
	pop	di
	pop	cx
	jnz	C_F_Error
	loop	C_F_Scan_Loop
	pop	cx si di ds es bp dx bx ax
	clc
	ret
	
C_F_Error:
	pop	cx si di ds es bp dx bx ax
	stc
	ret
Check_Format	endp

;- - - SUBR- - - Check_Sign - - - - - - - -
;INFO  : ��������� ����� ����� � ����������� ���������
;INPUT : AX - �����
;	 SI+2 - ���� �����
;OUTOUT: CF = 0 - OK, CF = 1 - ������

Check_Sign	proc
	mov	si,word ptr [bp+2]	;�������� ������
	cmp	byte ptr [bp+1],1	;�������� ���� ����� (����./�����.)
	jne	C_S_Unsigned
	cmp	byte ptr [si+2],'-'
	jne	C_S_Positive
	cmp	ax,32768
	ja	C_S_Error
	neg	ax
	clc
	ret
C_S_Positive:	
	cmp	ax,32767
	ja	C_S_Error
C_S_Unsigned:	
	clc
	ret
C_S_Error:
	stc
	ret	
Check_Sign	endp

Basis	dw	0			;��������� ������� ���������
Cnv_Str_Num	endp	

;########################################################################



COMMENT*
-------------------------  Cnv_Num_Str --------------------
INFO  : �������������� ����� � ������ ��������  � ��������� �������
	���������. ����������� (0..65535), �������� (-32768..32767)
INPUT : ������������������ ���������� ���������� � �����:
	-����� (WORD)
	-��� ����� (�������� =0 /����������� =1):BYTE
	-������� ��������� (2,8,10,16):BYTE
		����.:000Ah - �����������, 10 �\�
		      0110h - �������� 16 �\�
		      0002h - ����������� 2 �\�	
	-�������,
	-�������� ������
	��� 2 �\� ����� ���� 17
OUTPUT: ����: ��������� ���������
SAVE  :	ALL
*
Cnv_Num_Str	proc	far
	pusha
	mov	ax,seg Field_Length	;����� ���� ��� �\�
	mov	ds,ax
	mov	bp,sp
	add	bp,20			;�������� �� 8 ��������� + ����� ��������
	mov	ax,word ptr[bp+4]	;��� �����
	mov	byte ptr cs:NBasis,al	;��������� �\�
	lea	bx,Field_Length		;������� ���� �����
	xlat
	add	al,ah			;������������ ���� (���� ����� ��������
					;+1 ��� �����)
	mov	di,word ptr [bp]	;�������� ������
	xor	ah,ah
	mov	cx,ax			;���������� ���������
	add	di,ax			;�������� �� ����� ���� ������
	dec	di
	mov	ax,word ptr [bp+2]
	mov	es,ax			;������� ������
	mov	ax,word ptr [bp+6]	;�������������� �����
	call	Correct_Value		;������������� ��������
	lea	bx,Digits
	std				;����� ������ ������
C_N_Translate_Loop:
	xor	dx,dx
	div	NBasis
	xchg	ax,dx
	xlat				;�������� ������ ���������������
					;����� �� �������
	stosb				
	xchg	ax,dx
	loop	C_N_Translate_Loop
	call	Set_Sign		;������� ���������� ���� � ������ ����
	popa
	ret	8			;����� ���������
	
;- - - SUBR- - - Correct_Value - - - - - - - -
;INFO  : ������ ������ ����� � �������� ������
;INPUT : AX - �����
;	 BP+7 - ��� ����� (0-�����./1-����.)
;OUTOUT: AX - ������ �����
;	 ���� ����� <0 ���������� � ������ ����� ����, ������������ ���
;	 �����, 1

Correct_Value	proc
	cmp	byte ptr [bp+5],1
	jne	C_V_Unsigned
	cmp	ax,0
	jge	C_V_Unsigned
	neg	ax
	or	byte ptr [bp+5],10h	;=1 - ����� <0
C_V_Unsigned:	
	ret
Correct_Value	endp
	
;- - - SUBR- - - Set_Sign - - - - - - - -
;INFO  : �������� ���������� ����� � ��������� �����
;INPUT : BP+4 - ������� ������ (����� � ��������� ����)
;	 BP+2 - �������� ������
;OUTOUT:

Set_Sign	proc
	mov	ax,word ptr [bp+2]	;������� ������
	mov	es,ax
	mov	di,word ptr [bp]	;�������� ������
	mov	si,di
	mov	al,30h			;�������� ������ ������ ��������
	mov	cx,20			;�����
	cld
	repe	scasb
	xor	cx,cx
	cmp	byte ptr es:[di-1],'A'	;��� ����� 16 �\� ������ 0 �����
	jb	S_S_Not_16		;A-F
	dec	di			;
S_S_Not_16:	
	cmp	byte ptr [bp+5],11h	;11h - �������� ������������� �����
	jne	S_S_Positive
	dec	di			;���������� �� ������� �����
	dec	di
	mov	byte ptr es:[di],'-'	;������ ����
	inc	cx			;������������ ���������� 0 (������� �� DI)
S_S_Positive:
	add	cx,di			;��������� ���-�� �����
	sub	cx,si
	dec	cx
	add	si,cx			;����� �����
	dec	si			;������� ������� ���� ������
	mov	di,si
	cmp	word ptr [bp+6],0	;����� = 0 ? �� - ��������� ���� 0
	jne	S_S_Del_0
	dec	di
S_S_Del_0:	
	std				;�������� ���� ��������� ������ ������
	mov	al,' '
	rep	stosb			
	ret
Set_Sign	endp

NBasis	dw	0			;��������� ������� ���������	
Cnv_Num_Str	endp
;##########################################################################
	end